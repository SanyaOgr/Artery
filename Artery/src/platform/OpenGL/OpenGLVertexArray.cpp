#include "artpch.h"

#include "platform/OpenGL/OpenGLVertexArray.h"

namespace art {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:    return GL_FLOAT;
		case ShaderDataType::Float2:   return GL_FLOAT;
		case ShaderDataType::Float3:   return GL_FLOAT;
		case ShaderDataType::Float4:   return GL_FLOAT;
		case ShaderDataType::Mat3f:     return GL_FLOAT;
		case ShaderDataType::Mat4f:     return GL_FLOAT;
		case ShaderDataType::Int:      return GL_INT;
		case ShaderDataType::Int2:     return GL_INT;
		case ShaderDataType::Int3:     return GL_INT;
		case ShaderDataType::Int4:     return GL_INT;
		case ShaderDataType::Bool:     return GL_BOOL;
		}

		ART_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_id);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const RefPtr<VertexBuffer>& vertexBuffer)
	{
		Bind();
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();

		for (const auto& element : layout)
		{
			switch (element.Type)
			{
			case ShaderDataType::Float:
			case ShaderDataType::Float2:
			case ShaderDataType::Float3:
			case ShaderDataType::Float4:
			{
				glEnableVertexAttribArray(m_vertexBufferIndex);
				glVertexAttribPointer(m_vertexBufferIndex,
					element.GetComponentCount(),
					ShaderDataTypeToOpenGLBaseType(element.Type),
					element.Normalized ? GL_TRUE : GL_FALSE,
					layout.GetStride(),
					reinterpret_cast<const void*>(element.Offset));
				m_vertexBufferIndex++;
				break;
			}
			case ShaderDataType::Int:
			case ShaderDataType::Int2:
			case ShaderDataType::Int3:
			case ShaderDataType::Int4:
			case ShaderDataType::Bool:
			{
				glEnableVertexAttribArray(m_vertexBufferIndex);
				glVertexAttribIPointer(m_vertexBufferIndex,
					element.GetComponentCount(),
					ShaderDataTypeToOpenGLBaseType(element.Type),
					layout.GetStride(),
					reinterpret_cast<const void*>(element.Offset));
				m_vertexBufferIndex++;
				break;
			}
			case ShaderDataType::Mat3f:
			case ShaderDataType::Mat4f:
			{
				uint8_t count = element.GetComponentCount();
				for (uint8_t i = 0; i < count; i++)
				{
					glEnableVertexAttribArray(m_vertexBufferIndex);
					glVertexAttribPointer(m_vertexBufferIndex,
						count,
						ShaderDataTypeToOpenGLBaseType(element.Type),
						element.Normalized ? GL_TRUE : GL_FALSE,
						layout.GetStride(),
						reinterpret_cast<const void*>(element.Offset + sizeof(float) * count * i));
					glVertexAttribDivisor(m_vertexBufferIndex, 1);
					m_vertexBufferIndex++;
				}
				break;
			}
			default:
				ART_CORE_ASSERT(false, "Unknown ShaderDataType!");
			}
		}

		m_vertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const RefPtr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_id);
		indexBuffer->Bind();

		m_indexBuffer = indexBuffer;
	}

	const std::vector<RefPtr<VertexBuffer>>& OpenGLVertexArray::GetVertexBuffers() const
	{
		return m_vertexBuffers;
	}

	const RefPtr<IndexBuffer>& OpenGLVertexArray::GetIndexBuffer() const
	{
		return m_indexBuffer;
	}

}