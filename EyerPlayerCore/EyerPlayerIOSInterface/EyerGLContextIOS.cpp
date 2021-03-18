#include "EyerGLContextIOS.hpp"
#include "EyerGLCOntext/EyerGLTestComponent.hpp"

namespace Eyer
{
    EyerGLContextIOS::EyerGLContextIOS(void * cLayer) : EyerGLContextThread(cLayer)
    {
        
    }

    int EyerGLContextIOS::Render()
    {
        EyerGLTestComponent testComponent;
        // testComponent.SetWH(200, 200);

        while(!stopFlag){
            glViewport(0, 0, 320, 568);
            glClearColor(0, 1.0, 1.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);
            testComponent.Draw();
            SwapBuffer();
        }
        
        return 0;
    }
}
