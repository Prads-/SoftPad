/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "definition.h"

#define ADMOB_UNIT_ID       @"a14f78ecea6e107"

extern int hSocket;
extern unsigned char code[PACKET_SIZE];

namespace SocketConnection {
    int socketConnect(const char *ip, const char *port);
    void sendPacket(unsigned char p1, unsigned char p2, unsigned char p3, unsigned char p4, unsigned char p5, unsigned char p6);
}

#endif
