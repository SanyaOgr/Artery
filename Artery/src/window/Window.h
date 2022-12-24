#pragma once
#include <string>
#include <memory>

#include "platform/WindowImpl.h"
#include "Events/Event.h"
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

	private:
		std::unique_ptr<WindowImpl> m_platformImpl;
	};

 }