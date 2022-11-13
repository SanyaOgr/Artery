#include "WindowImpl.h"

#include "Config.h"

#if defined(ARTERY_SYSTEM_WINDOWS)

    #include "platform/windows/WindowsWindowImpl.h"
    using WindowImplType = art::platform::WindowsWindowImpl;

#endif

namespace art {

    // static
    WindowImpl* WindowImpl::Create(int width, int height, const std::string& title)
    {
        return new WindowImplType(width, height, title);
    }

    void WindowImpl::SetEventCallback(const WindowImpl::EventCallbackFn& callback)
    {
        m_eventCallback = callback;
    }

    WindowImpl::WindowImpl(int width, int height, const std::string& title)
        : m_width(width), m_height(height), m_title(title)
    {}

}