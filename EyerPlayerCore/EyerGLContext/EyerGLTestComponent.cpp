#include "EyerGLTestComponent.hpp"

#include "EyerGL/GLHeader.h"

namespace Eyer
{
    EyerGLTestComponent::EyerGLTestComponent()
    {
        float vertex[] = {
                1.0, 1.0, 0.0,
                1.0, -1.0, 0.0,
                -1.0, -1.0, 0.0,
                -1.0, 1.0, 0.0
        };
        float coor[] = {
                1.0, 1.0, 0.0,
                1.0, 0.0, 0.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0
        };
        unsigned int vertexIndex[] = {
                0, 1, 2,
                0, 2, 3
        };

        const char * VERTEX_SHADER = (char *)EYER_GL_SHADER(
            \#version 300 es\n
            precision highp float;\n
            layout (location = 0) in vec3 pos;
            layout (location = 1) in vec3 coor;

            out vec2 outCoor;

            void main(){
                outCoor = vec2(coor.x, coor.y);
                gl_Position = vec4(pos * 1.0, 1.0);
            }
        );

        const char * FRAGMENT_SHADER = (char *)EYER_GL_SHADER(
            \#version 300 es\n
            precision highp float;\n

            out vec4 color;
            in vec2 outCoor;

            void main()
            {
                color = vec4(outCoor, 1.0, 1.0);
            }
        );

        draw = new EyerGLDraw(VERTEX_SHADER, FRAGMENT_SHADER);
        draw->Init();

        vao = new EyerGLVAO();

        vao->AddVBO(vertex, sizeof(vertex), 0);
        vao->AddVBO(coor, sizeof(coor), 1);
        vao->SetEBO(vertexIndex, sizeof(vertexIndex));

        draw->SetVAO(vao);   
    }

    EyerGLTestComponent::~EyerGLTestComponent()
    {
        if(draw != nullptr){
            delete draw;
            draw = nullptr;
        }
        if(vao != nullptr){
            delete vao;
            vao = nullptr;
        }
    }

    int EyerGLTestComponent::Draw()
    {
        draw->Draw();
        return 0;
    }
}