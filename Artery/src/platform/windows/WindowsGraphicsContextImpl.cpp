#include "artpch.h"

#include "WindowsGraphicsContextImpl.h"

namespace art::platform {

	// Constructors, Destructors
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	WindowsGraphicsContextImpl::WindowsGraphicsContextImpl(SystemDeviceContextHandle deviceContext)
	{
		create(deviceContext);
	}

	WindowsGraphicsContextImpl::~WindowsGraphicsContextImpl()
	{
		if (m_glContext)
		{
			::wglDeleteContext(m_glContext);
		}
	}


	// Public Methods
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	SystemGLContextHandle WindowsGraphicsContextImpl::GetSystemGLContextHandle() const
	{
		return m_glContext;
	}

	void WindowsGraphicsContextImpl::SetCurrentDeviceContext(SystemDeviceContextHandle deviceContext)
	{
		m_attachedDeviceContext = deviceContext;
	}

	void WindowsGraphicsContextImpl::SetActive(bool current)
	{
		::wglMakeCurrent(m_attachedDeviceContext, current ? m_glContext : nullptr);
	}

	void WindowsGraphicsContextImpl::SwapBuffers()
	{
		::SwapBuffers(m_attachedDeviceContext);
	}


	// Private Methods
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void WindowsGraphicsContextImpl::create(HDC deviceContext)
	{
		m_glContext = ::wglCreateContext(deviceContext);
	}

}
