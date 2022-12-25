#pragma once

#include "core/Base.h"
#include "WindowImpl.h"
#include "platform/SystemContextHandle.h"

namespace art {

	class GraphicsContextImpl
	{
	public:
		virtual ~GraphicsContextImpl() = default;

		static ScopePtr<GraphicsContextImpl> CreatePlatformImpl(SystemDeviceContextHandle deviceContext);

		virtual SystemGLContextHandle GetSystemGLContextHandle() const = 0;

		virtual	void SetCurrentDeviceContext(SystemDeviceContextHandle deviceContext) = 0;

		virtual void SetActive(bool current = true) = 0;

		virtual void SwapBuffers() = 0;

	protected:
		GraphicsContextImpl() = default;

	private:


	};

}