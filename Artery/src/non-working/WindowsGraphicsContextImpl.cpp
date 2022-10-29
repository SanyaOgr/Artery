#include "WindowsGraphicsContextImpl.h"

namespace art::platform::win {

	// Constructors, Destructors
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	WindowsGraphicsContextImpl::WindowsGraphicsContextImpl(PlatformWindowHandle windowHandle)
	{
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

		//if (m_attachedWindow)
		//	DestroyWindow(m_attachedWindow);
	}

	// Public Methods
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void WindowsGraphicsContextImpl::MakeCurrent(bool current)
	{
		if (current)
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

}
