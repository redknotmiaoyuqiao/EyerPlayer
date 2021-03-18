#ifndef	EYER_LIB_GL_CONTEXT_THREAD_AV_H
#define	EYER_LIB_GL_CONTEXT_THREAD_AV_H

#include "EyerThread/EyerThread.hpp"

#include "EyerGL/EyerGL.hpp"
#include "EyerGL/GLHeader.h"

namespace Eyer
{
    class EyerGLContextThreadPrivate;

    class EyerGLContextThread : public EyerThread {
    public:
        EyerGLContextThread(void * _cLayer);
        ~EyerGLContextThread();

        int Init();
        int Uninit();

        virtual void Run();
        virtual int Render() = 0;

        int SwapBuffer();

        int SetWH(int w, int h);
        int GetW();
        int GetH();
    private:
        EyerGLContextThreadPrivate * impl = nullptr;
    };
}

#endif //EYER_LIB_GL_CONTEXT_THREAD_AV_H
