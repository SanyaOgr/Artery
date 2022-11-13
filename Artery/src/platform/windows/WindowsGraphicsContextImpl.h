#pragma once
#include <Windows.h>

#include "platform/GraphicsContextImpl.h"

namespace art::platform {

	class WindowsGraphicsContextImpl : public GraphicsContextImpl
	{
	public:
		WindowsGraphicsContextImpl();
		WindowsGraphicsContextImpl(SystemWindowHandle windowHandle);
		~WindowsGraphicsContextImpl();

		void SetActive(bool active = true); 
		void SwapBuffers() override;

	private:
		void createSurface(HWND window);
		void initGLAD();

	private:
		HWND m_attachedWindow;
		HDC m_deviceContext;
		HGLRC m_glContext;
	};

}