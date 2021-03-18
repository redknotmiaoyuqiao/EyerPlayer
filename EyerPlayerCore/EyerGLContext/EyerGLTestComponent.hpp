#ifndef	EYER_LIB_GL_TEST_COMPONENT_AV_H
#define	EYER_LIB_GL_TEST_COMPONENT_AV_H

#include "EyerGL/EyerGL.hpp"

namespace Eyer
{
    class EyerGLTestComponent : public EyerGLComponent
    {
    public:
        EyerGLTestComponent();
        ~EyerGLTestComponent();

        virtual int Draw();

    private:
        EyerGLDraw * draw = nullptr;
        EyerGLVAO * vao = nullptr;
    };
}

#endif //EYER_LIB_GL_TEST_COMPONENT_AV_H