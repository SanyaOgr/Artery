#pragma once
#include "Window.h"
#include <iostream>

namespace engine {

	// 
	class Application
	{
	public:
		Application() :
			m_window("Test Window", 1280, 720)
		{

		}

		~Application()
		{
		}

		void Run()
		{
			while (m_window.IsOpen())
			{
				m_window.Update();
			}
		}

	private:


	private:
		Window m_window;

	};

}