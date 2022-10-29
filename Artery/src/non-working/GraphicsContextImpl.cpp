#include "GraphicsContextImpl.h"

namespace art::platform {

    GraphicsContextImpl* GraphicsContextImpl::Create(PlatformWindowHandle windowHandle)
    {
#ifdef _WIN32
        return new win::WindowsGraphicsContextImpl(windowHandle);
#endif
    }

{