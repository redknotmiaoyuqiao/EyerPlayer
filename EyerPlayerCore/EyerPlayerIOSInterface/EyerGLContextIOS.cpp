#include "EyerGLContextIOS.hpp"
#include "EyerGLContext/EyerGLTestComponent.hpp"
#include "EyerGL/EyerGL.hpp"

namespace Eyer
{
    EyerGLContextIOS::EyerGLContextIOS(void * cLayer) : EyerGLContextThread(cLayer)
    {
        
    }

    int EyerGLContextIOS::Render()
    {
        EyerGLFrameBuffer screenFrameBuffer(GetW(), GetH(), nullptr, nullptr, screenFramebuffer);
        EyerGLTestComponent testComponent;
        screenFrameBuffer.ClearColor(1.0, 1.0, 1.0, 1.0);
        screenFrameBuffer.AddComponent(&testComponent);

        while(!stopFlag){
            screenFrameBuffer.SetWH(GetW(), GetH());
            screenFrameBuffer.Clear();
            screenFrameBuffer.Draw();

            SwapBuffer();
        }
        
        return 0;
    }
}
