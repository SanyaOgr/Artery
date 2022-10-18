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
			MSG msg;
			PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE);

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		std::cout << "Stopped\n";
	}

}