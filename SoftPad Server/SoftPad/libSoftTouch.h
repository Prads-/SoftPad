/*
	Written By Pradipna Nepal
	www.pradsprojects.com

	Copyright (C) 2012 Pradipna Nepal
	Please read COPYING.txt included along with this source code for more detail.
	If not included, see http://www.gnu.org/licenses/
*/

#ifndef LIBSOFTTOUCH_H
#define LIBSOFTTOUCH_H

#include <WinSock2.h>
#include <Windows.h>
#include <process.h>
#include "definitions.h"

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Winmm.lib")

#define VIEW_WIDTH						273
#define VIEW_HEIGHT						410
#define SCREEN_PACKET_SIZE				(VIEW_WIDTH * VIEW_HEIGHT * 2)		//In bytes
#define SCREEN_CAPTURE_SIZE				(VIEW_WIDTH * VIEW_HEIGHT)			//In DWORD

//From libManageConnections.cpp
extern SOCKET clientSocket;
extern bool terminateSoftTouchThread;
extern unsigned char code[PACKET_SIZE];
extern INPUT input;
extern void threadsSwitch(bool iT, bool mT, bool kT, bool sT);
extern bool checkIndexCode();
extern void socketConnect(void *args);
extern void cleanUpSockets();

//From main.cpp
extern void writeLog(const char *msg);

namespace SoftTouch {
	void softTouchThread(void *arg);
}

#endif