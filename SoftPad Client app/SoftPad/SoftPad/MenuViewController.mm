/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#import "MenuViewController.h"

@interface MenuViewController ()

@end

@implementation MenuViewController

int putView = PUT_VIEW_MENU;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
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

-(void)viewDidAppear:(BOOL)animated {
    switch (putView) {
        case PUT_VIEW_TRACKPAD:
            [self performSegueWithIdentifier:@"TrackPadView" sender:self];
            break;
        case PUT_VIEW_KEYBOARD:
            [self performSegueWithIdentifier:@"KeyBoardView" sender:self];
            break;
        case PUT_VIEW_SOFTTOUCH:
            [self performSegueWithIdentifier:@"SoftTouchView" sender:self];
    }
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (IBAction)btnExit:(id)sender {
    exit(0);    //Maybe not the right way?
}

- (IBAction)btnTrackPad:(id)sender {
    sendPacket(CODE_TRACKPAD, 0, 0, 0, 0, 0);
    [self performSegueWithIdentifier:@"TrackPadView" sender:self];
}

- (IBAction)btnKeyBoard:(id)sender {
    sendPacket(CODE_KEYBOARD, 0, 0, 0, 0, 0);
    [self performSegueWithIdentifier:@"KeyBoardView" sender:self];
}

- (IBAction)btnSoftTouch:(id)sender {
    sendPacket(CODE_SOFTTOUCH, 0, 0, 0, 0, 0);
    [self performSegueWithIdentifier:@"SoftTouchView" sender:self];
}

@end
