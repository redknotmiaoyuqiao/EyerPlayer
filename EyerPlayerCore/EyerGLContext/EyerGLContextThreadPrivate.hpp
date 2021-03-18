#ifndef EYERLIB_EYERGLCONTEXTTHREADPRIVATE_HPP
#define EYERLIB_EYERGLCONTEXTTHREADPRIVATE_HPP

namespace Eyer
{
    class EyerGLContextThreadPrivate
    {
    public:
        int w = 0;
        int h = 0;

#ifdef EYER_PLATFORM_ANDROID

#endif

#ifdef EYER_PLATFORM_IOS
        void * cLayer = nullptr;
        void * ctx = nullptr;
#endif

    };
}

#endif //EYERLIB_EYERGLCONTEXTTHREADPRIVATE_HPP
