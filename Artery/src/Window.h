#pragma once

#include "platform/WindowImpl.h"
#include "Events/Event.h"

namespace art {

	class Window
	{
	public:
		Window();
		Window(int width, int height, const std::string& title);
		~Window();

		void Create(int width, int height, const std::string& title);

		void SetVisible(bool visible);

		void Update();

		void SetEventCallback(const WindowImpl::EventCallbackFn& callback);

	private:
		WindowImpl* m_platformImpl;
	};

 }