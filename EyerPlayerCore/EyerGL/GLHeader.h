#ifndef EYE_LIB_GLHEADER_H
#define EYE_LIB_GLHEADER_H

#define	EYER_STRINGIZE(x)	#x
#define	EYER_GL_SHADER(shader) "" EYER_STRINGIZE(shader)

#ifdef EYER_PLATFORM_ANDROID

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES2/gl2platform.h>

#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#include <GLES3/gl3platform.h>

#endif



#ifdef EYER_PLATFORM_IOS

#import <OpenGLES/gltypes.h>
#import <OpenGLES/ES3/gl.h>
#import <OpenGLES/ES3/glext.h>

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#endif

#endif //EYE_LIB_GLHEADER_H
