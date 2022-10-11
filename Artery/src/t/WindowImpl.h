#pragma once
#include <string>
#include <queue>
#include <Windows.h>

#include "Events/Event.h"
#include "Platform/PlatformWindow.h"
#include "Platform/Win32/WindowImplWin32.h"

namespace engine
{

	class WindowImpl
	{
	public:
		static WindowImpl* Create(const std::string& title, unsigned int width, unsigned int height);

        virtual WindowSystemHandle GetSystemHandle() const = 0;

        bool PopEvent(Event& event);

	private:

        WindowImpl(const WindowImpl&) = delete;

        WindowImpl& operator=(const WindowImpl&) = delete;

        //virtual Vector2i getPosition() const = 0;

        //virtual void setPosition(const Vector2i& position) = 0;

        //virtual Vector2u getSize() const = 0;

        //virtual void setSize(const Vector2u& size) = 0;

        //virtual void setTitle(const String& title) = 0;

        //virtual void setVisible(bool visible) = 0;

        //bool createOpenGLContext();

    protected:
        WindowImpl();

        void pushEvent(const Event& event);

        virtual void processEvents() = 0;

    private:
        std::queue<Event> m_events;
	};

}