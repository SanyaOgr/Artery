#pragma once

#include "platform/GraphicsContextImpl.h"
#include "Window.h"

namespace art {

	class GraphicsContext
	{
	public:
		GraphicsContext();
		GraphicsContext(const Window& window);
		virtual ~GraphicsContext();

		void Create();
		void Create(SystemWindowHandle windowHandle);

		void SwapBuffers();

		void SetActive(bool active = true);

	private:
		GraphicsContextImpl* m_platformImpl;

	};

}