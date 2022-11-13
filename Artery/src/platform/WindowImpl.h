#pragma once

#include <string>
#include <functional>

#include "SystemWindowHandle.h"
#include "Events/Event.h"
#include "Events/WindowEvent.h"

namespace art {

	class WindowImpl
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		static WindowImpl* Create(int width, int height, const std::string& title);
		virtual ~WindowImpl() = default;

		virtual void SetVisible(bool visible) = 0;

		virtual void ProcessEvents() = 0;

		virtual SystemWindowHandle GetSystemHandle() = 0;

		void SetEventCallback(const WindowImpl::EventCallbackFn& callback);

	protected:
		WindowImpl(int width, int height, const std::string& title);

	protected:
		EventCallbackFn m_eventCallback;

		std::string m_title;
		int m_width;
		int m_height;
	};

}