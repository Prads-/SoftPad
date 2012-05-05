/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#import <Foundation/Foundation.h>
#import "GADBannerView.h"

#include "socketConnection.h"
#include "definition.h"
using namespace SocketConnection;

@interface KBViewController : UIViewController{
    GADBannerView *bannerView_;
}
- (IBAction)btnDash:(id)sender;
- (IBAction)btnEquals:(id)sender;
- (IBAction)btnSquareOpen:(id)sender;
- (IBAction)btnSquareClose:(id)sender;
- (IBAction)btnFrontSlash:(id)sender;
- (IBAction)btnSemicolon:(id)sender;
- (IBAction)btnQuote:(id)sender;
- (IBAction)btnComma:(id)sender;
- (IBAction)btnFullStop:(id)sender;
- (IBAction)btnBackSlash:(id)sender;
- (IBAction)backTick:(id)sender;
- (IBAction)btnF1:(id)sender;
- (IBAction)btnF2:(id)sender;
- (IBAction)btnF3:(id)sender;
- (IBAction)btnF4:(id)sender;
- (IBAction)btnF5:(id)sender;
- (IBAction)btnF6:(id)sender;
- (IBAction)btnF7:(id)sender;
- (IBAction)btnF8:(id)sender;
- (IBAction)btnF9:(id)sender;
- (IBAction)btnF10:(id)sender;
- (IBAction)btnF11:(id)sender;
- (IBAction)btnF12:(id)sender;
- (IBAction)btnOne:(id)sender;
- (IBAction)btnTwo:(id)sender;
- (IBAction)btnThree:(id)sender;
- (IBAction)btnFour:(id)sender;
- (IBAction)btnFive:(id)sender;
- (IBAction)btnSix:(id)sender;
- (IBAction)btnSeven:(id)sender;
- (IBAction)btnEight:(id)sender;
- (IBAction)btnNine:(id)sender;
- (IBAction)btnZero:(id)sender;
- (IBAction)btnQ:(id)sender;
- (IBAction)btnW:(id)sender;
- (IBAction)btnE:(id)sender;
- (IBAction)btnR:(id)sender;
- (IBAction)btnT:(id)sender;
- (IBAction)btnY:(id)sender;
- (IBAction)btnU:(id)sender;
- (IBAction)btnI:(id)sender;
- (IBAction)btnO:(id)sender;
- (IBAction)btnP:(id)sender;
- (IBAction)btnA:(id)sender;
- (IBAction)btnS:(id)sender;
- (IBAction)btnD:(id)sender;
- (IBAction)btnF:(id)sender;
- (IBAction)btnG:(id)sender;
- (IBAction)btnH:(id)sender;
- (IBAction)btnJ:(id)sender;
- (IBAction)btnK:(id)sender;
- (IBAction)btnL:(id)sender;
- (IBAction)btnZ:(id)sender;
- (IBAction)btnX:(id)sender;
- (IBAction)btnC:(id)sender;
- (IBAction)btnV:(id)sender;
- (IBAction)btnB:(id)sender;
- (IBAction)btnN:(id)sender;
- (IBAction)btnM:(id)sender;
- (IBAction)btnShift:(id)sender;
- (IBAction)btnTab:(id)sender;
- (IBAction)btnCtrl:(id)sender;
- (IBAction)btnAlt:(id)sender;
- (IBAction)btnSpace:(id)sender;
- (IBAction)btnEnter:(id)sender;
- (IBAction)btnCaps:(id)sender;
- (IBAction)btnDel:(id)sender;
- (IBAction)btnBack:(id)sender;
- (IBAction)btnUp:(id)sender;
- (IBAction)btnRight:(id)sender;
- (IBAction)btnLeft:(id)sender;
- (IBAction)btnDown:(id)sender;

- (IBAction)btnDashP:(id)sender;
- (IBAction)btnFullstopP:(id)sender;
- (IBAction)btnBackTickP:(id)sender;
- (IBAction)btnBackSlashP:(id)sender;
- (IBAction)btnEqualsP:(id)sender;
- (IBAction)btnSquareOpenP:(id)sender;
- (IBAction)btnSquareCloseP:(id)sender;
- (IBAction)btnFrontSlashP:(id)sender;
- (IBAction)btnSemicolonP:(id)sender;
- (IBAction)btnQuoteP:(id)sender;
- (IBAction)btnCommaP:(id)sender;
- (IBAction)btnF11P:(id)sender;
- (IBAction)btnF12P:(id)sender;
- (IBAction)btnF1P:(id)sender;
- (IBAction)btnF2P:(id)sender;
- (IBAction)btnF3P:(id)sender;
- (IBAction)btnF4P:(id)sender;
- (IBAction)btnF5P:(id)sender;
- (IBAction)btnF6P:(id)sender;
- (IBAction)btnF7P:(id)sender;
- (IBAction)btnF8P:(id)sender;
- (IBAction)btnF9P:(id)sender;
- (IBAction)btnF10P:(id)sender;
- (IBAction)btn1P:(id)sender;
- (IBAction)btn2P:(id)sender;
- (IBAction)btn3P:(id)sender;
- (IBAction)btn4P:(id)sender;
- (IBAction)btn5P:(id)sender;
- (IBAction)btn6P:(id)sender;
- (IBAction)btn7P:(id)sender;
- (IBAction)btn8P:(id)sender;
- (IBAction)btn9P:(id)sender;
- (IBAction)btn0P:(id)sender;
- (IBAction)btnQP:(id)sender;
- (IBAction)btnWP:(id)sender;
- (IBAction)btnEP:(id)sender;
- (IBAction)btnRP:(id)sender;
- (IBAction)btnTP:(id)sender;
- (IBAction)btnYP:(id)sender;
- (IBAction)btnUP:(id)sender;
- (IBAction)btnIP:(id)sender;
- (IBAction)btnOP:(id)sender;
- (IBAction)btnPP:(id)sender;
- (IBAction)btnAP:(id)sender;
- (IBAction)btnSP:(id)sender;
- (IBAction)btnDP:(id)sender;
- (IBAction)btnFP:(id)sender;
- (IBAction)btnGP:(id)sender;
- (IBAction)btnHP:(id)sender;
- (IBAction)btnJP:(id)sender;
- (IBAction)btnKP:(id)sender;
- (IBAction)btnLP:(id)sender;
- (IBAction)btnShiftP:(id)sender;
- (IBAction)btnZP:(id)sender;
- (IBAction)btnXP:(id)sender;
- (IBAction)btnCP:(id)sender;
- (IBAction)btnVP:(id)sender;
- (IBAction)btnBP:(id)sender;
- (IBAction)btnNP:(id)sender;
- (IBAction)btnMP:(id)sender;
- (IBAction)btnTabP:(id)sender;
- (IBAction)btnCtrlP:(id)sender;
- (IBAction)btnAltP:(id)sender;
- (IBAction)btnSpaceP:(id)sender;
- (IBAction)btnEnterP:(id)sender;
- (IBAction)btnCapsP:(id)sender;
- (IBAction)btnDelP:(id)sender;
- (IBAction)btnBackP:(id)sender;
- (IBAction)btnUpP:(id)sender;
- (IBAction)btnLeftP:(id)sender;
- (IBAction)btnDownP:(id)sender;
- (IBAction)btnRightP:(id)sender;
- (IBAction)btnTrackPad:(id)sender;
- (IBAction)btnMenu:(id)sender;
- (IBAction)btnSoftTouch:(id)sender;


@end
