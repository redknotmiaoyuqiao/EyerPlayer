#include "OGLContext.hpp"
#include "OGLContext_C_Interface.h"

OGLContext::OGLContext(void * cLayer)
{
    void * ctx = gl_ctx_init(cLayer);
    gl_ctx_uninit(ctx);
}

OGLContext::~OGLContext()
{
    
}
