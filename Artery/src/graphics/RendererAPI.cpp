#include "artpch.h"
#include "RendererAPI.h"

#if defined(ARTERY_RENDERER_OPENGL)

#include "platform/OpenGL/OpenGLRendererAPI.h"
namespace art {
	using RendererAPI_Type = OpenGLRendererAPI;
}

#endif

namespace art {

	ScopePtr<RendererAPI> RendererAPI::CreatePlatformImpl()
	{
		return std::make_unique<RendererAPI_Type>();
	}

}