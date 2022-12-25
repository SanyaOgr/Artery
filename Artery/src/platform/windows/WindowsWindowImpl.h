#pragma once

#include "platform/WindowImpl.h"
#include "platform/SystemContextHandle.h"

namespace art::platform {

	class WindowsWindowImpl : public WindowImpl
	{
	public:
		WindowsWindowImpl(const WindowSettings& settings);
		~WindowsWindowImpl();

		void SetVisible(bool visible) override;

		void ProcessEvents() override;

		SystemWindowHandle GetSystemHandle() const override;

		SystemDeviceContextHandle GetSystemDeviceContextHandle() const override;

	private:
		static LRESULT globalWndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);
		LRESULT processEvent(UINT message, WPARAM wParam, LPARAM lParam);
		void registerWindowClass();

	private:
		static WNDCLASSEX s_windowClass;
		HWND m_handle;
		HDC m_deviceContext;
	};

}