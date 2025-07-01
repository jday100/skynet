#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include "T100VMHyperV.h"

T100VMHyperV*       g_vm        = T100NULL;

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT SomeFunction(const LPCSTR sometext);

void DLL_EXPORT VM_Start();
void DLL_EXPORT VM_Stop();


#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
