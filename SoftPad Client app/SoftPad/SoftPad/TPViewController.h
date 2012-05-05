/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#import <UIKit/UIKit.h>
#import "GADBannerView.h"

#include "socketConnection.h"
#include "definition.h"
using namespace SocketConnection;

@interface TPViewController : UIViewController {
    GADBannerView *bannerView_;
}
- (IBAction)panScroll:(UIPanGestureRecognizer*)recognizer;
- (IBAction)panTrackPad:(UIPanGestureRecognizer*)recognizer;
- (IBAction)btnKeyboard:(id)sender;
- (IBAction)btnMenu:(id)sender;
- (IBAction)btnL:(id)sender;
- (IBAction)btnR:(id)sender;
- (IBAction)btnLP:(id)sender;
- (IBAction)btnRP:(id)sender;
- (IBAction)tapTrackPad:(id)sender;
- (IBAction)btnSoftTouch:(id)sender;
- (IBAction)longPressTrackPad:(UILongPressGestureRecognizer*)recognizer;

@end
