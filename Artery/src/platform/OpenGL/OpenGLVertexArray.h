#pragma once

#include "graphics/VertexArray.h"

namespace art {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		void Bind() const override;
		void Unbind() const override;

		void AddVertexBuffer(const RefPtr<VertexBuffer>& vertexBuffer) override;
		void SetIndexBuffer(const RefPtr<IndexBuffer>& indexBuffer) override;

		const std::vector< RefPtr<VertexBuffer> >& GetVertexBuffers() const override;
		const RefPtr<IndexBuffer>& GetIndexBuffer() const override;

	private:
		uint32_t m_id;
		uint32_t m_vertexBufferIndex = 0;
		std::vector<RefPtr<VertexBuffer>> m_vertexBuffers;
		RefPtr<IndexBuffer> m_indexBuffer;

	};

}