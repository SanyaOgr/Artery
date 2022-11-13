#include "GraphicsContextImpl.h"
#include "Config.h"

#if defined(ARTERY_SYSTEM_WINDOWS)

    #include "windows/WindowsGraphicsContextImpl.h"
    using GraphicsContextImplType = art::platform::WindowsGraphicsContextImpl;

#endif

namespace art {

    GraphicsContextImpl* GraphicsContextImpl::Create()
    {
        return new GraphicsContextImplType();
    }

    GraphicsContextImpl* GraphicsContextImpl::Create(SystemWindowHandle windowHandle)
    {
        return new GraphicsContextImplType(windowHandle);
    }

}