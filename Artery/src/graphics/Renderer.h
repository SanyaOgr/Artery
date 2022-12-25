#pragma once

#include "GraphicsContext.h"
#include "RendererAPI.h"

#include "core/Base.h"

namespace art {

	class VertexBuffer; // temporary

	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static void Draw(const GraphicsContext& context, VertexBuffer vb /* prototype */);

		static RendererAPI::API GetAPI();

	private:
		static ScopePtr<RendererAPI> s_renderAPI;
	};

}