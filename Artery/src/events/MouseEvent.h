#pragma once

#include "Event.h"

namespace art {

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xPos, float yPos)
			: m_xPos(xPos), m_yPos(yPos)
		{}

		float GetX() const { return m_xPos; }
		float GetY() const { return m_yPos; }

		EVENT_CLASS_TYPE(MouseMoved)

	private:
		float m_xPos;
		float m_yPos;
	};

	class MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent(int buttonCode)
			: m_buttonCode(buttonCode)
		{}

		int GetButtonCode() const { return m_buttonCode; }

	private:
		int m_buttonCode;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int buttonCode)
			: MouseButtonEvent(buttonCode)
		{}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int buttonCode)
			: MouseButtonEvent(buttonCode)
		{}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}