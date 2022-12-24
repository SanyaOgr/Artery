#pragma once

#include "WindowImpl.h"
#include <Windows.h>

#include "platform/SystemContextHandle.h"

namespace art {

	class GraphicsContextImpl
	{
	public:
		virtual ~GraphicsContextImpl() = default;

		static std::unique_ptr<GraphicsContextImpl> CreatePlatformImpl(SystemDeviceContextHandle deviceContext);

		virtual SystemGLContextHandle GetSystemGLContextHandle() const = 0;

		virtual	void SetCurrentDeviceContext(SystemDeviceContextHandle deviceContext) = 0;

		virtual void SetActive(bool current = true) = 0;

		virtual void SwapBuffers() = 0;

	protected:
		GraphicsContextImpl() = default;

	private:


	};

}