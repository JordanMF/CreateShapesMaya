//
//  GLCP.h
//  ReflectionLocator
//
//  Created by Jordan Issa on 12/01/2017.
//
//

#ifndef GLCP_h
#define GLCP_h

#if defined (OSMac_)
    #define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
    #include <OpenGL/gl3.h> // For gl*VertexArray(s) and APIENTRY
#endif // OSMac_

class GLCP
{
public:
    // For more extensive OpenGL coding you will definitively want to
    // use a good extension loader framework. I recommend looking at:
    // https://www.opengl.org/wiki/OpenGL_Loading_Library
    // to find the one that will fit your needs the best.
    // Also note that MGLFunctionTable stops at GL 2.1, so a lot
    // of functions will be missing.
    
#if !defined (OSMac_)
    typedef char GLchar;
    typedef ptrdiff_t GLsizeiptr;
#endif
    
    typedef void (APIENTRY *Tp_glBindVertexArray) (GLuint array);
    static Tp_glBindVertexArray BindVertexArray;
    
    typedef void (APIENTRY *Tp_glGenVertexArrays) (GLsizei n, GLuint *arrays);
    static Tp_glGenVertexArrays GenVertexArrays;
    
    typedef void (APIENTRY *Tp_glDeleteVertexArrays ) (GLsizei n, const GLuint *arrays);
    static Tp_glDeleteVertexArrays DeleteVertexArrays;
    
