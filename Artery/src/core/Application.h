#pragma once
#include <memory>

#include "window/Window.h"
#include "Events/Event.h"
#include "Events/WindowEvent.h"

#include "graphics/GraphicsContext.h"
#include "graphics/Renderer.h"
#include "graphics/RendererAPI.h"

namespace art {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		void OnEvent2(Event& e);

		void Close();

	private:
		void init();

		bool onWindowClosed(WindowClosedEvent& e);
		bool onWindowResized(WindowResizedEvent& e);

		bool onWindowResized2(WindowResizedEvent& e);

	private:
		bool m_running;
		Window m_window;
		Window m_window2;
		std::unique_ptr<GraphicsContext> m_context;

		std::unique_ptr<RendererAPI> m_rendererAPI;
	};

}