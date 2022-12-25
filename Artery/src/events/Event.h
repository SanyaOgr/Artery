#pragma once

#include <functional>

namespace art {

	enum class EventType
	{
		WindowClosed, WindowResized,

		MouseMoved, MouseButtonPressed, MouseButtonReleased,

		KeyPressed, KeyReleased
	};

	class Event
	{
	public:
		virtual ~Event() = default;

		virtual EventType GetType() = 0;

	public:
		bool IsHandled = false;
	};

	using EventCallbackFn = std::function<void(art::Event&)>;

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; } \
								virtual EventType GetType() override { return GetStaticType(); }

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_event(event)
		{}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_event.GetType() == T::GetStaticType())
			{
				m_event.IsHandled |= func(static_cast<T&>(m_event));
				return true;
			}
			return false;
		}
	private:
		Event& m_event;
	};


}