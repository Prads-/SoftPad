/*
 Written By Pradipna Nepal
 www.pradsprojects.com
 
 Copyright (C) 2012 Prads Projects
 Please read COPYING.txt included along with this source code for more detail.
 If not included, see http://www.gnu.org/licenses/
 */

#import "ConnectionViewController.h"

@implementation ConnectionViewController
@synthesize pickServer;
@synthesize txtNewName;
@synthesize txtNewIP;
@synthesize txtNewPort;
@synthesize txtEditName;
@synthesize txtEditIP;
@synthesize txtEditPort;
@synthesize lblStatus;

struct ServerInfo {
    string name, ip, portNumber;
};

vector<ServerInfo> serverList;
bool loadSFile = true;  //This will be true only once when app loads. Load the server file when it's true
NSString *lblString;
NSString *serverFilePath;
int pickerViewIndex;

bool loadServerFile();
void getServerList(unsigned char *bin, int size);
bool saveServerFile();

-(NSInteger)numberOfComponentsInPickerView:(UIPickerView*)thePickerView {
    return 1;
}

-(NSInteger)pickerView:(UIPickerView *)thePickerView numberOfRowsInComponent:(NSInteger)component {
    return [list count];
}

-(NSString *)pickerView:(UIPickerView *)thePicketView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    return [list objectAtIndex:row];
}

-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    pickerViewIndex = [pickerView selectedRowInComponent:0];
}

-(void)viewDidLoad {
    bannerView_ = [[GADBannerView alloc] initWithAdSize:kGADAdSizeBanner];
    bannerView_.adUnitID = ADMOB_UNIT_ID;
    bannerView_.rootViewController = self;
    [self.view addSubview:bannerView_];
    [bannerView_ loadRequest:[GADRequest request]];
}

