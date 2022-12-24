#pragma once
#include <memory>

#include <glad/glad.h>

namespace art {

	class GLAD_Initializer
	{
	public:
		virtual ~GLAD_Initializer() = default;

		virtual void Init() = 0;

		static std::unique_ptr<GLAD_Initializer>& Get();

	protected:
		GLAD_Initializer() = default;

	private:
		static std::unique_ptr<GLAD_Initializer> create();

	private:
		static std::unique_ptr<GLAD_Initializer> m_platformImpl;
		static bool initialized;
	};

}