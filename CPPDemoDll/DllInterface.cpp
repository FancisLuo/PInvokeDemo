#include "DllInterface.h"
#include "AppLaucher.h"
#include "Logger.h"

__DLLEXPORT_API int __stdcall Add(int a, int b)
{
    return a + b;
}

__DLLEXPORT_API void __stdcall StartApp(char* info)
{
    Logger::Print(info);

    AppLaucher::instance()->init();
}

__DLLEXPORT_API void __stdcall ExitApp(char* info)
{
    Logger::Print(info);
    AppLaucher::instance()->exit();
}
