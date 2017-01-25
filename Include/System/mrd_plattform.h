#ifndef MRD_PLATFORM_H
#define MRD_PLATFORM_H

#ifdef _WIN32
	#define MRD_SYS_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif // !NOMINMAX
#elif defined(__linux__)
	#define MRD_SYS_LINUX
#elif defined(__APPLE__)
	#define MRD_SYS_MACOS
#endif // _WIN32

#ifndef MRD_STATIC_BUILD
	#ifdef MRD_SYS_WINDOWS
		#ifdef MRD_NONCLIENT_BUILD
			#define MRD_API __declspec(dllexport)
		#else
			#define MRD_API __declspec(dllimport)
		#endif
		#ifdef _MSC_VER
			#pragma warning(disable : 4251)
		#endif // _MSC_VER
	#elif defined(MRD_SYS_LINUX) || defined(MRD_SYS_MACOS)
		#ifdef __GNUC__ >= 4
			#define MRD_API __attribute__ ((__visibility__("default")))
		#else
			#define MRD_API MRD_API
		#endif // __GNUC__
	#endif
#else
	#define MRD_API MRD_API
#endif // !MRD_STATIC_BUILD




#endif // !MRD_PLATFORM_H
