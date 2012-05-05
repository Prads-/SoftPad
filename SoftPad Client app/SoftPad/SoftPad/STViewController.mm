/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#import "STViewController.h"

@implementation STViewController
@synthesize touchView;

extern int putView;

int screenWidth = 0, screenHeight = 0;
unsigned char screenPacket[SCREEN_PACKET_SIZE];
unsigned char pixelData[VIEW_AREA * 4];
bool terminateSoftTouchThread = false;

-(void)viewDidLoad {
    terminateSoftTouchThread = false;
    [NSThread detachNewThreadSelector:@selector(refreshCapture) toTarget:self withObject:nil];
    
    bannerView_ = [[GADBannerView alloc] initWithAdSize:kGADAdSizeBanner];
    bannerView_.adUnitID = ADMOB_UNIT_ID;
    bannerView_.rootViewController = self;
    [self.view addSubview:bannerView_];
    [bannerView_ loadRequest:[GADRequest request]];
}

- (void)viewDidUnload {
    [self setTouchView:nil];
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

//Thread method. All it does is ask for screen capture from server and then puts it in UIImage
-(void)refreshCapture {
    while (!terminateSoftTouchThread) {
        sendPacket(0, CODE_SEND_SCREEN, 0, 0, 0, 0);
        recv(hSocket, (char*)screenPacket, SCREEN_PACKET_SIZE, MSG_WAITALL);
        
        int offset = 0, packetCounter = 0;
        for (int i = 0; i < VIEW_AREA; ++i) {
            pixelData[offset] = screenPacket[packetCounter] & 0xF0;
            pixelData[offset + 1] = screenPacket[packetCounter++] << 4;
            pixelData[offset + 2] = screenPacket[packetCounter++];
            pixelData[offset + 3] = 0xFF;
            offset += 4;
        }
        
        CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
        CGContextRef gtx = CGBitmapContextCreate(pixelData, VIEW_WIDTH, VIEW_HEIGHT, 8, VIEW_WIDTH * 4, colorSpace, kCGImageAlphaPremultipliedLast);
        CGImageRef toCGImage = CGBitmapContextCreateImage(gtx);
        UIImage *uiImage = [[UIImage alloc] initWithCGImage:toCGImage];
        
        [touchView performSelectorOnMainThread:@selector(setImage:) withObject:uiImage waitUntilDone:YES];
        
        CGContextRelease(gtx);
        CGImageRelease(toCGImage);
    }
}

//Stride Left
- (IBAction)btnOffsetLeft:(id)sender {
    sendPacket(0, CODE_DECREMENT_OFFSET_H, VIEW_WIDTH, VIEW_WIDTH >> 8, 0, 0);
}

//Stride Right
- (IBAction)btnOffsetRight:(id)sender {
    sendPacket(0, CODE_INCREMENT_OFFSET_H, VIEW_WIDTH, VIEW_WIDTH >> 8, 0, 0);
}

//Stride Up
- (IBAction)btnOffsetUp:(id)sender {
    sendPacket(0, CODE_DECREMENT_OFFSET_V, VIEW_HEIGHT, VIEW_HEIGHT >> 8, 0, 0);
}

//Stride Down
- (IBAction)btnOffsetDown:(id)sender {
    sendPacket(0, CODE_INCREMENT_OFFSET_V, VIEW_HEIGHT, VIEW_HEIGHT >> 8, 0, 0);
}

//Touch
- (IBAction)tapSoftTouch:(UITapGestureRecognizer*)recognizer {
    CGPoint newCoordinates = [recognizer locationInView:self.view];
    int x = (int)newCoordinates.x;
    int y = (int)newCoordinates.y;
    
    sendPacket(0, CODE_TOUCH_INPUT, x, x >> 8, y, y >> 8);
}

//Scroll screen
- (IBAction)panTouchScroll:(UIPanGestureRecognizer*)recognizer {
    CGPoint scrollCoordinates = [recognizer translationInView:self.view];
    int x = scrollCoordinates.x;
    int y = scrollCoordinates.y;
    const int PX_SCROLL = 1;
    
    if (x != 0) {
        if (x > 0) {
            sendPacket(0, CODE_DECREMENT_OFFSET_H, PX_SCROLL, 0, 0, 0);
        } else {
            sendPacket(0, CODE_INCREMENT_OFFSET_H, PX_SCROLL, 0, 0, 0);
        }
    }
    if (y != 0) {
        if (y > 0) {
            sendPacket(0, CODE_DECREMENT_OFFSET_V, PX_SCROLL, 0, 0, 0);
        } else {
            sendPacket(0, CODE_INCREMENT_OFFSET_V, PX_SCROLL, 0, 0, 0);
        }
    }
    [recognizer setTranslation:CGPointMake(0, 0) inView:self.view];
}

- (IBAction)btnTrackPad:(id)sender {
    sendPacket(CODE_TRACKPAD, 0, 0, 0, 0, 0);
    putView = PUT_VIEW_TRACKPAD;
    [self cleanUp];
}

- (IBAction)btnKeyBoard:(id)sender {
    sendPacket(CODE_KEYBOARD, 0, 0, 0, 0, 0);
    putView = PUT_VIEW_KEYBOARD;
    [self cleanUp];
}

- (IBAction)btnMenu:(id)sender {
    sendPacket(CODE_INDEX, 0, 0, 0, 0, 0);
    putView = PUT_VIEW_MENU;
    [self cleanUp];
}

//Press
- (IBAction)longPress:(UILongPressGestureRecognizer*)recognizer {
    if (recognizer.state == UIGestureRecognizerStateBegan) {
        CGPoint newCoordinates = [recognizer locationInView:self.view];
        int x = (int)newCoordinates.x;
        int y = (int)newCoordinates.y;
        
        sendPacket(0, CODE_LONG_PRESS, x, x >> 8, y, y >> 8);
    } else {
        sendPacket(0, CODE_LONG_RELEASED, 0, 0, 0, 0);
    }
}

-(void)cleanUp {
    terminateSoftTouchThread = true;
    [self dismissModalViewControllerAnimated:YES];
}

@end
