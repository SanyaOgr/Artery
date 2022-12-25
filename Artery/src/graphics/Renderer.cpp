#include "artpch.h"
#include "graphics/Renderer.h"

namespace art {

	ScopePtr<RendererAPI> Renderer::s_renderAPI;

	void Renderer::Init()
	{
	}

	void Renderer::Shutdown()
	{
	}

	//void Renderer::Draw(const GraphicsContext& context, VertexBuffer vb)
	//{
	//}

	RendererAPI::API Renderer::GetAPI()
	{
		return s_renderAPI->GetAPI();
	}

}