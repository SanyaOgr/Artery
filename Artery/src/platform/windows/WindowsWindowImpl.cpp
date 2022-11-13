#include "WindowsWindowImpl.h"

#include <iostream>

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

		UpdateWindow(m_handle);
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
		if (message == WM_CREATE)
		{
			LONG_PTR window = reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
			SetWindowLongPtrW(handle, GWLP_USERDATA, window);
		}

		WindowsWindowImpl* window = handle ? reinterpret_cast<WindowsWindowImpl*>(GetWindowLongPtr(handle, GWLP_USERDATA)) : nullptr;

		if (window)
		{
			return window->processEvent(message, wParam, lParam);
		}

		/*if (message == WM_CLOSE)
			return 0;*/

		return ::DefWindowProc(handle, message, wParam, lParam);
	}

	LRESULT WindowsWindowImpl::processEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (!m_eventCallback)
		{
			return ::DefWindowProc(m_handle, message, wParam, lParam);
		}

		switch (message)
		{
			case WM_CLOSE:
			{
				WindowClosedEvent e;
				m_eventCallback(e);
			}
			case WM_SIZE:
			{
				m_width = LOWORD(lParam);
				m_height = HIWORD(lParam);

				WindowResizedEvent e(m_width, m_height);
				m_eventCallback(e);
			}
			default:
			{
				return ::DefWindowProc(m_handle, message, wParam, lParam);
			}
		}

		return 0;
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

	SystemWindowHandle WindowsWindowImpl::GetSystemHandle()
	{
		return m_handle;
	}

}