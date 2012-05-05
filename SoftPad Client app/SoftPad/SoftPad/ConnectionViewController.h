/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#import <Foundation/Foundation.h>
#import "GADBannerView.h"

#include <vector>
#include <string>
#include <fstream>
#include "socketConnection.h"
#include "definition.h"
using namespace std;
using namespace SocketConnection;

@interface ConnectionViewController :UIViewController {
    NSMutableArray *list;
    GADBannerView *bannerView_;
}
@property (weak, nonatomic) IBOutlet UIPickerView *pickServer;
@property (weak, nonatomic) IBOutlet UILabel *lblStatus;
- (IBAction)btnConnect:(id)sender;
- (IBAction)btnAddNew:(id)sender;
- (IBAction)btnEdit:(id)sender;
- (IBAction)btnDelete:(id)sender;
- (IBAction)btnCancel:(id)sender;
@property (weak, nonatomic) IBOutlet UITextField *txtNewName;
@property (weak, nonatomic) IBOutlet UITextField *txtNewIP;
@property (weak, nonatomic) IBOutlet UITextField *txtNewPort;
@property (weak, nonatomic) IBOutlet UITextField *txtEditName;
@property (weak, nonatomic) IBOutlet UITextField *txtEditIP;
@property (weak, nonatomic) IBOutlet UITextField *txtEditPort;


@end
