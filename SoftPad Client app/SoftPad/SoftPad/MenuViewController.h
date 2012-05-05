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
using namespace SocketConnection;

@interface MenuViewController : UIViewController {
    GADBannerView *bannerView_;
}
- (IBAction)btnExit:(id)sender;
- (IBAction)btnTrackPad:(id)sender;
- (IBAction)btnKeyBoard:(id)sender;
- (IBAction)btnSoftTouch:(id)sender;

@end
