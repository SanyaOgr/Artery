#pragma once
#include <string>

#include <windows.h>

namespace art {

	class Window
	{
	public:
		Window(int width, int height, const std::wstring& title);

	private:
		HWND m_hWnd;
	};

 }