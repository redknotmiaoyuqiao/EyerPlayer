#include "EyerGLContext.hpp"
#include "EyerGLContextThreadPrivate.hpp"

namespace Eyer
{
    EyerGLContextThread::EyerGLContextThread(GLWindows * _nativeWindow)
    {
        impl = new EyerGLContextThreadPrivate();
        nativeWindow = _nativeWindow;
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
        return 0;
    }

    int EyerGLContextThread::Uninit()
    {
        return 0;
    }

    int EyerGLContextThread::CreateOESTexture()
    {
        return 0;
    }

    void EyerGLContextThread::Run()
    {
        EyerLog("EyerGLContextThread Start\n");

        EyerLog("EyerGLContextThread End\n");
    }

    int EyerGLContextThread::SwapBuffers()
    {
        return 0;
    }

    int EyerGLContextThread::SetWH(int _w, int _h)
    {
        w = _w;
        h = _h;
        return 0;
    }

    int EyerGLContextThread::GetW()
    {
        return w;
    }

    int EyerGLContextThread::GetH()
    {
        return h;
    }
}