#include "EyerGL_IOS_Context_C_Interface.h"
#include <stdio.h>

#import <GLKit/GLKit.h>

int ios_gl_ctx_test_add(int a, int b)
{
    return a + b;
}

void * ios_gl_ctx_init(void * cLayer)
{
    // CAEAGLLayer * eaglLayer = (__bridge CAEAGLLayer *)cLayer;
    EAGLContext * context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    return NULL;
}

int ios_gl_ctx_uninit(void * ctx)
{
    return 0;
}