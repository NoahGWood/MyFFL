#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace MyFFL
{
    class Log
    {
        public:
            static void Init();
            inline static Ref<spdlog::logger>& GetLogger() { return m_CoreLogger; }

        private:
            static Ref<spdlog::logger> m_CoreLogger;
    };
} // Namespace MyFFL

// Logging macros
#define MyFFL_TRACE(...) ::MyFFL::Log::GetLogger()->trace(__VA_ARGS__)
#define MyFFL_INFO(...) ::MyFFL::Log::GetLogger()->info(__VA_ARGS__)
#define MyFFL_WARN(...) ::MyFFL::Log::GetLogger()->warn(__VA_ARGS__)
#define MyFFL_ERROR(...) ::MyFFL::Log::GetLogger()->error(__VA_ARGS__)
#define MyFFL_CRITICAL(...) ::MyFFL::Log::GetLogger()->critical(__VA_ARGS__)