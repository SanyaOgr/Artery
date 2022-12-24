#include "GraphicsContextImpl.h"
#include "core/Config.h"

#if defined(ARTERY_SYSTEM_WINDOWS)

    #include "windows/WindowsGraphicsContextImpl.h"
    using GraphicsContextImplType = art::platform::WindowsGraphicsContextImpl;

#endif

namespace art {

    std::unique_ptr<GraphicsContextImpl> GraphicsContextImpl::CreatePlatformImpl(SystemDeviceContextHandle deviceContext)
    {
        return std::make_unique<GraphicsContextImplType>(deviceContext);
    }

}