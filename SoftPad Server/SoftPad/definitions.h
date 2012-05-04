/*
	Written By Pradipna Nepal
	www.pradsprojects.com

	Copyright (C) 2012 Pradipna Nepal
	Please read COPYING.txt included along with this source code for more detail.
	If not included, see http://www.gnu.org/licenses/
*/

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define PACKET_SIZE					6			//Size of Code Package in bytes

//Menu
#define CODE_INDEX					1
#define CODE_TRACKPAD				2
#define CODE_KEYBOARD				3
#define CODE_SOFTTOUCH				4

#define CODE_KEEP_ALIVE				5

//Keyboard and Mouse
#define KEY_RELEASED				0x80
#define MOUSE_BUTTON_CODE			0x80
#define MOUSE_LEFT_PRESSED			0
#define MOUSE_LEFT_RELEASED			1
#define MOUSE_RIGHT_PRESSED			2
#define MOUSE_RIGHT_RELEASED		3
#define MOUSE_SCROLL_UP				4
#define MOUSE_SCROLL_DOWN			5

//SoftTouch
#define CODE_SEND_SCREEN			1
#define CODE_TOUCH_INPUT			2
#define CODE_INCREMENT_OFFSET_V		3
#define CODE_INCREMENT_OFFSET_H		4
#define CODE_DECREMENT_OFFSET_V		5
#define CODE_DECREMENT_OFFSET_H		6
#define CODE_LONG_PRESS				7
#define CODE_LONG_RELEASED			8

#endif