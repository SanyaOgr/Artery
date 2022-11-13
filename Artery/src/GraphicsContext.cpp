#include "GraphicsContext.h"

namespace art {

	GraphicsContext::~GraphicsContext()
	{
		SetActive(false);
		delete m_platformImpl;
	}

	GraphicsContext::GraphicsContext()
		: m_platformImpl(nullptr)
	{
		Create();
		SetActive();
	}

	GraphicsContext::GraphicsContext(const Window& window)
		: m_platformImpl(nullptr)
	{
		Create(window.GetSystemHandle());
		SetActive();
	}

	void GraphicsContext::Create()
	{
		m_platformImpl = GraphicsContextImpl::Create();
	}

	void GraphicsContext::Create(SystemWindowHandle windowHandle)
	{
		m_platformImpl = GraphicsContextImpl::Create(windowHandle);
	}

	void GraphicsContext::SwapBuffers()
	{
		m_platformImpl->SwapBuffers();
	}

	void GraphicsContext::SetActive(bool active)
	{
		m_platformImpl->SetActive(active);
	}

}