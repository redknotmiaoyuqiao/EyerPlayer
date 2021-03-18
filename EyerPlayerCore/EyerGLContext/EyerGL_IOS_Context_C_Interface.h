#ifndef EYERLIB_EYERGL_IOS_CONTEXT_C_INTERFACE_H
#define EYERLIB_EYERGL_IOS_CONTEXT_C_INTERFACE_H

int         ios_gl_ctx_test_add         (int a, int b);

void *      ios_gl_ctx_init             (void * cLayer, int * screenFramebuffer);
int         ios_gl_ctx_uninit           (void * ctx);

int         ios_gl_ctx_swapbuffer       (void * ctx);

#endif //EYERLIB_EYERGL_IOS_CONTEXT_C_INTERFACE_H
