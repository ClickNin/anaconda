#ifndef INCLUDE_GL_H
#define INCLUDE_GL_H

#ifdef CHOWDREN_IS_DESKTOP

#ifdef CHOWDREN_USE_GL
#include <SDL_opengl.h>

extern PFNGLBLENDEQUATIONSEPARATEEXTPROC __glBlendEquationSeparateEXT;
extern PFNGLBLENDEQUATIONEXTPROC __glBlendEquationEXT;
extern PFNGLBLENDFUNCSEPARATEEXTPROC __glBlendFuncSeparateEXT;
extern PFNGLACTIVETEXTUREARBPROC __glActiveTextureARB;
extern PFNGLCLIENTACTIVETEXTUREARBPROC __glClientActiveTextureARB;
extern PFNGLGENFRAMEBUFFERSEXTPROC __glGenFramebuffersEXT;
extern PFNGLFRAMEBUFFERTEXTURE2DEXTPROC __glFramebufferTexture2DEXT;
extern PFNGLBINDFRAMEBUFFEREXTPROC __glBindFramebufferEXT;
extern PFNGLUSEPROGRAMPROC __glUseProgram;
extern PFNGLDETACHSHADERPROC __glDetachShader;
extern PFNGLGETPROGRAMINFOLOGPROC __glGetProgramInfoLog;
extern PFNGLGETPROGRAMIVPROC __glGetProgramiv;
extern PFNGLLINKPROGRAMPROC __glLinkProgram;
extern PFNGLCREATEPROGRAMPROC __glCreateProgram;
extern PFNGLATTACHSHADERPROC __glAttachShader;
extern PFNGLGETSHADERINFOLOGPROC __glGetShaderInfoLog;
extern PFNGLGETSHADERIVPROC __glGetShaderiv;
extern PFNGLCOMPILESHADERPROC __glCompileShader;
extern PFNGLSHADERSOURCEPROC __glShaderSource;
extern PFNGLCREATESHADERPROC __glCreateShader;
extern PFNGLUNIFORM1IPROC __glUniform1i;
extern PFNGLUNIFORM2FPROC __glUniform2f;
extern PFNGLUNIFORM1FPROC __glUniform1f;
extern PFNGLUNIFORM4FPROC __glUniform4f;
extern PFNGLGETUNIFORMLOCATIONPROC __glGetUniformLocation;

#define glBlendEquation __glBlendEquationEXT
#define glBlendEquationSeparate __glBlendEquationSeparateEXT
#define glBlendFuncSeparate __glBlendFuncSeparateEXT
#define glActiveTexture __glActiveTextureARB
#define glClientActiveTexture __glClientActiveTextureARB
#define glGenFramebuffers __glGenFramebuffersEXT
#define glBindFramebuffer __glBindFramebufferEXT
#define glFramebufferTexture2D __glFramebufferTexture2DEXT
#define glUseProgram __glUseProgram
#define glDetachShader __glDetachShader
#define glGetProgramInfoLog __glGetProgramInfoLog
#define glGetProgramiv __glGetProgramiv
#define glLinkProgram __glLinkProgram
#define glCreateProgram __glCreateProgram
#define glAttachShader __glAttachShader
#define glGetShaderInfoLog __glGetShaderInfoLog
#define glGetShaderiv __glGetShaderiv
#define glCompileShader __glCompileShader
#define glShaderSource __glShaderSource
#define glCreateShader __glCreateShader
#define glUniform1i __glUniform1i
#define glUniform2f __glUniform2f
#define glUniform1f __glUniform1f
#define glUniform4f __glUniform4f
#define glGetUniformLocation __glGetUniformLocation

#elif CHOWDREN_USE_GLES1
#include <SDL_opengles.h>

#elif CHOWDREN_USE_GLES2
#include <SDL_opengles2.h>

#endif // CHOWDREN_USE_GL

#endif // CHOWDREN_IS_DESKTOP

#endif // INCLUDE_GL_H
