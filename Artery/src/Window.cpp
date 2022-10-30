#include "Window.h"
#include <iostream>

namespace art {

	Window::Window(int width, int height, const std::string& title)
	{
		m_platformImpl = WindowImpl::Create(width, height, title);
		m_platformImpl->SetVisible(true);
	}

	Window::~Window()
	{
		delete m_platformImpl;
	}

	void Window::Update()
	{
		m_platformImpl->ProcessEvents();
	}

	void Window::SetEventCallback(const WindowImpl::EventCallbackFn& callback)
	{
		m_platformImpl->SetEventCallback(callback);
	}

}
