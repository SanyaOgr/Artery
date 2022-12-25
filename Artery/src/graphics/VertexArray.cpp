#include "artpch.h"
#include "graphics/VertexArray.h"

#include "graphics/Renderer.h"
#include "platform/OpenGL/OpenGLVertexArray.h"

namespace art {

	RefPtr<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:	ART_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateRef<OpenGLVertexArray>();
		}

		ART_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}