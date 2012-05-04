/*
	Written By Pradipna Nepal
	www.pradsprojects.com

	Copyright (C) 2012 Pradipna Nepal
	Please read COPYING.txt included along with this source code for more detail.
	If not included, see http://www.gnu.org/licenses/
*/

#include "libKeyboard.h"

void Keyboard::keyboardThread(void *arg) {
	while (!terminateKeyboardThread) {
		if (recv(clientSocket, (char*)code, PACKET_SIZE, MSG_WAITALL) == 0) {
			writeLog("Disconnected...\r\n");
			cleanUpSockets();
			_beginthread(socketConnect, 0, 0);
			break;
		}
		if (code[0] == CODE_KEEP_ALIVE) continue;
		if (!checkIndexCode()) {
			if (code[2] == KEY_RELEASED)
				input.ki.dwFlags = KEYEVENTF_KEYUP;
			else
				input.ki.dwFlags = 0;
			input.ki.wVk = code[1];
			SendInput(1, &input, sizeof(INPUT));
		}
	}
}