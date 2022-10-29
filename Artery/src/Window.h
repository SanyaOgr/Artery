#pragma once

#include "platform/WindowImpl.h"

namespace art {

	struct WindowParams
	{
		std::string title;
		int width;
		int height;
	};

	class Window
	{
	public:
		Window(int width, int height, const std::string& title);
		Window(const WindowParams& params);
		~Window();

		void Update();

	private:
		WindowImpl* m_platformImpl;
		WindowParams m_params;
	};

 }