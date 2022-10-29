#pragma once

#include <Windows.h>

#include "../GraphicsContextImpl.h"
#include "../WindowImpl.h"

namespace art::platform::win {

	class GraphicsContextImpl;

	class WindowsGraphicsContextImpl : public art::platform::GraphicsContextImpl
	{
	public:
		WindowsGraphicsContextImpl(PlatformWindowHandle windowHandle);
		~WindowsGraphicsContextImpl();

		void MakeCurrent(bool current = true);
		void SwapBuffers() override;

	private:
		void createSurface(HWND window);

	private:
		HWND m_attachedWindow;
		HDC m_deviceContext;
		HGLRC m_glContext;
	};

}