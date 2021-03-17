#include "OGLContext_C_Interface.h"
#include <stdio.h>

#import <GLKit/GLKit.h>

void * gl_ctx_init(void * cLayer)
{
    CAEAGLLayer * eaglLayer = (__bridge CAEAGLLayer *)cLayer;
    
    printf("gl_ctx_init\n");
    EAGLContext * context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    [EAGLContext setCurrentContext:context];
    
    GLuint colorRenderBuffer;
    
    glGenRenderbuffers(1, &colorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, colorRenderBuffer);
    [context renderbufferStorage:GL_RENDERBUFFER fromDrawable:eaglLayer];
    
    GLuint framebuffer;
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, colorRenderBuffer);
    
    glClearColor(0, 104.0/255.0, 55.0/255.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    [context presentRenderbuffer:GL_RENDERBUFFER];
    
    return NULL;
}

int gl_ctx_uninit(void * ctx)
{
    printf("gl_ctx_uninit\n");
    return 0;
}
