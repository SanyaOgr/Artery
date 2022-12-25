#pragma once

#include "window/Window.h"
#include "graphics/GraphicsContext.h"

namespace art {

	class RenderWindow : public Window
	{
	public:
		RenderWindow(const WindowSettings& settings = WindowSettings());
		virtual ~RenderWindow();
		
		void SetActive(bool active = true);

	private:
		GraphicsContext* m_graphicsContext;
	};

}