-(void)viewDidAppear:(BOOL)animated {
    if (loadSFile) {
        NSArray *searchPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        serverFilePath = [searchPaths objectAtIndex:0];
        serverFilePath = [serverFilePath stringByAppendingString:@"SoftPadServerList.dat"];
        if (!loadServerFile()) {
           lblString = @"Loading server list failed";
        }
        loadSFile = false;
    }
    if (self.view.tag == 0) {
        lblStatus.text = lblString;
        [self updatePickerView];
    } else if (self.view.tag == 1) {
        [self updateTextBoxes];
    }
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

bool loadServerFile() {
    ifstream serverFile;
    
    serverFile.open([serverFilePath cStringUsingEncoding:NSUTF8StringEncoding], ios::binary | ios::ate);
    if (serverFile.is_open()) {
        int size = serverFile.tellg();
        serverFile.seekg(0, ios::beg);
        unsigned char *bin = new (nothrow) unsigned char [size];
        if (bin == 0) {
            serverFile.close();
            return false;
        }
        serverFile.read((char*)bin, size);
        serverFile.close();
        getServerList(bin, size);
        delete [] bin;
    } else {
        return false;
    }
    
    return true;
}

/*
    Servers List are saved in SoftPadServerList.dat file in application's document folder.
    1 is used as delimiter between servers as well as their name, ip and port.
    Example: [name][1][ip][1][port][1][name][1][ip][1][port]... so on...
*/
bool saveServerFile() {
    int size = 0;
    for (unsigned int i = 0; i < serverList.size(); ++i) {
        size += serverList[i].name.size();
        size += serverList[i].ip.size();
        size += serverList[i].portNumber.size();
        size += 3;
    }
    
    unsigned char *bin = new (nothrow) unsigned char [size];
    if (bin == 0) return false;
    
    int binCounter = 0;
    
    for (unsigned int i =0; i < serverList.size(); ++i) {
        memcpy(&bin[binCounter], serverList[i].name.c_str(), serverList[i].name.size());
        binCounter += serverList[i].name.size();
        bin[binCounter++] = 1;
        memcpy(&bin[binCounter], serverList[i].ip.c_str(), serverList[i].ip.size());
        binCounter += serverList[i].ip.size();
        bin[binCounter++] = 1;
        memcpy(&bin[binCounter], serverList[i].portNumber.c_str(), serverList[i].portNumber.size());
        binCounter += serverList[i].portNumber.size();
        bin[binCounter++] = 1;
    }
    
    ofstream serverFile;
    bool retVal = true;
    
    serverFile.open([serverFilePath cStringUsingEncoding:NSUTF8StringEncoding], ios::binary);
    if (serverFile.is_open()) {
        serverFile.write((char*)bin, size);
        serverFile.close();
    } else {
        retVal = false;
    }
    
    delete [] bin;
    return retVal;
}

void getServerList(unsigned char *bin, int size) {
    ServerInfo temp;
    
    for (int i = 0; i < size; ++i) {
        temp.name = string();
        while (bin[i] != 1) temp.name += bin[i++];
        ++i;
        temp.ip = string();
        while (bin[i] != 1) temp.ip += bin[i++];
        ++i;
        temp.portNumber = string();
        while (bin[i] != 1) temp.portNumber += bin[i++];
        
        serverList.push_back(temp);
    }
}

-(void)updateTextBoxes {
    if (serverList.size() == 0) return;
    
    txtEditName.text = [[NSString alloc] initWithUTF8String:serverList[pickerViewIndex].name.c_str()];
    txtEditIP.text = [[NSString alloc] initWithUTF8String:serverList[pickerViewIndex].ip.c_str()];
    txtEditPort.text = [[NSString alloc] initWithUTF8String:serverList[pickerViewIndex].portNumber.c_str()];
}
    
- (IBAction)btnConnect:(id)sender {
    if (serverList.size() == 0) return;
    
    if (socketConnect(serverList[pickerViewIndex].ip.c_str(), serverList[pickerViewIndex].portNumber.c_str()))
        lblStatus.text = @"Connection failed";
    else
        [self performSegueWithIdentifier:@"MenuView" sender:sender];
}

- (IBAction)btnAddNew:(id)sender {
    ServerInfo temp;
    
    temp.name = [txtNewName.text cStringUsingEncoding:NSUTF8StringEncoding];
    temp.ip = [txtNewIP.text cStringUsingEncoding:NSUTF8StringEncoding];
    temp.portNumber = [txtNewPort.text cStringUsingEncoding:NSUTF8StringEncoding];
    
    serverList.push_back(temp);
    
    if (!saveServerFile()) 
        lblString = @"Saving server list failed";
    else
        lblString = @"";
    
    [self dismissModalViewControllerAnimated:YES];
}

- (IBAction)btnEdit:(id)sender {
    if (serverList.size() == 0) return;
    
    serverList[pickerViewIndex].name = [txtEditName.text cStringUsingEncoding:NSUTF8StringEncoding];
    serverList[pickerViewIndex].ip = [txtEditIP.text cStringUsingEncoding:NSUTF8StringEncoding];
    serverList[pickerViewIndex].portNumber = [txtEditPort.text cStringUsingEncoding:NSUTF8StringEncoding];
    
    if (!saveServerFile()) 
        lblString = @"Saving server list failed";
    else
        lblString = @"";
    
    [self dismissModalViewControllerAnimated:YES];
}

- (IBAction)btnDelete:(id)sender {
    if (serverList.size() == 0) return;
    
    serverList.erase(serverList.begin() + pickerViewIndex);
    
    if (!saveServerFile()) 
        lblString = @"Saving server list failed";
    else
        lblString = @"";
    [self updatePickerView];
}

- (IBAction)btnCancel:(id)sender {
    [self dismissModalViewControllerAnimated:YES];
}

-(void)updatePickerView {
    list = [[NSMutableArray alloc] init];
    for (int i = 0; i < serverList.size(); ++i) {
        NSString *temp =[[NSString alloc] initWithUTF8String:serverList[i].name.c_str()];
        [list addObject:temp];
    }
    [pickServer reloadAllComponents];
    pickerViewIndex = 0;
}


- (void)viewDidUnload {
    [self setLblStatus:nil];
    [self setTxtNewName:nil];
    [self setTxtNewIP:nil];
    [self setTxtNewPort:nil];
    [self setTxtEditName:nil];
    [self setTxtEditIP:nil];
    [self setTxtEditPort:nil];
    [self setPickServer:nil];
    [super viewDidUnload];
}

@end
