#include "WindowImpl.h"

#include "core/Config.h"

#if defined(ARTERY_SYSTEM_WINDOWS)

    #include "platform/windows/WindowsWindowImpl.h"
    using WindowImplType = art::platform::WindowsWindowImpl;

#endif

namespace art {

    // static
    std::unique_ptr<WindowImpl> WindowImpl::CreatePlatformImpl(const WindowSettings& settings)
    {
        return std::make_unique<WindowImplType>(settings);
    }

    void WindowImpl::SetEventCallback(const EventCallbackFn& callback)
    {
        m_eventCallback = callback;
    }

    uint32_t WindowImpl::GetWidth() const
    {
        return m_settings.Width;
    }

    uint32_t WindowImpl::GetHeight() const
    {
        return m_settings.Height;
    }

    WindowImpl::WindowImpl(const WindowSettings& settings)
        : m_settings(settings)
    {}

}