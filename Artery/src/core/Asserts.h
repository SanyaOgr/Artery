#pragma once

#include <filesystem>

#if defined(ARTERY_ENABLE_ASSERTS)

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define ART_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { ART##type##ERROR(msg, __VA_ARGS__); ART_DEBUGBREAK(); } }
	#define ART_INTERNAL_ASSERT_WITH_MSG(type, check, ...) ART_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define ART_INTERNAL_ASSERT_NO_MSG(type, check) ART_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", ART_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define ART_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define ART_INTERNAL_ASSERT_GET_MACRO(...) ART_EXPAND_MACRO( ART_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, ART_INTERNAL_ASSERT_WITH_MSG, ART_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define ART_ASSERT(...) ART_EXPAND_MACRO( ART_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define ART_CORE_ASSERT(...) ART_EXPAND_MACRO( ART_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )

#else

	#define ART_ASSERT(...)
	#define ART_CORE_ASSERT(...)

#endif