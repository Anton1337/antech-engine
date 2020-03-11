#pragma once

#include <memory>
#include "Core.h";
#include "spdlog/spdlog.h"

namespace Antech {

	class ANTECH_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define AT_CORE_TRACE(...)  ::Antech::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AT_CORE_INFO(...)   ::Antech::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AT_CORE_WARN(...)   ::Antech::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AT_CORE_ERROR(...)  ::Antech::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AT_CORE_FATAL(...)  ::Antech::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define AT_TRACE(...)		::Antech::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AT_INFO(...)		::Antech::Log::GetClientLogger()->info(__VA_ARGS__)
#define AT_WARN(...)		::Antech::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AT_ERROR(...)		::Antech::Log::GetClientLogger()->error(__VA_ARGS__)
#define AT_FATAL(...)		::Antech::Log::GetClientLogger()->fatal(__VA_ARGS__)




