#pragma once
#include <Windows.h>

#include "platform/GraphicsContextImpl.h"

namespace art::platform {

	class WindowsGraphicsContextImpl : public GraphicsContextImpl
	{
	public:
		WindowsGraphicsContextImpl(SystemDeviceContextHandle deviceContext);
		~WindowsGraphicsContextImpl();

		SystemGLContextHandle GetSystemGLContextHandle() const override;

		void SetCurrentDeviceContext(SystemDeviceContextHandle deviceContext) override;

		virtual void SetActive(bool current = true) override;

		void SwapBuffers() override;

	private:
		void create(HDC deviceContext);

	private:
		HGLRC m_glContext;
		HDC m_attachedDeviceContext;
	};

}