#include "artpch.h"
#include "GraphicsContext.h"

namespace art {

	GraphicsContext::~GraphicsContext()
	{
	}

	GraphicsContext::GraphicsContext(const Window& window)
	{
		m_platformImpl = GraphicsContextImpl::CreatePlatformImpl(window.GetSystemDeviceContextHandle());
	}

	SystemGLContextHandle GraphicsContext::GetSystemGLContextHandle() const
	{
		return m_platformImpl->GetSystemGLContextHandle();
	}

	void GraphicsContext::SwapBuffers()
	{
		m_platformImpl->SwapBuffers();
	}

	void GraphicsContext::SetCurrentDeviceContext(SystemDeviceContextHandle deviceContext)
	{
		m_platformImpl->SetCurrentDeviceContext(deviceContext);
	}

	void GraphicsContext::SetActive(bool current)
	{
		m_platformImpl->SetActive(current);
	}

}