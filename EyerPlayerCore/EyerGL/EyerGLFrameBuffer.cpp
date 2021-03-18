#include "EyerGL.hpp"

#include "GLHeader.h"

namespace Eyer {
    EyerGLFrameBuffer::EyerGLFrameBuffer(int w, int h, EyerGLTexture * _texture, EyerGLContext * _ctx, int _defaultFBO)
    {
        ctx = _ctx;

        defaultFBO = _defaultFBO;

        width = w;
        height = h;

        texture = _texture;
        if(texture == nullptr){
            // 使用默认 Framebuffer
            fbo = defaultFBO;
        }
        else{
#ifdef QT_EYER_GL
            ctx->glGenFramebuffers(1, &fbo);
            ctx->glBindFramebuffer(GL_FRAMEBUFFER, fbo);

            texture->SetDataRGBAChannel(nullptr, width, height);

            ctx->glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture->GL_GetTextureId(), 0);
            GLenum status = ctx->glCheckFramebufferStatus(GL_FRAMEBUFFER);

            if (status != GL_FRAMEBUFFER_COMPLETE) {
                EyerLog("GL_FRAMEBUFFER_COMPLETE Error!!!!\n");
                if(fbo != 0){
                    ctx->glDeleteFramebuffers(1, &fbo);
                    fbo = defaultFBO;
                }
            }
#else
            glGenFramebuffers(1, &fbo);
            glBindFramebuffer(GL_FRAMEBUFFER, fbo);

            texture->SetDataRGBAChannel(nullptr, width, height);

            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture->type, texture->GL_GetTextureId(), 0);
            GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

            if (status != GL_FRAMEBUFFER_COMPLETE) {
                EyerLog("GL_FRAMEBUFFER_COMPLETE Error!!!!\n");
                if(fbo != 0){
                    glDeleteFramebuffers(1, &fbo);
                    fbo = defaultFBO;
                }
            }
#endif
        }
    }

    EyerGLFrameBuffer::~EyerGLFrameBuffer()
    {
        if(fbo != 0){
#ifdef QT_EYER_GL
            ctx->glDeleteFramebuffers(1, &fbo);
#else
            glDeleteFramebuffers(1, &fbo);
#endif
            fbo = 0;
        }
        drawList.clear();
        componentList.clear();
    }

    int EyerGLFrameBuffer::SetWH(int w, int h)
    {
        width = w;
        height = h;
        return 0;
    }

    int EyerGLFrameBuffer::AddDraw(EyerGLDraw * draw)
    {
        drawList.insertBack(draw);
        return 0;
    }

    int EyerGLFrameBuffer::AddComponent(EyerGLComponent * component)
    {
        componentList.insertBack(component);
        return 0;
    }

    int EyerGLFrameBuffer::ClearAllComponent()
    {
        componentList.clear();
        return 0;
    }

    int EyerGLFrameBuffer::Draw()
    {
#ifdef QT_EYER_GL
        ctx->glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        ctx->glViewport(0, 0, width, height);
#else
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glViewport(0, 0, width, height);
#endif


        for(int i=0;i<drawList.getLength();i++){
            EyerGLDraw * drawP = nullptr;
            drawList.find(i, drawP);
            if(drawP != nullptr){
                drawP->Draw();
            }
        }

        for(int i=0;i<componentList.getLength();i++){
            EyerGLComponent * componentP = nullptr;
            componentList.find(i, componentP);
            if(componentP != nullptr){
                componentP->Viewport(width, height);
                componentP->Draw();
            }
        }

#ifdef QT_EYER_GL
        ctx->glBindFramebuffer(GL_FRAMEBUFFER, 0);
#else
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif

        return 0;
    }

    int EyerGLFrameBuffer::ClearColor(float r, float g, float b, float a)
    {
#ifdef QT_EYER_GL
        ctx->glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        ctx->glClearColor(r, g, b, a);
        ctx->glBindFramebuffer(GL_FRAMEBUFFER, 0);
#else
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glClearColor(r, g, b, a);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif

        return 0;
    }

    int EyerGLFrameBuffer::Clear()
    {
#ifdef QT_EYER_GL
        ctx->glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        ctx->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ctx->glBindFramebuffer(GL_FRAMEBUFFER, 0);
#else
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif
        return 0;
    }

    int EyerGLFrameBuffer::ReadPixel(int x, int y, int width, int height, unsigned char * data)
    {
#ifdef QT_EYER_GL
        ctx->glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        ctx->glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
        ctx->glBindFramebuffer(GL_FRAMEBUFFER, 0);
#else
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif
        return 0;
    }
}
