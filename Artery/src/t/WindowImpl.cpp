#include "WindowImpl.h"

namespace engine {

	WindowImpl* WindowImpl::Create(const std::string& title, unsigned int width, unsigned int height)
	{
		return (WindowImpl*)(new PlatformWindowImpl(title, width, height));
	}
	
	WindowImpl::WindowImpl()
	{
	}

	void WindowImpl::pushEvent(const Event& event)
	{
		m_events.push(event);
	}

	bool WindowImpl::PopEvent(Event& event)
	{
        // If the event queue is empty, let's first check if new events are available from the OS
        if (m_events.empty())
        {
            // Get events from the system
            processEvents();
        }

        // Pop the first event of the queue, if it is not empty
        if (!m_events.empty())
        {
            event = m_events.front();
            m_events.pop();

            return true;
        }

        return false;
	}

}