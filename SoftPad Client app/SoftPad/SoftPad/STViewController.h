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

@interface STViewController :UIViewController {
    GADBannerView *bannerView_;
}

@property (weak, nonatomic) IBOutlet UIImageView *touchView;
- (IBAction)btnOffsetLeft:(id)sender;
- (IBAction)btnOffsetRight:(id)sender;
- (IBAction)btnOffsetUp:(id)sender;
- (IBAction)btnOffsetDown:(id)sender;
- (IBAction)tapSoftTouch:(UITapGestureRecognizer*)recognizer;
- (IBAction)panTouchScroll:(UIPanGestureRecognizer*)recognizer;
- (IBAction)btnTrackPad:(id)sender;
- (IBAction)btnKeyBoard:(id)sender;
- (IBAction)btnMenu:(id)sender;
- (IBAction)longPress:(UILongPressGestureRecognizer*)recognizer;

@end
