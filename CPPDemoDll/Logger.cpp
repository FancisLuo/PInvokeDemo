#include "Logger.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

PrintCallback Logger::m_pPrintCallback = nullptr;

void Logger::PrintFormat(const char* fmt, ...)
{
	static char buffer[512] = { 0 };

	va_list valist;
	va_start(valist, fmt);

	vsnprintf(buffer, 512, fmt, valist);
	va_end(valist);

	Print(buffer);
}

void Logger::Print(const char* msg)
{
	if (nullptr != m_pPrintCallback)
	{
		(m_pPrintCallback)(msg);
	}
}

void Logger::SetPrintCallback(PrintCallback callback)
{
	m_pPrintCallback = callback;
}

__DLLEXPORT_API void __stdcall RegisterPrintCallback(PrintCallback callback)
{
	Logger::SetPrintCallback(callback);
}
