#pragma once
#include <windows.h>
#include <windowsx.h>

#include "WindowImpl.h"
#include "Debug.h"

#include "Events/AppEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"
#include "Events/WindowEvent.h"

#include "Input/Keyboard.h"



#include <string>
#include <queue>
#include <Windows.h>

#include "Events/Event.h"
#include "Platform/PlatformWindow.h"
#include "Platform/Win32/WindowImplWin32.h"



namespace engine {

	//class WindowImpl;


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

	class WindowImplWin32 : public WindowImpl
	{
	public:
        //WindowImplWin32(WindowSystemHandle handle);

        WindowImplWin32(const std::string& title, unsigned int width, unsigned int height);

        WindowSystemHandle GetSystemHandle() const override;

        //Vector2i getPosition() const override;

        //void setPosition(const Vector2i& position) override;

        ////////////////////////////////////////////////////////////
        //Vector2u getSize() const override;

        //void setSize(const Vector2u& size) override;

        //void setTitle(const String& title) override;

        //void setVisible(bool visible) override;

	protected:
        virtual void processEvents() override;

    private:
        void registerWindowClass();

        static LRESULT CALLBACK globalOnMsgEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

        void processMsgEvent(UINT uMsg, WPARAM wParam, LPARAM lParam);

        Keyboard::Key virtualKeyCodeToEnum(WPARAM key, LPARAM flags);

	private:
        static WNDCLASSEX s_windowClass;
        HWND m_handle;
        LONG_PTR m_callback;

	};

}