#import "OGLView.h"

#import <GLKit/GLKit.h>
#include "OGLContext.hpp"
#include "EyerPlayerIOSInterface/EyerPlayerIOS_C.h"

@implementation OGLView

+ (Class)layerClass {
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame
{
    NSLog(@"initWithFrame: (%f, %f, %f, %f)\n", frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
    self = [super initWithFrame:frame];
    if (self) {
        [self setupLayer];
        
        int width = (int)frame.size.width;
        int height = (int)frame.size.height;
        
        void * cLayer = (__bridge void *)self.layer;
        void * ctx = ios_eyer_gl_ctx_init(cLayer, width, height);
    }
    return self;
}

- (void)setupLayer {
    _eaglLayer = (CAEAGLLayer*) self.layer;
    _eaglLayer.opaque = YES;
}

@end
