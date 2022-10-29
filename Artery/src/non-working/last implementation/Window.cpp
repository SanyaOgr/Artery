#include "Window.h"

namespace engine {

	Window::Window(const std::string& title, unsigned int width, unsigned int height)
	{
		m_impl = WindowImpl::Create(title, width, height);
	}

	/*void Window::SetEventCallback(const std::function<void(Event&)>& callback)
	{
		m_impl->SetEventCallback(callback);
	}*/

	WindowHandle Window::GetHandle() const
	{
		return m_impl->GetHandle();
	}

	void Window::Update()
	{
		m_impl->Update();
	}

	bool Window::IsOpen() const
	{
		return (m_impl != nullptr);
	}

	void Window::Close()
	{
		delete m_impl;
	}

	void Window::SetTitle(const std::string& title)
	{
		m_impl->SetTitle(title);
	}

}