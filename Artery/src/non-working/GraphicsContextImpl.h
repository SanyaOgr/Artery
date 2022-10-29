#pragma once

#include "WindowImpl.h"
#include "windows/WindowsGraphicsContextImpl.h"

namespace art::platform {

	class win::WindowsGraphicsContextImpl;

	class GraphicsContextImpl
	{
	public:
		static GraphicsContextImpl* Create(PlatformWindowHandle windowHandle);

		virtual void SwapBuffers() = 0;

	protected:
		GraphicsContextImpl() {}

	private:


	};

}