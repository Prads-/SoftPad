/*
	Written By Pradipna Nepal
	www.pradsprojects.com

	Copyright (C) 2012 Pradipna Nepal
	Please read COPYING.txt included along with this source code for more detail.
	If not included, see http://www.gnu.org/licenses/
*/

#include "libMouse.h"

concurrent_queue<INPUT> mouseChanges;

void Mouse::mouseThread1(void *arg) {
	while (!terminateMouseThread) {
		if (recv(clientSocket, (char*)code, PACKET_SIZE, MSG_WAITALL) == 0) {
			writeLog("Disconnected...");
			cleanUpSockets();
			_beginthread(socketConnect, 0, 0);
			break;
		}
		if (code[0] == CODE_KEEP_ALIVE) continue;
		if (!checkIndexCode()) {
			if (code[1] == MOUSE_BUTTON_CODE) {
				switch (code[2]) {
					case MOUSE_LEFT_PRESSED:
						input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
						break;
					case MOUSE_LEFT_RELEASED:
						input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
						break;
					case MOUSE_RIGHT_PRESSED:
						input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
						break;
					case MOUSE_RIGHT_RELEASED:
						input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
						break;
					case MOUSE_SCROLL_UP:
						input.mi.dwFlags = MOUSEEVENTF_WHEEL;
						input.mi.mouseData = WHEEL_DELTA / 13;
						break;
					case MOUSE_SCROLL_DOWN:
						input.mi.dwFlags = MOUSEEVENTF_WHEEL;
						input.mi.mouseData = -WHEEL_DELTA / 13;
				}

				input.mi.dx = 0;
				input.mi.dy = 0;
				mouseChanges.push(input);
			} else {
				input.mi.dwFlags = MOUSEEVENTF_MOVE;

				short int x, y;
					
				x = code[2] | (code[3] << 8);
				y = code[4] | (code[5] << 8);
					
				input.mi.dx = x;
				input.mi.dy = y;
				mouseChanges.push(input);
			}
		}
	}
}

//This thread sends mouse input every 15ms so that mouse cursor looks smooth
void Mouse::mouseThread2(void *arg) {
	while (!terminateMouseThread) {
		while (!mouseChanges.empty()) {
			mouseChanges.try_pop(input);
			SendInput(1, &input, sizeof(INPUT));
			Sleep(15);
		}
		Sleep(1);
	}
	mouseChanges.clear();
}