#include "WindowsGraphicsContextImpl.h"

#include <glad/glad.h>

namespace art::platform {

	// Constructors, Destructors
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	WindowsGraphicsContextImpl::WindowsGraphicsContextImpl()
		: m_attachedWindow(NULL), m_deviceContext(NULL), m_glContext(NULL)
	{
	}

	WindowsGraphicsContextImpl::WindowsGraphicsContextImpl(SystemWindowHandle windowHandle)
		: WindowsGraphicsContextImpl()
	{
		//initGLAD();
		createSurface(windowHandle);
	}

	WindowsGraphicsContextImpl::~WindowsGraphicsContextImpl()
	{
		if (m_glContext)
		{
			::wglMakeCurrent(m_deviceContext, nullptr);
			::wglDeleteContext(m_glContext);
		}

		if (m_deviceContext)
		{
			::ReleaseDC(m_attachedWindow, m_deviceContext);
		}
	}

	// Public Methods
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void WindowsGraphicsContextImpl::SetActive(bool active)
	{
		if (active)
		{
			::wglMakeCurrent(m_deviceContext, m_glContext);
		}
		else
		{
			::wglMakeCurrent(m_deviceContext, nullptr);
		}
	}

	void WindowsGraphicsContextImpl::SwapBuffers()
	{
		::SwapBuffers(m_deviceContext);
	}

	// Private Methods
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void WindowsGraphicsContextImpl::createSurface(HWND window)
	{
		m_deviceContext = ::GetDC(window);

		PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
			PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
			32,                   // Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                   // Number of bits for the depthbuffer
			8,                    // Number of bits for the stencilbuffer
			0,                    // Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		int bestFormat = ::ChoosePixelFormat(m_deviceContext, &pfd);
		::SetPixelFormat(m_deviceContext, bestFormat, &pfd);

		m_glContext = ::wglCreateContext(m_deviceContext);

		// wglMakeCurrent ?
	}

	void WindowsGraphicsContextImpl::initGLAD()
	{
		static bool initialized = false;
		if (!initialized)
		{
			initialized = true;
			gladLoadGL();
		}
	}

}
