//
//  OGLControllerViewController.m
//  EyerPlayer
//
//  Created by lichi on 2021/3/16.
//

#import "OGLControllerViewController.h"
#import <OpenGLES/EAGLIOSurface.h>
#import <GLKit/GLKit.h>

#include "OGLView.h"

@interface OGLControllerViewController ()

@end

@implementation OGLControllerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor redColor];
    
    NSLog(@"OGLControllerViewController viewDidLoad\n");
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    NSLog(@"OGLControllerViewController viewDidAppear\n");
    
    int width = self.view.frame.size.width;
    int height = self.view.frame.size.height;
    
    OGLView * oglView = [[OGLView alloc] initWithFrame:CGRectMake(0.0, 0.0, width, height)];
    [self.view addSubview:oglView];
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    
    NSLog(@"OGLControllerViewController viewDidDisappear\n");
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
