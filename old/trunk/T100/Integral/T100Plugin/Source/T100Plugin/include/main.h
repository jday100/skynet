#ifndef __MAIN_H__
#define __MAIN_H__

//#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifndef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

class T100MainFrame;

#ifdef __cplusplus
extern "C"
{
#endif

void __declspec(dllexport) Init(T100MainFrame*);

//void DLL_EXPORT SomeFunction(const LPCSTR sometext);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
