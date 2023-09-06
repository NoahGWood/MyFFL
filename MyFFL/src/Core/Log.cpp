#include "pch.h"
#include "Core/Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace MyFFL
{
    Ref<spdlog::logger> Log::m_CoreLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        m_CoreLogger = spdlog::stdout_color_mt("MyFFL");
        m_CoreLogger->set_level(spdlog::level::trace);
    }
} // namespace MyFFL