#include "EyerGL_IOS_Context_C_Interface.h"
#include <stdio.h>

#import <GLKit/GLKit.h>

int ios_gl_ctx_test_add(int a, int b)
{
    return a + b;
}

void * ios_gl_ctx_init(void * cLayer)
{
    CAEAGLLayer * eaglLayer = (__bridge CAEAGLLayer *)cLayer;

    EAGLContext * context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    [EAGLContext setCurrentContext:context];

    GLuint colorRenderBuffer;
    glGenRenderbuffers(1, &colorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, colorRenderBuffer);
    
    GLuint framebuffer;
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, colorRenderBuffer);
    
    [context renderbufferStorage:GL_RENDERBUFFER fromDrawable:eaglLayer];

    glClearColor(0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    [context presentRenderbuffer:GL_RENDERBUFFER];

    return NULL;
}

int ios_gl_ctx_uninit(void * ctx)
{
    return 0;
}