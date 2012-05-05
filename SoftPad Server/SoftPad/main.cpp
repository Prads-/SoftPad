/*
	Written By Pradipna Nepal
	www.pradsprojects.com

	Copyright (C) 2012 Pradipna Nepal
	Please read COPYING.txt included along with this source code for more detail.
	If not included, see http://www.gnu.org/licenses/
*/

#include <WinSock2.h>
#include <Windows.h>
#include <process.h>
#include <sstream>
#include "resources.h"
using namespace std;

//GUI Theme
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' \"\"version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

const char *WND_CN = "SoftPadCN";

//From libManageConnection.cpp
extern int port;
extern void socketConnect(void *args);
extern void cleanUpSockets();
extern void openPortFile();
extern bool savePortFile();

HWND mHwnd;	//Main Window Handle
HFONT headerFont, controlsFont;

void createControls(HWND hwnd);
void writeLog(const char *msg);
void updatePort();

LRESULT CALLBACK WndProc(HWND hwnd, UINT msG, WPARAM wParam, LPARAM lParam) {
	switch (msG) {
		case WM_CREATE:
			createControls(hwnd);
			break;
		case WM_COMMAND:
			switch (LOWORD(wParam)) {
				case IDC_BTN_PORT:
					updatePort();
			}
			break;
		case WM_CLOSE:
			savePortFile();
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msG, wParam, lParam);
	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	WNDCLASSEX wC = {0};

	wC.cbSize = sizeof(WNDCLASSEX);
	wC.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
	wC.hCursor = LoadCursor(NULL, IDC_ARROW);
	wC.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_MAIN_ICON));
	wC.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MAIN_ICON), IMAGE_ICON,16, 16, 0); 
	wC.hInstance = hInstance;
	wC.lpfnWndProc = WndProc;
	wC.lpszClassName = WND_CN;

	if (!RegisterClassEx(&wC)) {
		MessageBox(NULL, "Could not register Window Class", "Error", MB_ICONERROR);
		return 0;
	}

	mHwnd = CreateWindowEx(WS_EX_CLIENTEDGE, WND_CN, "SoftPad Server v0.1", WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 
		100, 100, 355, 327, NULL, NULL, hInstance, NULL);

	if (mHwnd == NULL) {
		MessageBox(NULL, "Could not create Window", "Error", MB_ICONERROR);
		return 0;
	}

	ShowWindow(mHwnd, nShowCmd);
	UpdateWindow(mHwnd);

	openPortFile();		//Get port number from 'port.dat'
	
	//Put port number in text box
	stringstream ss;
	ss << port;
	SetDlgItemText(mHwnd, IDC_TXT_PORT, ss.str().c_str());

	_beginthread(socketConnect, 0, 0);
	
	MSG Msg;
	while(GetMessage(&Msg, NULL, NULL, NULL) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	DeleteObject(headerFont);
	DeleteObject(controlsFont);
	cleanUpSockets();
	return 0;
}

void createControls(HWND hwnd) {
	CreateWindow("STATIC", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 10, 10, 114, 114, hwnd, (HMENU)IDC_ST_APPBANNER, 
		GetModuleHandle(NULL), NULL);
	HBITMAP appBanner = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(BITMAP_ST_APPBANNER), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE);
	SendDlgItemMessage(hwnd, IDC_ST_APPBANNER, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)appBanner);
	DeleteObject(appBanner);

	CreateWindow("STATIC", "SoftPad Server v0.1\r\nwww.pradsprojects.com", WS_VISIBLE | WS_CHILD | SS_RIGHT, 120, 70, 210, 50, hwnd, 
		(HMENU)IDC_ST_APPNAME, GetModuleHandle(NULL), NULL);

	headerFont = CreateFont(0, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, OUT_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, DEFAULT_PITCH, "Courier New");
	SendDlgItemMessage(hwnd, IDC_ST_APPNAME, WM_SETFONT, (WPARAM)headerFont, TRUE);

	controlsFont = CreateFont(13, 6, 0, 0, FW_MEDIUM, FALSE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS,	OUT_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, DEFAULT_PITCH, "Verdana");

	CreateWindow("LISTBOX", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | WS_HSCROLL, 100, 130, 230, 100, hwnd, (HMENU)IDC_LB_LOG,
		GetModuleHandle(NULL), NULL);
	SendDlgItemMessage(hwnd, IDC_LB_LOG, LB_SETHORIZONTALEXTENT, 500, 0);
	SendDlgItemMessage(hwnd, IDC_LB_LOG, WM_SETFONT, (WPARAM)controlsFont, TRUE);
	
	CreateWindow("BUTTON", "Port Number", WS_VISIBLE | WS_CHILD | BS_GROUPBOX, 100, 231, 230, 53, hwnd, (HMENU)IDC_GB_PORT,
		GetModuleHandle(NULL), NULL);
	SendDlgItemMessage(hwnd, IDC_GB_PORT, WM_SETFONT, (WPARAM)controlsFont, TRUE);

	CreateWindow("STATIC", "Port No.", WS_VISIBLE | WS_CHILD, 110, 255, 50, 20, hwnd, (HMENU)IDC_ST_PORT,
		GetModuleHandle(NULL), NULL);
	SendDlgItemMessage(hwnd, IDC_ST_PORT, WM_SETFONT, (WPARAM)controlsFont, TRUE);

	CreateWindow("EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 170, 252, 60, 20, hwnd, (HMENU)IDC_TXT_PORT,
		GetModuleHandle(NULL), NULL);
	SendDlgItemMessage(hwnd, IDC_TXT_PORT, WM_SETFONT, (WPARAM)controlsFont, TRUE);
	
	CreateWindow("BUTTON", "Edit", WS_VISIBLE | WS_CHILD, 237, 251, 60, 23, hwnd, (HMENU)IDC_BTN_PORT,
		GetModuleHandle(NULL), NULL);
	SendDlgItemMessage(hwnd, IDC_BTN_PORT, WM_SETFONT, (WPARAM)controlsFont, TRUE);
}

void writeLog(const char *msg) {
	SendDlgItemMessage(mHwnd, IDC_LB_LOG, LB_ADDSTRING, 0, (LPARAM)msg);

	//We won't display more than 5 logs at once. If there are more than 5, pop from the top
	int listSize = SendDlgItemMessage(mHwnd, IDC_LB_LOG, LB_GETCOUNT, 0, 0);
	while (listSize >= 5) {
		SendDlgItemMessage(mHwnd, IDC_LB_LOG, LB_DELETESTRING, 0, 0);
		--listSize;
	}
}

void updatePort() {
	char *buffer = 0;
	int size = GetWindowTextLength(GetDlgItem(mHwnd, IDC_TXT_PORT));
	
	buffer = new char[size + 1];
	GetDlgItemText(mHwnd, IDC_TXT_PORT, buffer, size + 1);
	port = atoi(buffer);
	delete [] buffer;

	if (MessageBox(mHwnd, "SoftPad Server needs to restart for change to take effect. Do you want to restart SoftPad now?", 
		"SoftPad Restart", MB_YESNO | MB_ICONQUESTION) == IDYES) {
			savePortFile();
			ShellExecute(NULL, "open", "SoftPad.exe", NULL, NULL, SW_SHOW);
			PostQuitMessage(0);
	}
}