    typedef void (APIENTRY *Tp_glUniform4f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    static Tp_glUniform4f Uniform4f;
    
    typedef void (APIENTRY *Tp_glUniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    static Tp_glUniformMatrix4fv UniformMatrix4fv;
    
    typedef GLint (APIENTRY *Tp_glGetUniformLocation) (GLuint program, const GLchar *name);
    static Tp_glGetUniformLocation GetUniformLocation;
    
    typedef GLint (APIENTRY *Tp_glGetAttribLocation) (GLuint program, const GLchar *name);
    static Tp_glGetAttribLocation GetAttribLocation;
    
    typedef GLuint (APIENTRY *Tp_glCreateShader ) (GLenum type);
    static Tp_glCreateShader CreateShader;
    
    typedef void (APIENTRY *Tp_glShaderSource ) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
    static Tp_glShaderSource ShaderSource;
    
    typedef void (APIENTRY *Tp_glCompileShader ) (GLuint shader);
    static Tp_glCompileShader CompileShader;
    
    typedef void (APIENTRY *Tp_glGetShaderiv ) (GLuint shader, GLenum pname, GLint *params);
    static Tp_glGetShaderiv GetShaderiv;
    
    typedef void (APIENTRY *Tp_glGetShaderInfoLog ) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    static Tp_glGetShaderInfoLog GetShaderInfoLog;
    
    typedef GLuint (APIENTRY *Tp_glCreateProgram ) ();
    static Tp_glCreateProgram CreateProgram;
    
    typedef void (APIENTRY *Tp_glAttachShader ) (GLuint program, GLuint shader);
    static Tp_glAttachShader AttachShader;
    
    typedef void (APIENTRY *Tp_glDeleteShader ) (GLuint shader);
    static Tp_glDeleteShader DeleteShader;
    
    typedef void (APIENTRY *Tp_glLinkProgram ) (GLuint program);
    static Tp_glLinkProgram LinkProgram;
    
    typedef void (APIENTRY *Tp_glGetProgramiv ) (GLuint program, GLenum pname, GLint *params);
    static Tp_glGetProgramiv GetProgramiv;
    
    typedef void (APIENTRY *Tp_glUseProgram ) (GLuint program);
    static Tp_glUseProgram UseProgram;
    
    typedef void (APIENTRY *Tp_glDeleteProgram ) (GLuint program);
    static Tp_glDeleteProgram DeleteProgram;
    
    typedef void (APIENTRY *Tp_glGetProgramInfoLog ) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    static Tp_glGetProgramInfoLog GetProgramInfoLog;
    
    typedef void (APIENTRY *Tp_glGenBuffers ) (GLsizei n, GLuint *buffers);
    static Tp_glGenBuffers GenBuffers;
    
    typedef void (APIENTRY *Tp_glDeleteBuffers ) (GLsizei n, const GLuint *buffers);
    static Tp_glDeleteBuffers DeleteBuffers;
    
    typedef void (APIENTRY *Tp_glBindBuffer ) (GLenum target, GLuint buffer);
    static Tp_glBindBuffer BindBuffer;
    
    typedef void (APIENTRY *Tp_glBufferData ) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
    static Tp_glBufferData BufferData;
    
    typedef void (APIENTRY *Tp_glEnableVertexAttribArray ) (GLuint index);
    static Tp_glEnableVertexAttribArray EnableVertexAttribArray;
    
    typedef void (APIENTRY *Tp_glVertexAttribPointer ) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
    static Tp_glVertexAttribPointer VertexAttribPointer;
    
    static void initGLFunctionsCoreProfile();
};

GLCP::Tp_glBindVertexArray GLCP::BindVertexArray = 0;
GLCP::Tp_glGenVertexArrays GLCP::GenVertexArrays = 0;
GLCP::Tp_glDeleteVertexArrays GLCP::DeleteVertexArrays = 0;
GLCP::Tp_glUniform4f GLCP::Uniform4f = 0;
GLCP::Tp_glUniformMatrix4fv GLCP::UniformMatrix4fv = 0;
GLCP::Tp_glGetUniformLocation GLCP::GetUniformLocation = 0;
GLCP::Tp_glGetAttribLocation GLCP::GetAttribLocation = 0;
GLCP::Tp_glCreateShader GLCP::CreateShader = 0;
GLCP::Tp_glShaderSource GLCP::ShaderSource = 0;
GLCP::Tp_glCompileShader GLCP::CompileShader = 0;
GLCP::Tp_glGetShaderiv GLCP::GetShaderiv = 0;
GLCP::Tp_glGetShaderInfoLog GLCP::GetShaderInfoLog = 0;
GLCP::Tp_glCreateProgram GLCP::CreateProgram = 0;
GLCP::Tp_glAttachShader GLCP::AttachShader = 0;
GLCP::Tp_glDeleteShader GLCP::DeleteShader = 0;
GLCP::Tp_glLinkProgram GLCP::LinkProgram = 0;
GLCP::Tp_glGetProgramiv GLCP::GetProgramiv = 0;
GLCP::Tp_glUseProgram GLCP::UseProgram = 0;
GLCP::Tp_glDeleteProgram GLCP::DeleteProgram = 0;
GLCP::Tp_glGetProgramInfoLog GLCP::GetProgramInfoLog = 0;
GLCP::Tp_glGenBuffers GLCP::GenBuffers = 0;
GLCP::Tp_glDeleteBuffers GLCP::DeleteBuffers = 0;
GLCP::Tp_glBindBuffer GLCP::BindBuffer = 0;
GLCP::Tp_glBufferData GLCP::BufferData = 0;
GLCP::Tp_glEnableVertexAttribArray GLCP::EnableVertexAttribArray = 0;
GLCP::Tp_glVertexAttribPointer GLCP::VertexAttribPointer = 0;

void GLCP::initGLFunctionsCoreProfile()
{
#if defined (OSMac_)
#define INIT_GLPOINTER(funcName) funcName = gl##funcName
#elif defined (_WIN32)
#define INIT_GLPOINTER(funcName) if (!funcName) funcName = (Tp_gl##funcName)wglGetProcAddress("gl" #funcName)
#else
#define INIT_GLPOINTER(funcName) if (!funcName) funcName = (Tp_gl##funcName)::glXGetProcAddressARB((const GLubyte*)"gl" #funcName)
#endif
    
    INIT_GLPOINTER(BindVertexArray);
    INIT_GLPOINTER(GenVertexArrays);
    INIT_GLPOINTER(DeleteVertexArrays);
    INIT_GLPOINTER(Uniform4f);
    INIT_GLPOINTER(UniformMatrix4fv);
    INIT_GLPOINTER(GetUniformLocation);
    INIT_GLPOINTER(GetAttribLocation);
    INIT_GLPOINTER(CreateShader);
    INIT_GLPOINTER(ShaderSource);
    INIT_GLPOINTER(CompileShader);
    INIT_GLPOINTER(GetShaderiv);
    INIT_GLPOINTER(GetShaderInfoLog);
    INIT_GLPOINTER(CreateProgram);
    INIT_GLPOINTER(AttachShader);
    INIT_GLPOINTER(DeleteShader);
    INIT_GLPOINTER(LinkProgram);
    INIT_GLPOINTER(GetProgramiv);
    INIT_GLPOINTER(UseProgram);
    INIT_GLPOINTER(DeleteProgram);
    INIT_GLPOINTER(GetProgramInfoLog);
    INIT_GLPOINTER(GenBuffers);
    INIT_GLPOINTER(DeleteBuffers);
    INIT_GLPOINTER(BindBuffer);
    INIT_GLPOINTER(BufferData);
    INIT_GLPOINTER(EnableVertexAttribArray);
    INIT_GLPOINTER(VertexAttribPointer);
    
#undef INIT_GLPOINTER
}

#if !defined (OSMac_)
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_STATIC_DRAW                    0x88E4
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_INFO_LOG_LENGTH                0x8B84
#endif

#endif /* GLCP_h */
