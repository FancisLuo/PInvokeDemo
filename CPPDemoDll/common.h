#pragma once

#ifdef __DLLEXPORT
#define __DLLEXPORT_API __declspec(dllexport)
#else
#define __DLLEXPORT_API __declspec(dllimport)
#endif // __DLLEXPORT