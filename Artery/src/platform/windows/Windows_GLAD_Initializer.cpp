#include "platform/windows/Windows_GLAD_Initializer.h"

#include "platform/windows/WindowsWindowImpl.h"
#include "platform/windows/WindowsGraphicsContextImpl.h"

namespace art {

	void Windows_GLAD_Initializer::Init()
	{
		std::unique_ptr<WindowImpl> fakeWnd = WindowImpl::CreatePlatformImpl(WindowSettings());
		HDC deviceContext = ::GetDC(fakeWnd->GetSystemHandle());
		HGLRC glContext = ::wglCreateContext(deviceContext);
		::wglMakeCurrent(deviceContext, glContext);

		gladLoadGL();

		::wglMakeCurrent(deviceContext, NULL);
		::ReleaseDC(fakeWnd->GetSystemHandle(), deviceContext);
		::wglDeleteContext(glContext);
	}

}
