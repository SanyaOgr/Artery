#pragma once

//#define GLM_ENABLE_EXPERIMENTAL
//#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace art {

	class Log
	{
	public:
		static void Init();

		static RefPtr<spdlog::logger>& GetCoreLogger() { return s_coreLogger; }
		static RefPtr<spdlog::logger>& GetClientLogger() { return s_clientLogger; }

	private:   
		static RefPtr<spdlog::logger> s_coreLogger;
		static RefPtr<spdlog::logger> s_clientLogger;
	};

}

//template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
//inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
//{
//	return os << glm::to_string(vector);
//}
//
//template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
//inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
//{
//	return os << glm::to_string(matrix);
//}
//
//template<typename OStream, typename T, glm::qualifier Q>
//inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
//{
//	return os << glm::to_string(quaternion);
//}

// Core log macros
#define ART_CORE_TRACE(...)    ::art::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ART_CORE_INFO(...)     ::art::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ART_CORE_WARN(...)     ::art::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ART_CORE_ERROR(...)    ::art::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ART_CORE_CRITICAL(...) ::art::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ART_TRACE(...)         ::art::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ART_INFO(...)          ::art::Log::GetClientLogger()->info(__VA_ARGS__)
#define ART_WARN(...)          ::art::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ART_ERROR(...)         ::art::Log::GetClientLogger()->error(__VA_ARGS__)
#define ART_CRITICAL(...)      ::art::Log::GetClientLogger()->critical(__VA_ARGS__)