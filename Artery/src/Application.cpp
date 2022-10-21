#include "Application.h"
#include <iostream>

namespace art {

	Application::Application()
		: m_isRunning(false), m_window(600, 400, "Test Window :)")
	{}

	void Application::Run()
	{
		m_isRunning = true;
		std::cout << "Running\n";

		while (m_isRunning)
		{
			m_window.Update();
		}
		
		std::cout << "Stopped\n";
	}

}