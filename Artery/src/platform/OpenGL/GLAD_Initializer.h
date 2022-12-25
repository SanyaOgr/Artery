#pragma once

namespace art {

	class GLAD_Initializer
	{
	public:
		virtual ~GLAD_Initializer() = default;

		virtual void Init() = 0;

		static ScopePtr<GLAD_Initializer>& Get();

	protected:
		GLAD_Initializer() = default;

	private:
		static ScopePtr<GLAD_Initializer> create();

	private:
		static ScopePtr<GLAD_Initializer> s_platformImpl;
		static bool s_initialized;
	};

}