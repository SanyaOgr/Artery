#pragma once
#include "Window.h"

namespace art {

	class Application
	{
	public:
		Application();

		void Run();

	private:
		bool m_isRunning;
	};

}