#include "Application.h"
#include <iostream>

namespace art {

	Application::Application()
		: m_active(true), m_window(600, 400, "Test Window :)")
	{}

	void Application::Run()
	{
		std::cout << "Running\n";

		while (m_active)
		{
			m_window.Update();
		}
		
		std::cout << "Stopped\n";
	}

}