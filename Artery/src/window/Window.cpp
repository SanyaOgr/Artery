#include "Window.h"
#include <iostream>

namespace art {

	Window::Window(const WindowSettings& settings)
	{
		m_platformImpl = WindowImpl::CreatePlatformImpl(settings);
		m_platformImpl->SetVisible(true);
	}

	Window::~Window()
	{
	}

	void Window::SetVisible(bool visible)
	{
		m_platformImpl->SetVisible(visible);
	}

	void Window::OnUpdate()
	{
		m_platformImpl->ProcessEvents();
	}

	void Window::SetEventCallback(const EventCallbackFn& callback)
	{
		m_platformImpl->SetEventCallback(callback);
	}

	uint32_t Window::GetWidth() const
	{
		return m_platformImpl->GetWidth();
	}

	uint32_t Window::GetHeight() const
	{
		return m_platformImpl->GetHeight();
	}

	SystemWindowHandle Window::GetSystemHandle() const
	{
		return m_platformImpl->GetSystemHandle();
	}

	SystemDeviceContextHandle Window::GetSystemDeviceContextHandle() const
	{
		return m_platformImpl->GetSystemDeviceContextHandle();
	}

}
