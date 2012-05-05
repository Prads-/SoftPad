/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#import "TPViewController.h"

@interface TPViewController ()

@end

@implementation TPViewController

extern int putView;

NSTimer *tpTimer = nil;
bool doTPTimer = true;

- (void)viewDidLoad
{
    [super viewDidLoad];
	tpTimer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(timerFunc) userInfo:self repeats:YES];
    
    bannerView_ = [[GADBannerView alloc] initWithAdSize:kGADAdSizeBanner];
    bannerView_.adUnitID = ADMOB_UNIT_ID;
    bannerView_.rootViewController = self;
    [self.view addSubview:bannerView_];
    [bannerView_ loadRequest:[GADRequest request]];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

//Sends keep alive packets to keep connection busy
-(void)timerFunc {
    if (doTPTimer)
        sendPacket(CODE_KEEP_ALIVE, 0, 0, 0, 0, 0);
    else
        doTPTimer = true;
}

//Scroll
- (IBAction)panScroll:(UIPanGestureRecognizer*)recognizer {
    doTPTimer = false;
    CGPoint newCoordinates = [recognizer translationInView:self.view];
    
    if (newCoordinates.y < 0.0)
        sendPacket(0, MOUSE_BUTTON_CODE, MOUSE_SCROLL_UP, 0, 0, 0);
    else if (newCoordinates.y > 0.0)
        sendPacket(0, MOUSE_BUTTON_CODE, MOUSE_SCROLL_DOWN, 0, 0, 0);
    
    [recognizer setTranslation:CGPointMake(0, 0) inView:self.view];
}

//Move cursor
- (IBAction)panTrackPad:(UIPanGestureRecognizer*)recognizer {
    doTPTimer = false;
    CGPoint newCoordinates = [recognizer translationInView:self.view];
    int x = (int)newCoordinates.x;
    int y = (int)newCoordinates.y;
    
    sendPacket(0, 0, x, x >> 8, y, y >> 8);
    [recognizer setTranslation:CGPointMake(0, 0) inView:self.view];
}


- (IBAction)btnKeyboard:(id)sender {
    sendPacket(CODE_KEYBOARD, 0, 0, 0, 0, 0);
    putView = PUT_VIEW_KEYBOARD;
    [self cleanUp];
}

- (IBAction)btnMenu:(id)sender {
    sendPacket(CODE_INDEX, 0, 0, 0, 0, 0);
    putView = PUT_VIEW_MENU;
    [self cleanUp];
}

//Left Button Released
- (IBAction)btnL:(id)sender {
    doTPTimer = false;
    sendPacket(0, MOUSE_BUTTON_CODE, MOUSE_LEFT_RELEASED, 0, 0, 0);
}

//Right Button Released
- (IBAction)btnR:(id)sender {
    doTPTimer = false;
    sendPacket(0, MOUSE_BUTTON_CODE, MOUSE_RIGHT_RELEASED, 0, 0, 0);
}

//Left Button Pressed
- (IBAction)btnLP:(id)sender {
    doTPTimer = false;
    sendPacket(0, MOUSE_BUTTON_CODE, MOUSE_LEFT_PRESSED, 0, 0, 0);
}

//Right Button Pressed
- (IBAction)btnRP:(id)sender {
    doTPTimer = false;
    sendPacket(0, MOUSE_BUTTON_CODE, MOUSE_RIGHT_PRESSED, 0, 0, 0);
}

//Click
- (IBAction)tapTrackPad:(id)sender {
    sendPacket(0, MOUSE_BUTTON_CODE, MOUSE_LEFT_PRESSED, 0, 0, 0);
    sendPacket(0, MOUSE_BUTTON_CODE, MOUSE_LEFT_RELEASED, 0, 0, 0);
}

- (IBAction)btnSoftTouch:(id)sender {
    sendPacket(CODE_SOFTTOUCH, 0, 0, 0, 0, 0);
    putView = PUT_VIEW_SOFTTOUCH;
    [self cleanUp];
}

//Press
- (IBAction)longPressTrackPad:(UILongPressGestureRecognizer*)recognizer {
    doTPTimer = false;
    if (recognizer.state == UIGestureRecognizerStateBegan)
        sendPacket(0, MOUSE_BUTTON_CODE, MOUSE_LEFT_PRESSED, 0, 0, 0);
    else
        sendPacket(0, MOUSE_BUTTON_CODE, MOUSE_LEFT_RELEASED, 0, 0, 0);
}

-(void)cleanUp {
    [tpTimer invalidate];
    tpTimer = nil;
    [self dismissModalViewControllerAnimated:YES];
}

@end
