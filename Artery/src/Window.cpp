#include "Window.h"
#include <iostream>

namespace art {

	Window::Window()
		: m_platformImpl(nullptr)
	{
	}

	Window::Window(int width, int height, const std::string& title)
	{
		Create(width, height, title);
		m_platformImpl->SetVisible(true);
	}

	Window::~Window()
	{
		delete m_platformImpl;
	}

	void Window::Create(int width, int height, const std::string& title)
	{
		m_platformImpl = WindowImpl::Create(width, height, title);
	}

	void Window::SetVisible(bool visible)
	{
		m_platformImpl->SetVisible(visible);
	}

	void Window::Update()
	{
		m_platformImpl->ProcessEvents();
	}

	void Window::SetEventCallback(const WindowImpl::EventCallbackFn& callback)
	{
		m_platformImpl->SetEventCallback(callback);
	}

	SystemWindowHandle Window::GetSystemHandle() const
	{
		return m_platformImpl->GetSystemHandle();
	}

}
