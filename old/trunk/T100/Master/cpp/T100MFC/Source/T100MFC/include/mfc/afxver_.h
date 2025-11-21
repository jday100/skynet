#ifndef AFXVER__H
#define AFXVER__H

#pragma once

/////////////////////////////////////////////////////////////////////////////
// Main version numbers

#define _AFX        1
#ifndef _MFC_VER
#define _MFC_VER    0x0E00
#endif // _MFC_VER

#ifndef _MFC_FILENAME_VER
#define _MFC_FILENAME_VER   "140"
#endif // _MFC_FILENAME_VER


/////////////////////////////////////////////////////////////////////////////
// turn off reference tracking for certain often used symbols

#pragma component(browser, off, references, "ASSERT")
#pragma component(browser, off, references, "AfxAssertFailedLine")
#pragma component(browser, off, references, "AfxDebugBreak")
#pragma component(browser, off, references, "BOOL")
#pragma component(browser, off, references, "BYTE")
#pragma component(browser, off, references, "DECLSPEC_IMPORT")
#pragma component(browser, off, references, "DWORD")
#pragma component(browser, off, references, "FALSE")
#pragma component(browser, off, references, "FAR")
#pragma component(browser, off, references, "LPSTR")
#pragma component(browser, off, references, "LPTSTR")
#pragma component(browser, off, references, "LPCSTR")
#pragma component(browser, off, references, "LPCTSTR")
#pragma component(browser, off, references, "NULL")
#pragma component(browser, off, references, "PASCAL")
#pragma component(browser, off, references, "THIS_FILE")
#pragma component(browser, off, references, "TRUE")
#pragma component(browser, off, references, "UINT")
#pragma component(browser, off, references, "WINAPI")
#pragma component(browser, off, references, "WORD")

/////////////////////////////////////////////////////////////////////////////
// For target version (one of)
//   _CUSTOM   : for custom configurations (causes afxv_cfg.h to be included)
//
// Additional build options:
//  _DEBUG              debug versions (full diagnostics)
//  _AFXDLL             use shared MFC DLL
//  _AFXEXT             extension DLL version, implies _AFXDLL
//  _USRDLL             create regular DLL (_AFXDLL is valid too)
//

#ifndef _DEBUG
#ifndef _AFX_DISABLE_INLINES
    #define _AFX_ENABLE_INLINES
#endif // _AFX_DISABLE_INLINES
#endif // _DEBUG

/////////////////////////////////////////////////////////////////////////////
// Special configurations

#if defined(_AFXEXT) && !defined(_AFXDLL)
    #define _AFXDLL
#endif // defined

#if defined(_AFXDLL) && !defined(_DLL)
    #error Please use the /MD switch for _AFXDLL builds
#endif // defined

/////////////////////////////////////////////////////////////////////////////
// special include files

#ifndef AFX_INLINE
    #define AFX_INLINE      inline
#endif // AFX_INLINE

#define _AFX_PACKING        8

#include <afxv_w32.h>

#ifdef _M_IX86
    #define _AFX_MINREBUILD
#endif // _M_IX86

#ifdef _AFXDLL
    #include <afxv_dll.h>
#endif // _AFXDLL

#ifndef VK_KANA
#define VK_KANA             0x15
#endif // VK_KANA

/////////////////////////////////////////////////////////////////////////////
// Special AfxDebugBreak: used to break into debugger at critical times

#ifndef AfxDebugBreak
#define AfxDebugBreak()     __debugbreak()
#endif // AfxDebugBreak

#ifndef _DEBUG
#ifdef AfxDebugBreak
#undef AfxDebugBreak
#endif // AfxDebugBreak
#define AfxDebugBreak()
#endif // _DEBUG

/////////////////////////////////////////////////////////////////////////////
// Standard preprocessor symbols if not already defined
/////////////////////////////////////////////////////////////////////////////

#ifndef SIZE_T_MAX
#define SIZE_T_MAX      UINT_MAX
#endif // SIZE_T_MAX

#ifndef PASCAL
#define PASCAL      __stdcall
#endif // PASCAL

#ifndef FASTCALL
#define FASTCALL    __fastcall
#endif // FASTCALL

#ifndef CDECL
#define CDECL       __cdecl
#endif // CDECL

#ifndef EXPORT
#define EXPORT
#endif // EXPORT

#if !defined(UNALIGNED)
#if defined(_M_X64)
#define UNALIGNED   __unaligned
#else
#define UNALIGNED
#endif // defined
#endif

#ifndef AFX_DEPRECATED
#ifdef _AFX_DISABLE_DEPRECATED
#define AFX_DEPRECATED(_Message)
#else
#define AFX_DEPRECATED(_Message)    __declspec(deprecated(_Message))
#endif // _AFX_DISABLE_DEPRECATED
#endif // AFX_DEPRECATED

