#pragma once

#include <Windows.h>

#include "platform/WindowImpl.h"

namespace art::platform {

	class WindowsWindowImpl : public WindowImpl
	{
	public:
		WindowsWindowImpl(int width, int height, const std::string& title);
		~WindowsWindowImpl();

		void SetVisible(bool visible) override;

		void ProcessEvents() override;

	private:
		static LRESULT globalWndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);

		LRESULT processEvent(UINT message, WPARAM wParam, LPARAM lParam) { return 0; }

		void registerWindowClass();

		PlatformWindowHandle getPlatformHandle() override;

	private:
		HWND m_handle;
		static WNDCLASSEX s_windowClass;

	};

}