#pragma once

#include <platform/GraphicsContextImpl.h>

namespace art::graphics {

	class GraphicsContext
	{
	public:
		GraphicsContext() {}
		~GraphicsContext();

		void SwapBuffers() {}

	private:
		platform::GraphicsContextImpl* m_platformImpl;


	};

}