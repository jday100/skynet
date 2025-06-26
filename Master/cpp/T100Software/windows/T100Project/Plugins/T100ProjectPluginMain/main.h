#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include "T100ProjectApplication.h"
#include "T100ProjectMainMenu.h"

using namespace T100WINDOWS;

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

T100ProjectMainMenu*        g_mainMenu      = T100NULL;


void ModuleInit(T100Win32Application*);

void ViewResize(T100WindowEvent&);


#ifdef __cplusplus
extern "C"
{
#endif

//class __declspec(dllimport) T100ProjectInvoking;

void DLL_EXPORT SomeFunction(const LPCSTR sometext);

void DLL_EXPORT PluginInit(T100ProjectApplication*);

T100MenuBar* DLL_EXPORT Main_GetMainMenuBar();

void DLL_EXPORT MenuSignIn();
void DLL_EXPORT MenuSignOut();

void DLL_EXPORT ViewSignIn(T100VOID*);
void DLL_EXPORT ViewSignOut();

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
