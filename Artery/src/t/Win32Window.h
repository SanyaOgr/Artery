#pragma once
#include <windows.h>
#include <string>
#include <map>

#include "Debug.h"
#include "Event.h"

namespace win {

    /*class Win32Window
    {
    private:
        static WNDCLASSEX s_WndClassEx;
        HWND m_hWnd;

        using TMouseEvent = util::Event<util::MouseEventArgs>;
        using TKeyEvent = util::Event<util::KeyEventArgs>;
        using TWindowResizeEvent = util::Event<util::WindowResizeEventArgs>;

        TMouseEvent m_mouseMoveEvent;
        TMouseEvent m_mouseLButtonUpEvent;
        TMouseEvent m_mouseLButtonDownEvent;

        TKeyEvent m_keyUpEvent;
        TKeyEvent m_keyDownEvent;

        TWindowResizeEvent m_windowResizeEvent;

    public:
        Win32Window(const std::string& title, int width, int height);
        ~Win32Window();

        void Show()
        {
            ::ShowWindow(m_hWnd, SW_SHOWNORMAL);
            ::UpdateWindow(m_hWnd);
        }

        void Close()
        {
            ::CloseWindow(m_hWnd);
        }

        HWND GetHandle() const { return m_hWnd; }

        void SetTitle(const std::string& title)
        {
            ::SetWindowText(m_hWnd, title.c_str());
        }

        std::string GetTitle() const
        {
            char buffer[256];
            ::GetWindowText(m_hWnd, buffer, 255);
            return std::string(buffer);
        }

        TMouseEvent& MouseMoveEvent() { return m_mouseMoveEvent; }
        TMouseEvent& MouseLButtonUpEvent() { return m_mouseLButtonUpEvent; }
        TMouseEvent& MouseLButtonDownEvent() { return m_mouseLButtonDownEvent; }
        TKeyEvent& KeyUpEvent() { return m_keyUpEvent; }
        TKeyEvent& KeyDownEvent() { return m_keyDownEvent; }
        TWindowResizeEvent& WindowResizeEvent() { return m_windowResizeEvent; }

    private:
        static void InitWndClass();

        static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

        LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

        virtual void OnMouseMove(int x, int y)
        {
            m_mouseMoveEvent(util::MouseEventArgs(x, y));
        };

        virtual void OnMouseLeftButtonDown(int x, int y, int virtualKeyCode)
        {
            m_mouseLButtonDownEvent(util::MouseEventArgs(x, y, static_cast<util::MouseButton>(VK_LBUTTON)));
        };

        virtual void OnMouseLeftButtonUp(int x, int y, int virtualKeyCode)
        {
            m_mouseLButtonUpEvent(util::MouseEventArgs(x, y, static_cast<util::MouseButton>(VK_LBUTTON)));
        };

        virtual void OnKeyDown(int virtualKeyCode)
        {
            m_keyDownEvent(util::KeyEventArgs(virtualKeyCode));
        };

        virtual void OnKeyUp(int virtualKeyCode)
        {
            m_keyDownEvent(util::KeyEventArgs(virtualKeyCode));
        };

        virtual void OnWindowResize(int width, int height)
        {
            m_windowResizeEvent(util::WindowResizeEventArgs(width, height));
        };
    };*/

    class Win32WindowImpl : public WindowImpl
    {
    private:

        struct WindowData
        {
            std::string sTitle;
            unsigned int nWidth;
            unsigned int nHeight;
            bool bVSync;
            EventCallbackFn fnEventCallback;
        };

        GLFWwindow* m_pWindow;
        WindowData m_data;
        ImVec4 m_clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    private:
        virtual void init(const WindowProps& properities);
        virtual void shutdown();

    public:
        WinWindow(const WindowProps& properities);
        virtual ~WinWindow() override;

        void OnUpdate() override;

        inline unsigned int GetWidth() const { return m_data.nWidth; }
        inline unsigned int GetHeight() const { return m_data.nHeight; }

        void* GetNativeWindow() const override { return m_pWindow; }

        void SetVSync(bool enabled) override;
        bool IsVSyncEnabled() const override;

        inline void SetEventCallback(const EventCallbackFn& callback) { m_data.fnEventCallback = callback; }

        void GetCursorPos(double& x, double& y)
        {
            glfwGetCursorPos(m_pWindow, &x, &y);
        }
    };

}