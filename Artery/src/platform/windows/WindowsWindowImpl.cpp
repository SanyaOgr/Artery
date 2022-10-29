#include "WindowsWindowImpl.h"

namespace art::platform {
	
	WNDCLASSEX WindowsWindowImpl::s_windowClass{ sizeof(WNDCLASSEX) };

	WindowsWindowImpl::WindowsWindowImpl(int width, int height, const std::string& title)
		: WindowImpl(width, height, title), m_handle(nullptr)
	{
        registerWindowClass();

        // Compute position and size
        HDC screenDC = GetDC(nullptr);
        int left = (GetDeviceCaps(screenDC, HORZRES) - width) / 2;
        int top = (GetDeviceCaps(screenDC, VERTRES) - height) / 2;
        ReleaseDC(nullptr, screenDC);

        RECT rectangle = { 0, 0, width, height };
        AdjustWindowRect(&rectangle, WS_OVERLAPPEDWINDOW, false);
        int create_width = rectangle.right - rectangle.left;
        int create_height = rectangle.bottom - rectangle.top;

        m_handle = CreateWindowEx(
			WS_EX_OVERLAPPEDWINDOW,
			s_windowClass.lpszClassName,
            m_title.c_str(),
            WS_OVERLAPPEDWINDOW,
            left,
            top,
			create_width,
			create_height,
            nullptr,
            nullptr,
            GetModuleHandle(nullptr),
            this);
    }

	WindowsWindowImpl::~WindowsWindowImpl()
	{
		if (m_handle)
		{
			::DestroyWindow(m_handle);
		}
	}

	void WindowsWindowImpl::SetVisible(bool visible)
	{
		::ShowWindow(m_handle, visible ? SW_SHOW : SW_HIDE);
	}

	LRESULT WindowsWindowImpl::globalWndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return ::DefWindowProc(handle, message, wParam, lParam);
	}

	void WindowsWindowImpl::registerWindowClass()
	{
		s_windowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW; ////////////////////////// ???
		s_windowClass.lpfnWndProc = &WindowsWindowImpl::globalWndProc;
		s_windowClass.cbClsExtra = 0;
		s_windowClass.cbWndExtra = 0;
		s_windowClass.hInstance = GetModuleHandle(nullptr);
		s_windowClass.hIcon = nullptr;
		s_windowClass.hCursor = nullptr;
		s_windowClass.hbrBackground = nullptr;
		s_windowClass.lpszMenuName = nullptr;
		s_windowClass.lpszClassName = "Artery_WindowsWindowImpl_Class";
		RegisterClassEx(&s_windowClass);
	}

	void WindowsWindowImpl::ProcessEvents()
	{
		MSG message;
		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	PlatformWindowHandle WindowsWindowImpl::getPlatformHandle()
	{
		return m_handle;
	}

}