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
        const EGLint attrib_config_list[] = {
                EGL_RENDERABLE_TYPE,    EGL_OPENGL_ES3_BIT,
                EGL_SURFACE_TYPE,       EGL_WINDOW_BIT | EGL_PBUFFER_BIT,
                EGL_BLUE_SIZE,          8,
                EGL_GREEN_SIZE,         8,
                EGL_RED_SIZE,           8,
                EGL_ALPHA_SIZE,         8,
                EGL_NONE
        };

        const EGLint attrib_ctx_list[] = {
                EGL_CONTEXT_CLIENT_VERSION, 3,
                EGL_NONE
        };

        EGLint num_config;

        impl->mEglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (impl->mEglDisplay == EGL_NO_DISPLAY) {
            SvLog("eglGetDisplay error\n");
            SvLog("SvGLContextThread End\n");
            return -1;
        }
        if (!eglInitialize(impl->mEglDisplay, 0, 0)) {
            SvLog("eglInitialize() returned error %d\n", eglGetError());
            SvLog("SvGLContextThread End\n");
            return -1;
        }

        if (!eglChooseConfig(impl->mEglDisplay, attrib_config_list, &impl->eglConfig, 1, &num_config)) {
            SvLog("eglChooseConfig error\n");
            SvLog("SvGLContextThread End\n");
            return -1;
        }

        impl->mEglContext = eglCreateContext(impl->mEglDisplay, impl->eglConfig, NULL, attrib_ctx_list);
        if (impl->mEglContext == EGL_NO_CONTEXT) {
            SvLog("eglCreateContext error %d\n", eglGetError());
            SvLog("SvGLContextThread End\n");
            return -1;
        }

        impl->window = eglCreateWindowSurface(impl->mEglDisplay, impl->eglConfig, nativeWindow, NULL);
        if(impl->window == EGL_NO_SURFACE) {
            SvLog("eglCreateWindowSurface error %d\n", eglGetError());
            SvLog("SvGLContextThread End\n");
            return -1;
        }

        eglMakeCurrent(impl->mEglDisplay, impl->window, impl->window, impl->mEglContext);

        return 0;
    }

    int EyerGLContextThread::CreateOESTexture()
    {
        return 0;
    }

    int EyerGLContextThread::Uninit()
    {
        eglMakeCurrent(impl->mEglDisplay, impl->window, impl->window, impl->mEglContext);

        eglDestroySurface(impl->mEglDisplay, impl->window);
        eglDestroyContext(impl->mEglDisplay, impl->mEglContext);
        eglTerminate(impl->mEglDisplay);

        return 0;
    }

    void EyerGLContextThread::Run()
    {
        EyerLog("EyerGLContextThread Start\n");

        eglMakeCurrent(impl->mEglDisplay, impl->window, impl->window, impl->mEglContext);

        glClearColor(0.0, 0.0, 0.0, 1.0);
        Render();

        EyerLog("EyerGLContextThread End\n");
    }

    int EyerGLContextThread::SwapBuffers()
    {
        eglSwapBuffers(impl->mEglDisplay, impl->window);
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