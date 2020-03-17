#pragma once

#ifdef AT_PLATFORM_WINDOWS
	#ifdef AT_BUILD_DLL
		#define ANTECH_API __declspec(dllexport)
	#else
		#define ANTECH_API __declspec(dllimport)
	#endif
#else
	#error Antech Engine only supports Windows! (for now)
#endif

#ifdef AT_ENABLE_ASSERTS
	#define AT_ASSERT(x, ...) { if(!(x)) { AT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AT_CORE_ASSERT(x, ...) { if(!(x)) { AT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AT_ASSERT(x, ...)
	#define AT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
