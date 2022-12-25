#pragma once

#include <string>

#include "core/Base.h"
#include "Events/Event.h"
#include "Events/WindowEvent.h"
#include "platform/SystemWindowHandle.h"
#include "platform/SystemContextHandle.h"

namespace art {

	struct WindowSettings
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowSettings(const std::string& title = "Default Window",
			uint32_t width = 800,
			uint32_t height = 600)
			: Title(title), Width(width), Height(height)
		{}
	};

	class WindowImpl
	{
	public:
		static ScopePtr<WindowImpl> CreatePlatformImpl(const WindowSettings& settings);

		virtual ~WindowImpl() = default;

		virtual void SetVisible(bool visible) = 0;

		virtual void ProcessEvents() = 0;

		virtual SystemWindowHandle GetSystemHandle() const = 0;

		virtual SystemDeviceContextHandle GetSystemDeviceContextHandle() const = 0;

		void SetEventCallback(const EventCallbackFn& callback);

		uint32_t GetWidth() const;
		uint32_t GetHeight() const;
		std::string GetTitle() const;

	protected:
		WindowImpl(const WindowSettings& settings);

	protected:
		EventCallbackFn m_eventCallback;
		WindowSettings m_settings;
	};

}