#ifndef AFX_ANSI_DEPRECATED
#ifdef UNICODE
#define AFX_ANSI_DEPRECATED
#else
#define AFX_ANSI_DEPRECATED     AFX_DEPRECATED( \
			"This MFC feature requires /DUNICODE to work correctly, because the underlying Windows control is only supported for UNICODE builds. " \
			"Previous versions of MFC incorrectly enabled this in ANSI/MBCS builds. " \
			"Please compile with /DUNICODE to use this feature. See product documentation for more information." \
			)
#endif // UNICODE
#endif // AFX_ANSI_DEPRECATED

#if defined(_AFX_SECURE_NO_DEPRECATE) && !defined(_AFX_SECURE_NO_WARNINGS)
#define _AFX_SECURE_NO_WARNINGS
#endif // defined

#ifndef _AFX_INSECURE_DEPRECATE
#ifdef _AFX_SECURE_NO_WARNINGS
#define _AFX_INSECURE_DEPRECATE(_Message)
#else
#define _AFX_INSECURE_DEPRECATE(_Message)   __declspec(deprecated(_Message))
#endif // _AFX_SECURE_NO_WARNINGS
#endif // _AFX_INSECURE_DEPRECATE

#ifndef AFXAPI
#define AFXAPI          __stdcall
#endif // AFXAPI

#ifndef AFXOLEAPI
#define AFXOLEAPI       __stdcall
#endif // AFXOLEAPI

#ifndef AFX_CDECL
#define AFX_CDECL       __cdecl
#endif // AFX_CDECL

#ifndef AFX_EXPORT
#define AFX_EXPORT      EXPORT
#endif // AFX_EXPORT

#ifndef AFX_STATIC
#define AFX_STATIC      extern
#define AFX_STATIC_DATA extern __declspec(selectany)
#endif // AFX_STATIC

#ifndef AFX_DATA_EXPORT
#define AFX_DATA_EXPORT     __declspec(dllexport)
#endif // AFX_DATA_EXPORT
#ifndef AFX_DATA_IMPORT
#define AFX_DATA_IMPORT     __declspec(dllimport)
#endif // AFX_DATA_IMPORT

#if !defined(_MFC_BLD) && defined(_AFXDLL)
#define AFX_IMPORT_DATA     __declspec(dllimport)
#else
#define AFX_IMPORT_DATA
#endif

#ifndef AFX_CLASS_EXPORT
#define AFX_CLASS_EXPORT    __declspec(dllexport)
#endif // AFX_CLASS_EXPORT
#ifndef AFX_CLASS_IMPORT
#define AFX_CLASS_IMPORT    __declspec(dllimport)
#endif // AFX_CLASS_IMPORT

#ifndef AFX_API_EXPORT
#define AFX_API_EXPORT      __declspec(dllexport)
#endif // AFX_API_EXPORT
#ifndef AFX_API_IMPORT
#define AFX_API_IMPORT      __declspec(dllimport)
#endif // AFX_API_IMPORT


#ifndef AFX_ALWAYS_VTABLE
#ifndef AFX_NOVTABLE
#if !defined(_DEBUG)
#define AFX_NOVTABLE        __declspec(novtable)
#else
#define AFX_NOVTABLE
#endif
#endif // AFX_NOVTABLE
#endif // AFX_ALWAYS_VTABLE


#ifndef AFX_COMDAT
#define AFX_COMDAT      __declspec(selectany)
#endif // AFX_COMDAT

#define AFX_DATA
#define AFX_DATADEF
#define AFX_API

#ifndef AFX_CORE_DATA
#define AFX_CORE_DATA
#define AFX_CORE_DATADEF
#endif // AFX_CORE_DATA

#ifndef AFX_OLE_DATA
#define AFX_OLE_DATA
#define AFX_OLE_DATADEF
#endif // AFX_OLE_DATA

#ifndef AFX_DB_DATA
#define AFX_DB_DATA
#define AFX_DB_DATADEF
#endif // AFX_DB_DATA

#ifndef AFX_NET_DATA
#define AFX_NET_DATA
#define AFX_NET_DATADEF
#endif // AFX_NET_DATA

#ifndef AFX_EXT_DATA
#define AFX_EXT_DATA
#define AFX_EXT_DATADEF
#define AFX_EXT_CLASS
#define AFX_EXT_API
#endif // AFX_EXT_DATA

#ifndef BASED_CODE
#define BASED_CODE
#endif // BASED_CODE

#ifndef BASED_DEBUG
#define BASED_DEBUG
#endif // BASED_DEBUG

#ifndef BASED_STACK
#define BASED_STACK
#endif // BASED_STACK

#endif // AFXVER__H
