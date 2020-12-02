#pragma once

#include "common.h"

#if defined(__cplusplus)||defined(c_plusplus)
extern "C"
{
#endif

	__DLLEXPORT_API int __stdcall Add(int a, int b);

	__DLLEXPORT_API void __stdcall StartApp(char* info);
	__DLLEXPORT_API void __stdcall ExitApp(char* info);


#if defined(__cplusplus)||defined(c_plusplus)
}
#endif

