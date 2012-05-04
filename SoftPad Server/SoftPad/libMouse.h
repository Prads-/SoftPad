/*
	Written By Pradipna Nepal
	www.pradsprojects.com

	Copyright (C) 2012 Pradipna Nepal
	Please read COPYING.txt included along with this source code for more detail.
	If not included, see http://www.gnu.org/licenses/
*/

#ifndef LIBMOUSE_H
#define LIBMOUSE_H

#include <WinSock2.h>
#include <Windows.h>
#include <process.h>
#include <concurrent_queue.h>
#include "definitions.h"
using namespace Concurrency;

#pragma comment (lib, "Ws2_32.lib")

//From libManageConnections.cpp
extern SOCKET clientSocket;
extern bool terminateMouseThread;
extern unsigned char code[PACKET_SIZE];
extern INPUT input;
extern void threadsSwitch(bool iT, bool mT, bool kT, bool sT);
extern bool checkIndexCode();
extern void socketConnect(void *args);
extern void cleanUpSockets();

//From main.cpp
extern void writeLog(const char *msg);

namespace Mouse {
	void mouseThread1(void *arg);
	void mouseThread2(void *arg);
}

#endif