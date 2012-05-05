/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#import "KBViewController.h"

@implementation KBViewController

extern int putView;

NSTimer *kbTimer = nil;
bool doKBTimer = true;

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

/*////////////////////////////////
 Send Virtual Key codes to server
 *////////////////////////////////

- (IBAction)btnDash:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_MINUS, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnEquals:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_EQUALS, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnSquareOpen:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_OPENSQUARE, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnSquareClose:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_CLOSESQUARE, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnFrontSlash:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_FRONTSLASH, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnSemicolon:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_SEMICOLON, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnQuote:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_QUOTE, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnComma:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_COMMA, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnFullStop:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_PERIOD, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnBackSlash:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_BACKSLASH, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnBackTickP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_BACKTICK, 0,0, 0, 0);
}

- (IBAction)btnBackSlashP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_BACKSLASH, 0,0, 0, 0);
}

- (IBAction)btnEqualsP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_EQUALS, 0,0, 0, 0);
}

- (IBAction)btnSquareOpenP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_OPENSQUARE, 0,0, 0, 0);
}

- (IBAction)btnSquareCloseP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_CLOSESQUARE, 0,0, 0, 0);
}

- (IBAction)btnFrontSlashP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_FRONTSLASH, 0,0, 0, 0);
}

- (IBAction)btnSemicolonP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_SEMICOLON, 0,0, 0, 0);
}

- (IBAction)btnQuoteP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_QUOTE, 0,0, 0, 0);
}

- (IBAction)btnCommaP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_COMMA, 0,0, 0, 0);
}

- (IBAction)btnF11P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F11, 0,0, 0, 0);
}

- (IBAction)btnF12P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F12, 0,0, 0, 0);
}

- (IBAction)btnF1P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F1, 0,0, 0, 0);
}

- (IBAction)btnF2P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F2, 0,0, 0, 0);
}

- (IBAction)btnF3P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F3, 0,0, 0, 0);
}

- (IBAction)btnF4P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F4, 0,0, 0, 0);
}

- (IBAction)btnF5P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F5, 0,0, 0, 0);
}

- (IBAction)btnF6P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F6, 0,0, 0, 0);
}

- (IBAction)btnF7P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F7, 0,0, 0, 0);
}

- (IBAction)btnF8P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F8, 0,0, 0, 0);
}

- (IBAction)btnF9P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F9, 0,0, 0, 0);
}

- (IBAction)btnF10P:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F10, 0,0, 0, 0);
}

- (IBAction)btn1P:(id)sender {
    doKBTimer = false;
    sendPacket(0, '1', 0,0, 0, 0);
}

- (IBAction)btn2P:(id)sender {
    doKBTimer = false;
    sendPacket(0, '2', 0,0, 0, 0);
}

- (IBAction)btn3P:(id)sender {
    doKBTimer = false;
    sendPacket(0, '3', 0,0, 0, 0);
}

- (IBAction)btn4P:(id)sender {
    doKBTimer = false;
    sendPacket(0, '4', 0,0, 0, 0);
}

- (IBAction)btn5P:(id)sender {
    doKBTimer = false;
    sendPacket(0, '5', 0,0, 0, 0);
}

- (IBAction)btn6P:(id)sender {
    doKBTimer = false;
    sendPacket(0, '6', 0,0, 0, 0);
}

- (IBAction)btn7P:(id)sender {
    doKBTimer = false;
    sendPacket(0, '7', 0,0, 0, 0);
}

- (IBAction)btn8P:(id)sender {
    doKBTimer = false;
    sendPacket(0, '8', 0,0, 0, 0);
}

- (IBAction)btn9P:(id)sender {
    doKBTimer = false;
    sendPacket(0, '9', 0,0, 0, 0);
}

- (IBAction)btn0P:(id)sender {
    doKBTimer = false;
    sendPacket(0, '0', 0,0, 0, 0);
}

- (IBAction)btnQP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'Q', 0,0, 0, 0);
}

- (IBAction)btnWP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'W', 0,0, 0, 0);
}

- (IBAction)btnEP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'E', 0,0, 0, 0);
}

- (IBAction)btnRP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'R', 0,0, 0, 0);
}

- (IBAction)btnTP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'T', 0,0, 0, 0);
}

- (IBAction)btnYP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'Y', 0,0, 0, 0);
}

- (IBAction)btnUP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'U', 0,0, 0, 0);
}

- (IBAction)btnIP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'I', 0,0, 0, 0);
}

- (IBAction)btnOP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'O', 0,0, 0, 0);
}

- (IBAction)btnPP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'P', 0,0, 0, 0);
}

- (IBAction)btnAP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'A', 0,0, 0, 0);
}

- (IBAction)btnSP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'S', 0,0, 0, 0);
}

- (IBAction)btnDP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'D', 0,0, 0, 0);
}

- (IBAction)btnFP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'F', 0,0, 0, 0);
}

- (IBAction)btnGP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'G', 0,0, 0, 0);
}

- (IBAction)btnHP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'H', 0,0, 0, 0);
}

- (IBAction)btnJP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'J', 0,0, 0, 0);
}

- (IBAction)btnKP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'K', 0,0, 0, 0);
}

- (IBAction)btnLP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'L', 0,0, 0, 0);
}

- (IBAction)btnShiftP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_SHIFT, 0,0, 0, 0);
}

- (IBAction)btnZP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'Z', 0,0, 0, 0);
}

- (IBAction)btnXP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'X', 0,0, 0, 0);
}

