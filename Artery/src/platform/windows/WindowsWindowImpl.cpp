#include "artpch.h"

#include "WindowsWindowImpl.h"

namespace art::platform {
	
	WNDCLASSEX WindowsWindowImpl::s_windowClass{ sizeof(WNDCLASSEX) };

	WindowsWindowImpl::WindowsWindowImpl(const WindowSettings& settings)
		: WindowImpl(settings), m_handle(nullptr)
	{
		registerWindowClass();

        HDC screenDC = ::GetDC(nullptr);
        int left = (::GetDeviceCaps(screenDC, HORZRES) - settings.Width) / 2;
        int top = (::GetDeviceCaps(screenDC, VERTRES) - settings.Height) / 2;
        ::ReleaseDC(nullptr, screenDC);

        RECT rectangle = { 0, 0, settings.Width, settings.Height };
        ::AdjustWindowRect(&rectangle, WS_OVERLAPPEDWINDOW, false);
        int create_width = rectangle.right - rectangle.left;
        int create_height = rectangle.bottom - rectangle.top;

		// Creating of system window
        m_handle = ::CreateWindowEx(
			WS_EX_OVERLAPPEDWINDOW,
			s_windowClass.lpszClassName,
            m_settings.Title.c_str(),
            WS_OVERLAPPEDWINDOW,
            left,
            top,
			create_width,
			create_height,
            nullptr,
            nullptr,
            ::GetModuleHandle(nullptr),
            this);

		::UpdateWindow(m_handle);

		// Creating DC and configuring it for OpenGL
		m_deviceContext = ::GetDC(m_handle);

		PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
			PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
			32,                   // Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                   // Number of bits for the depthbuffer
			8,                    // Number of bits for the stencilbuffer
			0,                    // Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		int bestFormat = ::ChoosePixelFormat(m_deviceContext, &pfd);
		::SetPixelFormat(m_deviceContext, bestFormat, &pfd);
    }

	WindowsWindowImpl::~WindowsWindowImpl()
	{
		if (m_handle)
		{
			::ReleaseDC(m_handle, m_deviceContext);
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
			::SetWindowLongPtrW(handle, GWLP_USERDATA, window);
		}

		WindowsWindowImpl* window = handle ? reinterpret_cast<WindowsWindowImpl*>(GetWindowLongPtr(handle, GWLP_USERDATA)) : nullptr;

		if (window)
		{
			return window->processEvent(message, wParam, lParam);
		}

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
				m_settings.Width = LOWORD(lParam);
				m_settings.Height = HIWORD(lParam);

				WindowResizedEvent e(m_settings.Width, m_settings.Height);
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
		static bool registered = false;
		if (registered)
			return;
		registered = true;

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

	SystemWindowHandle WindowsWindowImpl::GetSystemHandle() const
	{
		return m_handle;
	}

	SystemDeviceContextHandle WindowsWindowImpl::GetSystemDeviceContextHandle() const
	{
		return m_deviceContext;
	}

}