/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#include "socketConnection.h"

int hSocket;
unsigned char code[PACKET_SIZE] = {0};

//Connect with server using BSD sockets
int SocketConnection::socketConnect(const char *ip, const char *port) {
    int retVal = 0;
    hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (hSocket >= 0) {
        
        struct sockaddr_in sockAddr = {0};
        
        sockAddr.sin_addr.s_addr = inet_addr(ip);
        sockAddr.sin_family = AF_INET;
        sockAddr.sin_port = htons(atoi(port));
        
        if (connect(hSocket, (struct sockaddr*)&sockAddr, sizeof(sockAddr)) < 0) 
            retVal = 1;
        else
            retVal = 0;
    } else {
        retVal = 1;
    }
    
    return retVal;
}

//Sends Code Packets to server
void SocketConnection::sendPacket(unsigned char p1, unsigned char p2, unsigned char p3, unsigned char p4, unsigned char p5, unsigned char p6) {
    code[0] = p1;
    code[1] = p2;
    code[2] = p3;
    code[3] = p4;
    code[4] = p5;
    code[5] = p6;
    send(hSocket, code, PACKET_SIZE, 0);
}