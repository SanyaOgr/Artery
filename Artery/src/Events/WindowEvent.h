#pragma once

#include "Event.h"

namespace art {

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() = default;

		EVENT_CLASS_TYPE(WindowClosed)
	};

	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(unsigned int width, unsigned int height)
			: m_width(width), m_height(height) 
		{}

		unsigned int GetWidth() const { return m_width; }
		unsigned int GetHeight() const { return m_height; }

		EVENT_CLASS_TYPE(WindowResized)

	private:
		unsigned int m_width;
		unsigned int m_height;
	};

}