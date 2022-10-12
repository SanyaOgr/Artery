#include "Application.h"
#include <iostream>

namespace art {

	Application::Application()
		: m_isRunning(false)
	{}

	void Application::Run()
	{
		m_isRunning = true;
		std::cout << "Running\n";

		while (m_isRunning)
		{
			int a;
			std::cin >> a;
			m_isRunning = (a >= 0);
		}
		
		std::cout << "Stopped\n";
	}

}