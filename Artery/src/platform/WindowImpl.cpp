#include "WindowImpl.h"

#ifdef _WIN32
    #include "platform/windows/WindowsWindowImpl.h"
#endif

namespace art {

    // static
    WindowImpl* WindowImpl::Create(int width, int height, const std::string& title)
    {
#ifdef _WIN32
        return new platform::WindowsWindowImpl(width, height, title);
#endif
    }

    void WindowImpl::SetEventCallback(const WindowImpl::EventCallbackFn& callback)
    {
        m_eventCallback = callback;
    }

    WindowImpl::WindowImpl(int width, int height, const std::string& title)
        : m_width(width), m_height(height), m_title(title)
    {}

}