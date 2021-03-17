#ifndef	EYER_PLAYER_IOS_GL_CONTEXT_H
#define	EYER_PLAYER_IOS_GL_CONTEXT_H

#include "EyerGLContext/EyerGLContext.hpp"

namespace Eyer
{
    class EyerGLContextIOS : public EyerGLContextThread
    {
    public:
        EyerGLContextIOS(void * cLayer);
        
        virtual int Render();
    };
}

#endif // EYER_PLAYER_IOS_GL_CONTEXT_H