#include "EyerGLContextThread.hpp"
#include "EyerGLContextThreadPrivate.hpp"

#include "EyerGL_IOS_Context_C_Interface.h"

namespace Eyer
{
    EyerGLContextThread::EyerGLContextThread()
    {
        impl = new EyerGLContextThreadPrivate();
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
        ios_gl_ctx_init(NULL);
        return 0;
    }

    int EyerGLContextThread::Uninit()
    {
        return 0;
    }

    void EyerGLContextThread::Run()
    {
        EyerLog("EyerGLContextThread Start\n");
        Init();
        Render();
        Uninit();
        EyerLog("EyerGLContextThread End\n");
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