- (IBAction)btnCP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'C', 0,0, 0, 0);
}

- (IBAction)btnVP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'V', 0,0, 0, 0);
}

- (IBAction)btnBP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'B', 0,0, 0, 0);
}

- (IBAction)btnNP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'N', 0,0, 0, 0);
}

- (IBAction)btnMP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'M', 0,0, 0, 0);
}

- (IBAction)btnTabP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_TAB, 0,0, 0, 0);
}

- (IBAction)btnCtrlP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_CONTROL, 0,0, 0, 0);
}

- (IBAction)btnAltP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_MENU, 0,0, 0, 0);
}

- (IBAction)btnSpaceP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_SPACE, 0,0, 0, 0);
}

- (IBAction)btnEnterP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_RETURN, 0,0, 0, 0);
}

- (IBAction)btnCapsP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_CAPITAL, 0,0, 0, 0);
}

- (IBAction)btnDelP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_DELETE, 0,0, 0, 0);
}

- (IBAction)btnBackP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_BACK, 0,0, 0, 0);
}

- (IBAction)btnUpP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_UP, 0,0, 0, 0);
}

- (IBAction)btnLeftP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_LEFT, 0,0, 0, 0);
}

- (IBAction)btnDownP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_DOWN, 0,0, 0, 0);
}

- (IBAction)btnRightP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_RIGHT, 0,0, 0, 0);
}

- (IBAction)btnTrackPad:(id)sender {
    sendPacket(CODE_TRACKPAD, 0, 0,0, 0, 0);
    putView = PUT_VIEW_TRACKPAD;
    [self cleanUp];
}

- (IBAction)btnMenu:(id)sender {
    sendPacket(CODE_INDEX, 0, 0,0, 0, 0);
    putView = PUT_VIEW_MENU;
    [self cleanUp];
}

- (IBAction)btnSoftTouch:(id)sender {
    sendPacket(CODE_SOFTTOUCH, 0, 0, 0, 0, 0);
    putView = PUT_VIEW_SOFTTOUCH;
    [self cleanUp];
}

- (IBAction)backTick:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_BACK, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF1:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F1, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF2:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F2, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF3:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F3, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF4:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F4, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF5:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F5, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF6:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F6, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF7:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F7, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF8:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F8, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF9:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F9, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF10:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F10, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF11:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F11, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnF12:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_F12, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnOne:(id)sender {
    doKBTimer = false;
    sendPacket(0, '1', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnTwo:(id)sender {
    doKBTimer = false;
    sendPacket(0, '2', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnThree:(id)sender {
    doKBTimer = false;
    sendPacket(0, '3', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnFour:(id)sender {
    doKBTimer = false;
    sendPacket(0, '4', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnFive:(id)sender {
    doKBTimer = false;
    sendPacket(0, '5', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnSix:(id)sender {
    doKBTimer = false;
    sendPacket(0, '6', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnSeven:(id)sender {
    doKBTimer = false;
    sendPacket(0, '7', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnEight:(id)sender {
    doKBTimer = false;
    sendPacket(0, '8', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnNine:(id)sender {
    doKBTimer = false;
    sendPacket(0, '9', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnZero:(id)sender {
    doKBTimer = false;
    sendPacket(0, '0', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnQ:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'Q', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnW:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'W', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnE:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'E', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnR:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'R', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnT:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'T', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnY:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'Y', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnU:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'U', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnI:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'I', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnO:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'O', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnP:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'P', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnA:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'A', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnS:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'S', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnD:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'D', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnRight:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_RIGHT, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnLeft:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_LEFT, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnDown:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_DOWN, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnDashP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_MINUS, 0,0, 0, 0);
}

- (IBAction)btnFullstopP:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_PERIOD, 0,0, 0, 0);
}

- (IBAction)btnF:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'F', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnG:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'G', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnH:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'H', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnJ:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'J', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnK:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'K', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnL:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'L', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnZ:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'Z', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnX:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'X', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnC:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'C', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnV:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'V', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnB:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'B', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnN:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'N', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnM:(id)sender {
    doKBTimer = false;
    sendPacket(0, 'M', KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnShift:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_SHIFT, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnTab:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_TAB, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnCtrl:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_CONTROL, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnAlt:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_MENU, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnSpace:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_SPACE, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnEnter:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_RETURN, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnCaps:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_CAPITAL, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnDel:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_DELETE, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnBack:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_BACK, KEY_RELEASED,0, 0, 0);
}

- (IBAction)btnUp:(id)sender {
    doKBTimer = false;
    sendPacket(0, VK_UP, KEY_RELEASED,0, 0, 0);
}

- (void)viewDidUnload {
    [super viewDidUnload];
}

-(void)viewDidLoad {
    kbTimer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(timerFunc) userInfo:nil repeats:YES];
    
    bannerView_ = [[GADBannerView alloc] initWithAdSize:kGADAdSizeBanner];
    bannerView_.adUnitID = ADMOB_UNIT_ID;
    bannerView_.rootViewController = self;
    [self.view addSubview:bannerView_];
    [bannerView_ loadRequest:[GADRequest request]];
}

-(void)timerFunc {
    if (doKBTimer)
        sendPacket(CODE_KEEP_ALIVE, 0, 0, 0, 0, 0);
    else
        doKBTimer = true;
}

-(void)cleanUp {
    [kbTimer invalidate];
    kbTimer = nil;
    [self dismissModalViewControllerAnimated:YES];
}

@end
