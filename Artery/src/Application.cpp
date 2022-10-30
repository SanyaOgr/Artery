#include "Application.h"

#include <iostream>
#include "Defines.h"

namespace art {

	Application::Application()
		: m_running(true), m_window(600, 400, "Test Window :)")
	{
		m_window.SetEventCallback(ART_BIND_EVENT_FN(Application::OnEvent));
	}

	void Application::Run()
	{
		std::cout << "Running\n";

		while (m_running)
		{
			m_window.Update();
		}
		
		std::cout << "Stopped\n";
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowClosedEvent>(ART_BIND_EVENT_FN(Application::OnWindowClosed));
		dispatcher.Dispatch<WindowResizedEvent>(ART_BIND_EVENT_FN(Application::OnWindowResized));
	}

	void Application::Close()
	{
		m_running = false;
	}

	bool Application::OnWindowClosed(WindowClosedEvent& e)
	{
		Close();
		return true;
	}

	bool Application::OnWindowResized(WindowResizedEvent& e)
	{
		std::cout << "Window Size: " << e.GetWidth() << "x" << e.GetHeight() << "\n";
		return true;
	}

}