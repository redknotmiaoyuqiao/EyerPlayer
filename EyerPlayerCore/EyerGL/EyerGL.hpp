#ifndef	EYER_LIB_GL_AV_H
#define	EYER_LIB_GL_AV_H

#include "EyerCore/EyerCore.hpp"
#include "EyerMath/EyerMath.hpp"
#include <vector>

#ifdef QT_EYER_PLAYER
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#else
#endif

namespace Eyer
{
    class EyerGLWindow;
    class EyerGLWindowPrivate;
    class EyerGLCMD;

    class EyerGLComponent;
    class EyerGLTextDraw;
    class EyerGLSingleTextureDraw;
    class EyerGLFrameDraw;

    class EyerGLShader;
    class EyerGLProgram;
    class EyerGLVAO;
    class EyerGLTexture;

    class _EyerGLContext
    {
    };

#ifdef QT_EYER_GL
#define EyerGLContext QOpenGLFunctions_3_3_Core
#else
#define EyerGLContext _EyerGLContext
#endif

    enum EyerGLDrawType
    {
        TRIANGLES,
        LINE,
        LINE_LOOP,
        POINT
    };

    class EyerGLCMD
    {
    public:
        virtual ~EyerGLCMD()
        {

        }
    };

    enum EyerGLShaderType
    {
        VERTEX_SHADER,
        FRAGMENT_SHADER
    };

    class EyerGLShader : public EyerGLCMD
    {
    private:
        EyerGLShaderType type = EyerGLShaderType::VERTEX_SHADER;
        EyerString src;
        unsigned int shaderId = 0;

        EyerGLContext * ctx = nullptr;
    public:
        EyerGLShader(EyerGLShaderType type, EyerString src, EyerGLContext * _ctx = nullptr);
        ~EyerGLShader();

        int Compile();

        unsigned int GL_GetShaderId();
    };

    class EyerGLProgram : public EyerGLCMD
    {
    private:
        EyerString vertexShaderSrc;
        EyerString fragmentShaderSrc;

        unsigned int programId = 0;

        EyerGLContext * ctx = nullptr;
    public:
        EyerGLProgram(EyerString vertexShaderSrc, EyerString fragmentShaderSrc, EyerGLContext * _ctx = nullptr);
        ~EyerGLProgram();
        int LinkProgram();
        int UseProgram();

        int PutUniform1i(EyerString key, int value);
        int PutMatrix4fv(EyerString key, EatrixF4x4 & mat);
        int PutMatrix3fv(EyerString key, EatrixF3x3 & mat);
        int PutUniform1f(EyerString key, float value);
    };

    class EyerGLVAO : public EyerGLCMD
    {
    private:
        unsigned int VAOId = 0;
        unsigned int EBOId = 0;
        std::vector<unsigned int> vboList;

        int DrawTime = 0;

        EyerGLContext * ctx = nullptr;
    public:
        EyerGLVAO(EyerGLContext * ctx = nullptr);
        ~EyerGLVAO();

        int SetEBO(unsigned int * EBOdata, int bufferSize);
        int AddVBO(float * VBOdata, int bufferSize, int layout, int size = 3, unsigned int stride = 0);

        int DrawVAO(EyerGLDrawType drawType);
    };

    class EyerGLDrawTexture
    {
    public:
        EyerString uniformName;
        EyerGLTexture * texture = nullptr;
    };

    class EyerGLDraw : public EyerGLCMD
    {
    private:
        EyerString vertexShaderSrc;
        EyerString fragmentShaderSrc;

        EyerGLProgram * program = nullptr;
        EyerGLVAO * vao = nullptr;

        EyerGLContext * ctx = nullptr;
    public:
        EyerGLDraw(EyerString vertexShaderSrc, EyerString fragmentShaderSrc, EyerGLContext * ctx = nullptr);
        ~EyerGLDraw();

        int Init();

        int SetVAO(EyerGLVAO * vao);
        int PutTexture(EyerString uniform, EyerGLTexture * texture, int textureIndex = 0);
        int PutMatrix4fv(EyerString uniform, EatrixF4x4 & mat);
        int PutMatrix3fv(EyerString uniform, EatrixF3x3 & mat);
        int PutUniform1f(EyerString uniform, float val);
        int PutUniform1i(EyerString uniform, int val);

        int Draw(EyerGLDrawType drawType = EyerGLDrawType::TRIANGLES);
    };

    enum EyerGLTextureType
    {
        EYER_GL_TEXTURE_2D = 1,
        EYER_GL_TEXTURE_EXTERNAL_OES = 2
    };

    class EyerGLTexture : public EyerGLCMD
    {
    private:
        unsigned int textureId = 0;
        EyerGLContext * ctx = nullptr;

    public:
        int type = -1;
    public:
        EyerGLTexture(EyerGLTextureType textureType = EyerGLTextureType::EYER_GL_TEXTURE_2D, EyerGLContext * ctx = nullptr);
        ~EyerGLTexture();

        unsigned int GL_GetTextureId();

        int SetDataRedChannel   (unsigned char * data,int width,int height);
        int SetDataRGChannel    (unsigned char * data,int width,int height);
        int SetDataRGBAChannel  (unsigned char * data,int width,int height);
    };

    class EyerGLFrameBuffer : public EyerGLCMD
    {
    private:
        EyerLinkedList<EyerGLDraw *> drawList;
        EyerLinkedList<EyerGLComponent *> componentList;

        unsigned int fbo = 0;

        int defaultFBO = 0;

        int width = 0;
        int height = 0;

        EyerGLTexture * texture = nullptr;
        EyerGLContext * ctx = nullptr;
    public:
        EyerGLFrameBuffer(int w, int h, EyerGLTexture * texture = nullptr, EyerGLContext * ctx = nullptr, int defaultFBO = 0);
        ~EyerGLFrameBuffer();

        int SetWH(int w, int h);

        int AddDraw(EyerGLDraw * draw);
        int AddComponent(EyerGLComponent * component);
        int ClearAllComponent();

        int ClearColor(float r, float g, float b, float a);
        int Clear();

        int Draw();

        int ReadPixel(int x, int y, int width, int height, unsigned char * data);
    };


    class EyerGLComponent
    {
    public:

    public:
        virtual ~EyerGLComponent();

        virtual int Draw() = 0;

        int Viewport(int w, int h);

        int SetVP(EatrixF4x4 & _vpMat);

        int SetModel(EectorF3 & _p, EectorF4 & _r, EectorF3 & _s);

        int SetColor(EectorF4 & _color);

    public:
        int width = 0;
        int height = 0;

        EatrixF4x4 vpMat;
        EatrixF4x4 modelMat;
        EectorF3 p;
        EectorF3 r;
        EectorF3 s;
        EectorF4 color;
    };

    class EyerGLRenderTask
    {
    public:
        EyerGLRenderTask();
        virtual ~EyerGLRenderTask();

        int SetWH(int w, int h);

        // 外部只能复写，不能调用
        virtual int Render() = 0;
        virtual int Init() = 0;
        virtual int Destory() = 0;

    public:
        int w = 0;
        int h = 0;
    };

    class EyerGLRenderTaskQueue
    {
    public:
        EyerGLRenderTaskQueue();
        ~EyerGLRenderTaskQueue();

        int GetSize();

        int PushRendTask(EyerGLRenderTask * renderTask);
        int PopAndRender(int w, int h);
        int PopAndRenderAndFree(int w, int h);

        int PopAndFree();
    private:
        EyerLockQueue<EyerGLRenderTask> taskQueue;
    };
}

#endif
