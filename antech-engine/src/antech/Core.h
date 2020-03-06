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
