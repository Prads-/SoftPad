/*
	Written By Pradipna Nepal
	www.pradsprojects.com

	Copyright (C) 2012 Pradipna Nepal
	Please read COPYING.txt included along with this source code for more detail.
	If not included, see http://www.gnu.org/licenses/
*/

#include "libSoftTouch.h"

#define SCREEN_PACKET_SIZE				(viewWidth * viewHeight * 2)		//In bytes
#define SCREEN_CAPTURE_SIZE				(viewWidth * viewHeight)			//In DWORD

unsigned char *screenPacket = 0;
DWORD *screenCapture = 0;
int vOffset = 0, hOffset = 0, sWidth = GetSystemMetrics(SM_CXSCREEN), sHeight = GetSystemMetrics(SM_CYSCREEN);
char appType = 'P';
int viewWidth = 273, viewHeight = 460;

void processInput(bool release);
void sendScreen();

void SoftTouch::softTouchThread(void *arg) {
	while (!terminateSoftTouchThread) {
		if (recv(clientSocket, (char*)code, PACKET_SIZE, MSG_WAITALL) == 0) {
			writeLog("Disconnected...");
			cleanUpSockets();
			_beginthread(socketConnect, 0, 0);
			break;
		}
		if (!checkIndexCode()) {
			switch (code[1]) {
				case CODE_SEND_SCREEN:
					sendScreen();
					break;
				case CODE_TOUCH_INPUT:
					processInput(true);
					break;
				case CODE_INCREMENT_OFFSET_V:
					if (sHeight > vOffset + viewHeight) vOffset += code[2] | (code[3] << 8);
					break;
				case CODE_INCREMENT_OFFSET_H:
					if (sWidth > hOffset + viewWidth) hOffset +=  code[2] | (code[3] << 8);
					break;
				case CODE_DECREMENT_OFFSET_V:
					vOffset -= code[2] | (code[3] << 8);
					if (vOffset < 0) vOffset = 0;
					break;
				case CODE_DECREMENT_OFFSET_H:
					hOffset -= code[2] | (code[3] << 8);
					if (hOffset < 0) hOffset = 0;
					break;
				case CODE_LONG_PRESS:
					processInput(false);
					break;
				case CODE_LONG_RELEASED:
					input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
					SendInput(1, &input, sizeof(INPUT));
			}
		}
	}
}

void SoftTouch::allocMemSoftTouch(int width, int height) {
	if (screenPacket != 0 || screenCapture != 0) freeMemSoftTouch();

	viewWidth = width;
	viewHeight = height;
	screenPacket = new unsigned char[SCREEN_PACKET_SIZE];
	screenCapture = new DWORD[SCREEN_CAPTURE_SIZE];
}

void SoftTouch::freeMemSoftTouch() {
	delete [] screenPacket;
	delete [] screenCapture;

	screenPacket = 0;
	screenCapture = 0;
}

//Processes touch input
void processInput(bool release) {
	static unsigned int currentTime = timeGetTime(), previousTime = 0;
	int x, y;

	x = code[2] | (code[3] << 8);
	y = code[4] | (code[5] << 8);

	input.mi.dx = ((x - 47 + hOffset) * 65535 / sWidth);
	if (appType == 'P')	//If client app is a paid app
		input.mi.dy = ((y + vOffset) * 65535 / sHeight);
	else
		input.mi.dy = ((y - 50 + vOffset) * 65535 / sHeight);

	currentTime = timeGetTime();
	if (currentTime - previousTime > 500) {
		input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
		SendInput(1, &input, sizeof(INPUT));
	}
	previousTime = currentTime;

	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));
	if (release) {
		input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		SendInput(1, &input, sizeof(INPUT));
	}
}

//Captures screenshot and sends it to the client
void sendScreen() {
	static unsigned int currentTime = timeGetTime(), previousTime = 0;

	currentTime = timeGetTime();
	while (currentTime - previousTime < 70) {
		Sleep(1);
		currentTime = timeGetTime();
	}

	previousTime = currentTime;

	HWND hDesktop = GetDesktopWindow();
	HDC hdcDesktop = GetDC(hDesktop);
	HDC hdcComptDesktop = CreateCompatibleDC(hdcDesktop);
	HBITMAP hBitmapCompt = CreateCompatibleBitmap(hdcDesktop, viewWidth, viewHeight);

	SelectObject(hdcComptDesktop, hBitmapCompt);
	BitBlt(hdcComptDesktop, 0, 0, viewWidth, viewHeight, hdcDesktop, hOffset, vOffset, SRCCOPY);

	BITMAPINFO bitInfo = {0};
	bitInfo.bmiHeader.biBitCount = 32;
	bitInfo.bmiHeader.biCompression = BI_RGB;
	bitInfo.bmiHeader.biHeight = viewHeight;
	bitInfo.bmiHeader.biPlanes = 1;
	bitInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitInfo.bmiHeader.biWidth = viewWidth;

	GetDIBits(hdcComptDesktop, hBitmapCompt, 0, viewHeight, (void*)screenCapture, &bitInfo, DIB_RGB_COLORS);
	
	ReleaseDC(hDesktop, hdcDesktop);
	DeleteObject(hdcComptDesktop);
	DeleteObject(hBitmapCompt);

	int packetCounter = 0;
	for (int y = viewHeight - 1; y >= 0; --y) {
		for (int x = 0; x < viewWidth; ++x) {
			screenPacket[packetCounter] = (screenCapture[x + y * viewWidth] & 0xF00000) >> 16;
			screenPacket[packetCounter++] |= (screenCapture[x + y * viewWidth] & 0xF000) >> 12;
			screenPacket[packetCounter++] = screenCapture[x + y * viewWidth] & 0xF0;
		}
	}
	send(clientSocket, (char*)screenPacket, SCREEN_PACKET_SIZE, 0);	
}