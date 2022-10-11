#pragma once
#include <windows.h>
#include <windowsx.h>
#include <string>
#include <map>

#include "Win32Window.h"

namespace win {

	WNDCLASSEX Win32Window::s_WndClassEx{};

	Win32Window::Win32Window(const std::string& title, int width, int height)
	{
		InitWndClass();

		m_hWnd = ::CreateWindow(
			s_WndClassEx.lpszClassName,
			title.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			width,
			height,
			NULL,
			NULL,
			GetModuleHandle(NULL),
			this);

		//ASSERT(m_hWnd);
		if (!m_hWnd)
			LOG("ERROR win::Window::Window() -> CreateWindow()");
	}

	Win32Window::~Win32Window()
	{
		::CloseWindow(m_hWnd);
		::DestroyWindow(m_hWnd);
	}

	void Win32Window::InitWndClass()
	{
		static bool s_Initialized = false;

		if (!s_Initialized)
		{
			s_Initialized = true;

			HINSTANCE hInst = ::GetModuleHandle(NULL);

			s_WndClassEx.cbSize = sizeof(WNDCLASSEX);
			s_WndClassEx.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
			s_WndClassEx.lpfnWndProc = Win32Window::StaticWndProc;
			s_WndClassEx.cbClsExtra = 0;
			s_WndClassEx.cbWndExtra = 0;
			s_WndClassEx.hInstance = hInst;
			s_WndClassEx.hIcon = ::LoadIcon(hInst, MAKEINTRESOURCE(IDI_APPLICATION));
			s_WndClassEx.hCursor = ::LoadCursor(NULL, IDC_ARROW);
			s_WndClassEx.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_MENU + 1);
			s_WndClassEx.lpszMenuName = NULL;
			s_WndClassEx.lpszClassName = "win::Win32Window";
			s_WndClassEx.hIconSm = ::LoadIcon(hInst, MAKEINTRESOURCE(IDI_APPLICATION));

			::RegisterClassEx(&s_WndClassEx);
		}

		DLOG("InitWndClass()");
	}

	LRESULT CALLBACK Win32Window::StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		Win32Window* pWindow = nullptr;

		if (uMsg == WM_CREATE)
		{
			DLOG("WM_CREATE");
			pWindow = reinterpret_cast<Win32Window*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
			::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));
			ASSERT(pWindow);
		}
		else
		{
			pWindow = reinterpret_cast<Win32Window*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
		}

		if (pWindow)
			return pWindow->WndProc(uMsg, wParam, lParam);

		return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	LRESULT Win32Window::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_MOUSEMOVE:
		{
			OnMouseMove(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			break;
		}
		case WM_LBUTTONDOWN:
		{
			OnMouseLeftButtonDown(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), wParam);
			break;
		}
		case WM_LBUTTONUP:
		{
			OnMouseLeftButtonUp(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), wParam);
			break;
		}
		case WM_KEYDOWN:
		{
			OnKeyDown(wParam);
			break;
		}
		case WM_KEYUP:
		{
			OnKeyUp(wParam);
			break;
		}
		case WM_SIZE:
		{
			OnWindowResize(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			break;
		}
		case WM_DESTROY:
		{
			DLOG("WM_DESTROY");
			::PostQuitMessage(0);
			break;
		}
		default:
		{
			return ::DefWindowProc(m_hWnd, uMsg, wParam, lParam);
		}
		}

		return 0;
	}

}