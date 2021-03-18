#include "EyerGL.hpp"

#include "GLHeader.h"

namespace Eyer
{
    EyerGLTexture::EyerGLTexture(EyerGLTextureType textureType, EyerGLContext * _ctx)
    {
        if(textureType == EyerGLTextureType::EYER_GL_TEXTURE_2D) {
            type = GL_TEXTURE_2D;
        }
        else if(textureType == EyerGLTextureType::EYER_GL_TEXTURE_EXTERNAL_OES) {
#ifdef SV_PLATFORM_ANDROID
            type = GL_TEXTURE_EXTERNAL_OES;
#else
            type = GL_TEXTURE_2D;
#endif
        }

        ctx = _ctx;

#ifdef QT_EYER_GL
        ctx->glGenTextures(1, &textureId);

        ctx->glBindTexture(type, textureId);
        ctx->glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        ctx->glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        ctx->glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        ctx->glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        ctx->glBindTexture(type, 0);
#else
        glGenTextures(1, &textureId);

        glBindTexture(type, textureId);
        glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(type, 0);
#endif
    }

    EyerGLTexture::~EyerGLTexture()
    {
        if(textureId != 0){
#ifdef QT_EYER_GL
            ctx->glDeleteTextures(1, &textureId);
#else
            glDeleteTextures(1, &textureId);
#endif
            textureId = 0;
        }
    }

    unsigned int EyerGLTexture::GL_GetTextureId()
    {
        return textureId;
    }

    int EyerGLTexture::SetDataRedChannel(unsigned char * data,int width,int height)
    {
#ifdef QT_EYER_GL
        ctx->glBindTexture(type, textureId);
        ctx->glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        ctx->glTexImage2D(type, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
        ctx->glBindTexture(type, 0);
#else
        glBindTexture(type, textureId);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(type, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
        glBindTexture(type, 0);
#endif
        return 0;
    }

    int EyerGLTexture::SetDataRGBAChannel(unsigned char * data,int width,int height)
    {
#ifdef QT_EYER_GL
        ctx->glBindTexture(type, textureId);
        ctx->glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        ctx->glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        ctx->glBindTexture(type, 0);
#else
        glBindTexture(type, textureId);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glBindTexture(type, 0);
#endif

        return 0;
    }

    int EyerGLTexture::SetDataRGChannel(unsigned char * data,int width,int height)
    {
#ifdef QT_EYER_GL
        ctx->glBindTexture(type, textureId);
        ctx->glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        ctx->glTexImage2D(type, 0, GL_RG, width, height, 0, GL_RG, GL_UNSIGNED_BYTE, data);
        ctx->glBindTexture(type, 0);
#else
        glBindTexture(type, textureId);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(type, 0, GL_RG, width, height, 0, GL_RG, GL_UNSIGNED_BYTE, data);
        glBindTexture(type, 0);
#endif

        return 0;
    }
}
