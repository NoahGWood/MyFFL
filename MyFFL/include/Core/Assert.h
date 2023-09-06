#pragma once

#include "Core/Base.h"
#include "Core/Log.h"
#include <filesystem>

#ifdef MyFFL_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define MyFFL_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { VM##type##ERROR(msg, __VA_ARGS__); MyFFL_DEBUG_BREAK(); } }
	#define MyFFL_INTERNAL_ASSERT_WITH_MSG(type, check, ...) MyFFL_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define MyFFL_INTERNAL_ASSERT_NO_MSG(type, check) MyFFL_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", MyFFL_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define MyFFL_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define MyFFL_INTERNAL_ASSERT_GET_MACRO(...) MyFFL_EXPAND_MACRO( MyFFL_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, MyFFL_INTERNAL_ASSERT_WITH_MSG, MyFFL_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define MyFFL_ASSERT(...) MyFFL_EXPAND_MACRO( MyFFL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define MyFFL_CORE_ASSERT(...) MyFFL_EXPAND_MACRO( MyFFL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define MyFFL_ASSERT(...)
	#define MyFFL_CORE_ASSERT(...)
#endif