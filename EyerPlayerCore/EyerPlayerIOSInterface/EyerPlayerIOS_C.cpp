#include "EyerPlayerIOS_C.h"

#include <stdio.h>

#include "EyerGLContextIOS.hpp"

void * ios_eyer_gl_ctx_init(void * cLayer, int w, int h)
{
    Eyer::EyerGLContextIOS * ctx = new Eyer::EyerGLContextIOS(cLayer);
    ctx->SetWH(w, h);
    ctx->Start();
    return (void *)ctx;
}

int ios_eyer_gl_ctx_uninit(void * _ctx)
{
    Eyer::EyerGLContextIOS * ctx = (Eyer::EyerGLContextIOS *)_ctx;
    ctx->Stop();
    delete ctx;
    return 0;
}