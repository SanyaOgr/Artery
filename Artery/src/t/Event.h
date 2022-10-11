#pragma once
#include <functional>
#include <list>

#include "EventArgs.h"

namespace util {

	template<class Arg>
	class IEventHandler
	{
	public:
		virtual void call(Arg arg) = 0;

	protected:
		IEventHandler() {};
	};

	template<class Obj, class Arg>
	class MethodEventHandler : public IEventHandler<Arg>
	{
		using Method = void(Obj::*)(Arg);
	public:
		MethodEventHandler(Obj& object, Method method)
			: m_object(object), m_method(method)
		{
			ASSERT(method != nullptr);
		}

		virtual void call(Arg arg) override
		{
			(m_object.*m_method)(arg);
		}

	private:
		Obj m_object;
		Method m_method;
	};

	template<class Arg>
	class Event
	{
		using EventHandler = IEventHandler<Arg>;
	public:
		Event()
			: m_handlers()
		{}

		~Event()
		{
			for (EventHandler* handler : m_handlers)
			{
				delete handler;
			}
			m_handlers.clear();
		}

		void operator()(Arg arg)
		{
			for (EventHandler* handler : m_handlers)
			{
				handler->call(arg);
			}
		}

		void operator+=(EventHandler& handler)
		{
			m_handlers.push_back(&handler);
		}


	private:
		std::list<EventHandler*> m_handlers;
	};

	template<class Obj, class Arg>
	IEventHandler<Arg>& createMethodEventHandler(Obj& object, void(Obj::* method)(Arg))
	{
		return *(new MethodEventHandler<Obj, Arg>(object, method));
	}

#define METHOD_HANDLER( object, method ) createMethodEventHandler( object, &method )
#define MY_METHOD_HANDLER( method ) METHOD_HANDLER( *this, method )

}