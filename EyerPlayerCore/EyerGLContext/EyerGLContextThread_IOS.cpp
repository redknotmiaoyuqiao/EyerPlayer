#include "EyerGLContextThread.hpp"
#include "EyerGLContextThreadPrivate.hpp"

#include "EyerGL_IOS_Context_C_Interface.h"

namespace Eyer
{
    EyerGLContextThread::EyerGLContextThread(void * _cLayer)
    {
        impl = new EyerGLContextThreadPrivate();
        impl->cLayer = _cLayer;
    }

    EyerGLContextThread::~EyerGLContextThread()
    {
        if(impl != nullptr){
            delete impl;
            impl = nullptr;
        }
    }

    int EyerGLContextThread::Init()
    {
        impl->ctx = ios_gl_ctx_init(impl->cLayer);
        return 0;
    }

    int EyerGLContextThread::Uninit()
    {
        return ios_gl_ctx_uninit(impl->ctx);
    }

    void EyerGLContextThread::Run()
    {
        EyerLog("EyerGLContextThread Start\n");
        Init();
        Render();
        Uninit();
        EyerLog("EyerGLContextThread End\n");
    }

    int EyerGLContextThread::SwapBuffer()
    {
        return ios_gl_ctx_swapbuffer(impl->ctx);
    }

    int EyerGLContextThread::SetWH(int w, int h)
    {
        impl->w = w;
        impl->h = h;
        return 0;
    }

    int EyerGLContextThread::GetW()
    {
        return impl->w;
    }

    int EyerGLContextThread::GetH()
    {
        return impl->h;
    }
}