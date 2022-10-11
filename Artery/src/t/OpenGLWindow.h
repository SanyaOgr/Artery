#pragma once
#include <windows.h>
#include <wingdi.h>
#include <gl/GL.h>
//#include "GL/glcorearb.h"
//#include "GL/glext.h"
//#include "GL/wglext.h"
#include "GL/wgl.h"

#include "Event.h"
#include "Debug.h"

namespace opengl {

    class OpenGLWindow
    {
        using TRenderEvent = util::Event<OpenGLWindow*>;
    private:
        TRenderEvent m_renderEvent;
        HDC m_deviceContext;
        HGLRC m_hGLRC;

        void SetPixelFormat(HDC deviceContext);
        void CreateRenderingContext(HDC deviceContext);

    public:
        OpenGLWindow(HDC deviceContext)
            : m_deviceContext(deviceContext)
        {}

        TRenderEvent& RenderEvent() { return m_renderEvent; }

        void Render()
        {
            wglMakeCurrent(m_deviceContext, m_hGLRC); // make OpenGL context current
            //opengl::ClearAllBuffers(); // this utility function clears the framebuffer
            m_renderEvent(this); // generate RenderEvent (where actual drawing takes place)
            SwapBuffers(m_deviceContext); // swap back and front buffers
        }
    };

}