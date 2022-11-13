#pragma once

#include "WindowImpl.h"

namespace art {

	class GraphicsContextImpl
	{
	public:
		static GraphicsContextImpl* Create();
		static GraphicsContextImpl* Create(SystemWindowHandle windowHandle);

		virtual void SwapBuffers() = 0;

		virtual void SetActive(bool active) = 0;

	protected:
		GraphicsContextImpl() = default;

	private:


	};

}