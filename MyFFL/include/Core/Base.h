#pragma once
#include "Core/PlatformDetection.h"

#include <memory>
#include <functional>

#ifdef MyFFL_DEBUG
	#define MyFFL_ENABLE_ASSERTS
    #if defined(MyFFL_PLATFORM_WINDOWS)
        #define MyFFL_DEBUG_BREAK() __debug_break()
    #elif defined(MyFFL_PLATFORM_LINUX)
        #include <signal.h>
        #define MyFFL_DEBUG_BREAK() raise(SIGTRAP)
    #else
        #error "Platform does not support MyFFL_DEBUG_BREAK()"
    #endif
    #define MyFFL_ENABLE_ASSERTS
#else
    #define MyFFL_DEBUG_BREAK()
#endif

#define MyFFL_EXPAND_MACRO(x) x
#define MyFFL_STRINGIFY_MACRO(x) #x

#define MyFFL_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }


namespace MyFFL
{
    template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

} // namespace MyFFL

#include "Core/Assert.h"
#include "Core/Log.h"