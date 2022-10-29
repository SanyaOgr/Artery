#include "Window.h"
#include <iostream>

namespace art {

	Window::Window(int width, int height, const std::string& title)
		: m_params{ title, width, height }
	{
		m_platformImpl = WindowImpl::Create(width, height, title);
		m_platformImpl->SetVisible(true);
	}

	Window::Window(const WindowParams& params)
		: Window(params.width, params.height, params.title)
	{}

	Window::~Window()
	{
		delete m_platformImpl;
	}

	void Window::Update()
	{
		m_platformImpl->ProcessEvents();
	}

}
