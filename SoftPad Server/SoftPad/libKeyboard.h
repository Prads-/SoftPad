/*
	Written By Pradipna Nepal
	www.pradsprojects.com

	Copyright (C) 2012 Pradipna Nepal
	Please read COPYING.txt included along with this source code for more detail.
	If not included, see http://www.gnu.org/licenses/
*/

#ifndef LIBKEYBOARD_H
#define LIBKEYBOAD_H

#include <WinSock2.h>
#include <Windows.h>
#include <process.h>
#include "definitions.h"

#pragma comment (lib, "Ws2_32.lib")

//From libManageConnections.cpp
extern SOCKET clientSocket;
extern bool terminateKeyboardThread;
extern unsigned char code[PACKET_SIZE];
extern INPUT input;
extern bool checkIndexCode();
extern void threadsSwitch(bool iT, bool mT, bool kT, bool sT);
extern void socketConnect(void *args);
extern void cleanUpSockets();

//From main.cpp
extern void writeLog(const char *msg);

namespace Keyboard {
	void keyboardThread(void *arg);
}

#endif