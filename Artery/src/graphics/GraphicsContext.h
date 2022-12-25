#pragma once

#include "core/Base.h"
#include "platform/SystemContextHandle.h"
#include "platform/GraphicsContextImpl.h"
#include "window/Window.h"

namespace art {

	class GraphicsContext
	{
	public:
		GraphicsContext(const Window& window);
		virtual ~GraphicsContext();

		SystemGLContextHandle GetSystemGLContextHandle() const;

		void SwapBuffers();

		void SetCurrentDeviceContext(SystemDeviceContextHandle deviceContext);

		void SetActive(bool current = true);

	private:
		ScopePtr<GraphicsContextImpl> m_platformImpl;

	};

}