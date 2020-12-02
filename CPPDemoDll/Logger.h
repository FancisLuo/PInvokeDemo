#pragma once

#include "common.h"

typedef void(__stdcall* PrintCallback)(const char* msg);

#if defined(__cplusplus)||defined(c_plusplus)
extern "C"
{
#endif

	__DLLEXPORT_API void __stdcall RegisterPrintCallback(PrintCallback callback);

#if defined(__cplusplus)||defined(c_plusplus)
}
#endif

class Logger
{
public:
	static void PrintFormat(const char* fmt, ...);
	static void Print(const char* msg);

	static void SetPrintCallback(PrintCallback callback);

private:
	static PrintCallback m_pPrintCallback;
};

