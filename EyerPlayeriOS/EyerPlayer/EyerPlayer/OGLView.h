#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface OGLView : UIView {
    CAEAGLLayer* _eaglLayer;
    EAGLContext* _context;
    GLuint _colorRenderBuffer;
}

@end

NS_ASSUME_NONNULL_END
