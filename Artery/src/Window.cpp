#include "Window.h"
#include <iostream>

namespace art {

    LRESULT CALLBACK globalWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	Window::Window(int width, int height, const std::wstring& title)
        : m_hWnd(nullptr)
	{
        WNDCLASSEX wndClass{};
        
        wndClass.cbSize         = sizeof(WNDCLASSEX);
        wndClass.style          = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
        wndClass.lpfnWndProc    = &art::globalWndProc;                                      // TODO: wndProc abstraction
        wndClass.cbClsExtra     = 0;
        wndClass.cbWndExtra     = 0;
        wndClass.hInstance      = GetModuleHandle(nullptr);
        wndClass.hIcon          = LoadIcon(wndClass.hInstance, IDI_APPLICATION);
        wndClass.hIconSm        = wndClass.hIcon;
        wndClass.hCursor        = LoadCursor(wndClass.hInstance, IDC_ARROW);
        wndClass.hbrBackground  = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
        wndClass.lpszMenuName   = nullptr;
        wndClass.lpszClassName  = L"art::Window";
        
        if (!::RegisterClassEx(&wndClass))
        {
            std::cout << "failed to register wndClass at art::Window\n";                    // TODO: LOG and SHUTDOWN
        }

        m_hWnd = CreateWindowEx(
            WS_EX_OVERLAPPEDWINDOW, wndClass.lpszClassName,
            title.c_str(), WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, width, height,
            nullptr, nullptr, GetModuleHandle(nullptr), this
        );

        if (m_hWnd == nullptr)
        {
            std::cout << "failed to create window (m_hWnd) at art::Window\n";               // TODO: LOG and SHUTDOWN
        }

        UpdateWindow(m_hWnd);
        ShowWindow(m_hWnd, SW_SHOW);
	}

    LRESULT CALLBACK globalWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        if (uMsg == WM_DESTROY)
        {
            std::cout << "WM_DESTROY sended\n";                                             // TODO: LOG and SHUTDOWN
        }

        return DefWindowProc(hWnd, uMsg, wParam, lParam);                                   // TODO: system events dispatching
    }

}
