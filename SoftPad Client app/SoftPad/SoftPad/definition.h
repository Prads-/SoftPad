/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#ifndef DEFINITION_H
#define DEFINITION_H

#define PACKET_SIZE                 6   //Packet size in bytes

//Menu
#define CODE_INDEX                  1
#define CODE_TRACKPAD               2
#define CODE_KEYBOARD               3
#define CODE_SOFTTOUCH              4

#define CODE_KEEP_ALIVE             5

//SoftTouch
#define CODE_SEND_SCREEN            1
#define CODE_TOUCH_INPUT            2
#define CODE_INCREMENT_OFFSET_V     3
#define CODE_INCREMENT_OFFSET_H     4
#define CODE_DECREMENT_OFFSET_V     5
#define CODE_DECREMENT_OFFSET_H     6
#define CODE_LONG_PRESS             7
#define CODE_LONG_RELEASED          8

//Keyboard and Mouse
#define KEY_RELEASED                0x80
#define MOUSE_BUTTON_CODE           0x80
#define MOUSE_LEFT_PRESSED          0
#define MOUSE_LEFT_RELEASED         1
#define MOUSE_RIGHT_PRESSED         2
#define MOUSE_RIGHT_RELEASED        3
#define MOUSE_SCROLL_UP             4
#define MOUSE_SCROLL_DOWN           5

//Keyboard virtual key codes
#define VK_F1                       0x70
#define VK_F2                       0x71
#define VK_F3                       0x72
#define VK_F4                       0x73
#define VK_F5	                    0x74
#define VK_F6	                    0x75
#define VK_F7	                    0x76
#define VK_F8	                    0x77
#define VK_F9	                    0x78
#define VK_F10	                    0x79
#define VK_F11	                    0x7A
#define VK_F12	                    0x7B	

#define VK_SPACE                    0x20
#define VK_LEFT                     0x25
#define VK_UP                       0x26
#define VK_RIGHT                    0x27
#define VK_DOWN                     0x28
#define VK_DELETE                   0x2E
#define VK_SHIFT                    0x10
#define VK_CONTROL                  0x11
#define VK_BACK                     0x08
#define VK_TAB                      0x09
#define VK_RETURN                   0x0D
#define VK_ESCAPE                   0x1B
#define VK_CAPITAL                  0x14
#define VK_MENU                     0x12

#define VK_SEMICOLON                0xBA	//OEM_1 (: ;)
#define VK_BACKSLASH                0xBF	//OEM_2 (? /)
#define VK_BACKTICK                 0xC0	//OEM_3 (~ `)
#define VK_OPENSQUARE               0xDB	//OEM_4 ({ [)
#define VK_FRONTSLASH               0xDC	//OEM_5 (| \)
#define VK_CLOSESQUARE              0xDD	//OEM_6 (} ])
#define VK_QUOTE                    0xDE	//OEM_7 (" ')
#define VK_COMMA                    0xBC	//OEM_COMMA (< ,)
#define VK_MINUS                    0xBD	//OEM_MINUS (_ -)
#define VK_PERIOD                   0xBE	//OEM_PERIOD (> .)
#define VK_EQUALS                   0xBB	//OEM_PLUS (+ =)

//Screen height width
#define VIEW_WIDTH                  273
#define VIEW_HEIGHT                 410
#define SCREEN_PACKET_SIZE          (VIEW_WIDTH * VIEW_HEIGHT * 2)  //In bytes
#define VIEW_AREA                   (VIEW_WIDTH * VIEW_HEIGHT)

//Which view to show
#define PUT_VIEW_MENU               0
#define PUT_VIEW_TRACKPAD           1
#define PUT_VIEW_KEYBOARD           2
#define PUT_VIEW_SOFTTOUCH          3

#endif
