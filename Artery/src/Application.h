#pragma once

#include "Window.h"
#include "Events/Event.h"
#include "Events/WindowEvent.h"

namespace art {

	class Application
	{
	public:
		Application();

		void Run();

		void OnEvent(Event& e);

		void Close();

	private:
		bool OnWindowClosed(WindowClosedEvent& e);
		bool OnWindowResized(WindowResizedEvent& e);

	private:
		bool m_running;
		Window m_window;
	};

}