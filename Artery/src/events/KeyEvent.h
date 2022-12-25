#pragma once

#include "Event.h"

namespace art {

	class KeyEvent : public Event
	{
	public:
		KeyEvent(int keyCode)
			: m_keyCode(keyCode)
		{}

		int GetKeyCode() const { return m_keyCode; }

	private:
		int m_keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode)
			: KeyEvent(keyCode)
		{}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode)
		{}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}