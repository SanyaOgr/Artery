#include "OpenGLWindow.h"

namespace opengl {

    void OpenGLWindow::SetPixelFormat(HDC deviceContext)
    {
        //// Pixel format attributes array.
        //int pixAttribs[] =
        //{
        //    WGL_SUPPORT_OPENGL_ARB,   GL_TRUE,                   // nonzero value means "support OpenGL"
        //    WGL_DRAW_TO_WINDOW_ARB,   GL_TRUE,                   // true if the pixel format can be used with a window
        //    WGL_ACCELERATION_ARB,     WGL_FULL_ACCELERATION_ARB, // hardware acceleration through ICD driver
        //    WGL_DOUBLE_BUFFER_ARB,    GL_TRUE,                   // nonzero value means "double buffering"
        //    WGL_SAMPLE_BUFFERS_ARB,   GL_TRUE,                   // support multisampling
        //    WGL_PIXEL_TYPE_ARB,       WGL_TYPE_RGBA_ARB,         // color mode (either WGL_TYPE_RGBA_ARB or WGL_TYPE_COLORINDEX_ARB)
        //    WGL_COLOR_BITS_ARB,       32,                        // bits number in the color buffer for R, G and B channels
        //    WGL_DEPTH_BITS_ARB,       24,                        // bits number in the depth buffer
        //    WGL_STENCIL_BITS_ARB,     8,                         // bits number in the stencil buffer
        //    WGL_SAMPLES_ARB,          8,                         // multisampling factor
        //    0                                                    // "end of array" symbol
        //};

        //int numFormats = 0;
        //int pixelFormat = -1;

        PIXELFORMATDESCRIPTOR pfd;

        // Find the most relevant pixel format for the specified attributes.
        int formatIndex = ChoosePixelFormat(deviceContext, &pfd);

        //wglChoosePixelFormatARB(
        //    deviceContext,       // device context
        //    &pixAttribs[0],      // list of integer attributes
        //    NULL,                // list of float attributes
        //    1,                   // the maximum number of pixel formats to be obtained
        //    &pixelFormat,        // [out] pointer to the array of pixel formats
        //    (UINT*)&numFormats); // the number of appropriate pixel formats found

        //// Throw an exception if we couldn't find an appropriate pixel format.

        if (formatIndex == 0)
            LOG("ERROR: OpenGLWindow::SetPixelFormat() -> ChoosePixelFormat()");

        // Set pixel format for the window device context.
        ::SetPixelFormat(deviceContext, formatIndex, &pfd);
    }

    void OpenGLWindow::CreateRenderingContext(HDC deviceContext)
    {
        //// Set the version that we want.
        //GLint attribs[] =
        //{
        //    WGL_CONTEXT_MAJOR_VERSION_ARB, majorVersion,
        //    WGL_CONTEXT_MINOR_VERSION_ARB, minorVersion,
        //    WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB, // core profile
        //    WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB, // compatible with future versions of OpenGL
        //    #ifdef _DEBUG
        //    WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB, // enhanced error message testing
        //    #endif
        //    0
        //};

        //// Create OpenGL rendering context.
        //m_hGLRC = wglCreateContextAttribsARB(deviceContext, 0, attribs);
        wglCreateContext(deviceContext);

        // Make the OpenGL rendering context current.
        wglMakeCurrent(deviceContext, m_hGLRC);
    }

}