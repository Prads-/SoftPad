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
#include <fstream>
#include "libKeyboard.h"
#include "libMouse.h"
#include "libSoftTouch.h"
#include "definitions.h"
#include "resources.h"
using namespace std;
using namespace Keyboard;
using namespace Mouse;
using namespace SoftTouch;

#pragma comment (lib, "Ws2_32.lib")

SOCKET clientSocket;
unsigned char code[PACKET_SIZE] = {0};
INPUT input = {0};
bool terminateIndexThread, terminateMouseThread, terminateKeyboardThread, terminateSoftTouchThread;
int port;

void socketConnect(void *arg);
void indexThread(void *arg);
void threadsSwitch(bool iT, bool mT, bool kT, bool sT);
bool checkIndexCode();
void codeIndex();
void codeTrackPad();
void codeKeyBoard();
void codeSoftTouch();
void openPortFile();
bool savePortFile();
void cleanUpSockets();

void socketConnect(void *args) {
	writeLog("Initializing...");
	SOCKET servSocket;

	//Winsock initialization
	WSADATA wSInfo = {0};
	if (WSAStartup(2, &wSInfo) == 0) {
		servSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (servSocket == INVALID_SOCKET) goto error;
		
		sockaddr_in sockAddr;
		sockAddr.sin_addr.s_addr = INADDR_ANY;
		sockAddr.sin_family = AF_INET;
		sockAddr.sin_port = htons(port);
		
		if (bind(servSocket, (sockaddr*)&sockAddr, sizeof(sockAddr)) != 0) goto error;
		
		if (listen(servSocket, 1) != 0) goto error;
		
		writeLog("Waiting for client to connect...");
		clientSocket = accept(servSocket, NULL, NULL);
		if (clientSocket == INVALID_SOCKET) goto error;
		
		threadsSwitch(true, false, false, false);
		if (_beginthread(indexThread, 0, 0) == -1) goto error;

		writeLog("Connected...");
	} else {
error:
		writeLog("FAILED");
	}

	closesocket(servSocket);
}

void indexThread(void *arg) {
	while (!terminateIndexThread) {
		if (recv(clientSocket, (char*)code, PACKET_SIZE, MSG_WAITALL) == 0) { 
			writeLog("Disconnected...");
			cleanUpSockets();
			_beginthread(socketConnect, 0, 0);
			break;
		}
 		checkIndexCode();
	}
}

void threadsSwitch(bool iT, bool mT, bool kT, bool sT) {
	terminateIndexThread = !iT;
	terminateMouseThread = !mT;
	terminateKeyboardThread = !kT;
	terminateSoftTouchThread = !sT;
}

bool checkIndexCode() {
	switch (code[0]) {
		case CODE_INDEX:
			if (!terminateIndexThread) break;	//Index thread is already running
			codeIndex();
			return true;
		case CODE_TRACKPAD:
			if (!terminateMouseThread) break;	//TrackPad thread is already running
			codeTrackPad();
			return true;
		case CODE_KEYBOARD:
			if (!terminateKeyboardThread) break;	//Keyboard thread is already running
			codeKeyBoard();
			return true;
		case CODE_SOFTTOUCH:
			if (!terminateSoftTouchThread) break;	//SoftTouch thread is already running
			codeSoftTouch();
			return true;
	}
	return false;
}

void codeIndex() {
	threadsSwitch(true, false, false, false);
	while (_beginthread(indexThread, 0, 0) == -1) {
		writeLog("Couldn't create Index thread, trying again after 5 secs...");
		Sleep(5000);
	}
}

void codeTrackPad() {
	input.type = INPUT_MOUSE;
	writeLog("Creating threads for recieving TrackPad input...");
	threadsSwitch(false, true, false, false);
	while (_beginthread(mouseThread1, 0, 0) == -1) {
		writeLog("Couldn't create Mouse thread 1, trying again after 5 secs...");
		Sleep(5000);
	}
	while (_beginthread(mouseThread2, 0, 0) == -1) {
		writeLog("Couldn't create Mouse thread 2, trying again after 5 secs...");
		Sleep(5000);
	}
	writeLog("OK");
}

void codeKeyBoard() {
	input.type = INPUT_KEYBOARD;
	writeLog("Creating thread for recieving KeyBoard input...");
	threadsSwitch(false, false, true, false);
	while (_beginthread(keyboardThread, 0, 0) == -1) {
		writeLog("Couldn't create Keyboard thread, trying again after 5 secs...");
		Sleep(5000);
	}
	writeLog("OK");
}

void codeSoftTouch() {
	input.type = INPUT_MOUSE;
	writeLog("Creating thread for recieving Touch Screen input...");
	threadsSwitch(false, false, false, true);
	while (_beginthread(softTouchThread, 0, 0) == -1) {
		writeLog("Couldn't create SoftTouch thread, trying again after 5 secs...");
		Sleep(5000);
	}
	writeLog("OK");
}

void openPortFile() {
	ifstream portFile;
	
	portFile.open("port.dat", ios::binary);
	if (portFile.is_open()) {
		portFile.read((char*)&port, 4);
		portFile.close();
	} else {
		port = 13248;
	}
}

bool savePortFile() {
	ofstream portFile;

	portFile.open("port.dat", ios::binary);
	if (portFile.is_open()) {
		portFile.write((char*)&port, 4);
		portFile.close();
		return true;
	}

	return false;
}

void cleanUpSockets() {
	threadsSwitch(false, false, false, false);
	closesocket(clientSocket);
	WSACleanup();
}