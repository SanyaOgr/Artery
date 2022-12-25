#include "artpch.h"

#include "GraphicsContextImpl.h"

#if defined(ARTERY_SYSTEM_WINDOWS)

    #include "windows/WindowsGraphicsContextImpl.h"
    using GraphicsContextImplType = art::platform::WindowsGraphicsContextImpl;

#endif

namespace art {

    ScopePtr<GraphicsContextImpl> GraphicsContextImpl::CreatePlatformImpl(SystemDeviceContextHandle deviceContext)
    {
        return std::make_unique<GraphicsContextImplType>(deviceContext);
    }

}