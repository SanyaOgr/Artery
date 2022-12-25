#pragma once

#include <string>

#include "core/Base.h"
#include "events/Event.h"
#include "platform/WindowImpl.h"
#include "platform/SystemContextHandle.h"

namespace art {

	class Window
	{
	public:
		Window(const WindowSettings& settings = WindowSettings());
		~Window();

		void SetVisible(bool visible);

		void OnUpdate();

		void SetEventCallback(const EventCallbackFn& callback);

		SystemWindowHandle GetSystemHandle() const;

		SystemDeviceContextHandle GetSystemDeviceContextHandle() const;

		uint32_t GetWidth() const;
		uint32_t GetHeight() const;
		std::string GetTitle() const;

	private:
		ScopePtr<WindowImpl> m_platformImpl;
	};

 }