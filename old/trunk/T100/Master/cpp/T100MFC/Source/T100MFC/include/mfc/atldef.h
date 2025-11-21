#ifndef ATLDEF_H
#define ATLDEF_H

#pragma once

#pragma warning(disable : 4619)

#ifndef _ATL_USE_WINAPI_FAMILY_DESKTOP_APP
#ifdef WINAPI_FAMILY
#include <winapifamily.h>
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#define _ATL_USE_WINAPI_FAMILY_DESKTOP_APP
#else
#ifdef WINAPI_FAMILY_PHONE_APP
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#define _ATL_USE_WINAPI_FAMILY_PHONE_APP
#endif // WINAPI_FAMILY
#endif // WINAPI_FAMILY_PHONE_APP
#ifdef WINAPI_FAMILY_APP
#if WINAPI_FAMILY == WINAPI_FAMILY_APP
#define _ATL_USE_WINAPI_FAMILY_APP
#endif // WINAPI_FAMILY
#endif // WINAPI_FAMILY_APP
#endif // WINAPI_FAMILY_PARTITION
#else
#define _ATL_USE_WINAPI_FAMILY_DESKTOP_APP
#endif // WINAPI_FAMILY
#endif // _ATL_USE_WINAPI_FAMILY_DESKTOP_APP

#ifndef _ATL_USE_WINAPI_FAMILY_DESKTOP_APP

#ifndef _ATL_NO_SERVICE
#define _ATL_NO_SERVICE
#endif // _ATL_NO_SERVICE

#ifndef _ATL_NO_COM_SUPPORT
#define _ATL_NO_COM_SUPPORT
#endif // _ATL_NO_COM_SUPPORT

#ifndef _ATL_NO_COMMODULE
#define _ATL_NO_COMMODULE
#endif // _ATL_NO_COMMODULE

#ifndef _ATL_NO_WIN_SUPPORT
#define _ATL_NO_WIN_SUPPORT
#endif // _ATL_NO_WIN_SUPPORT

#endif // _ATL_USE_WINAPI_FAMILY_DESKTOP_APP

#include <atlrc.h>
#include <errno.h>
#include <stdlib.h>
#include <sal.h>

#ifndef _ATL_DISABLE_NOTHROW_NEW
#include <new.h>
#define _ATL_NEW        new(std::nothrow)
#else
#define _ATL_NEW        new
#endif // _ATL_DISABLE_NOTHROW_NEW

#ifndef _ATL_STRINGIZE
#define __ATL_STRINGIZE(_Value) #_Value
#define _ATL_STRINGIZE(_Value) __ATL_STRINGIZE(_Value)
#endif // _ATL_STRINGIZE

#ifndef _ATL_APPEND
#define __ATL_APPEND(_Value1, _Value2)  _Value1 ## _Value2
#define _ATL_APPEND(_Value1, _Value2)   __ATL_APPEND(_Value1, _Value2)
#endif // _ATL_APPEND

#ifndef RC_INVOKED

#if defined(_CHAR_UNSIGNED) && !defined(_ATL_ALLOW_CHAR_UNSIGNED)
#error ATL does not support compilation with /J or _CHAR_UNSIGNED flag enabled
#endif // defined

#ifndef __cplusplus
	#error ATL requires C++ compilation (use a .cpp suffix)
#endif

#ifdef UNDER_CE
	#error This version of ATL is not currently supported for CE. Look for the CE specific version.
#endif

#if defined(_M_CEE)
#ifdef _ATL_MIXED
#pragma detect_mismatch("_ATL_MIXED", "Definded")
#else
#pragma detect_mismatch("_ATL_MIXED", "Undefined")
#endif // _ATL_MIXED
#endif // defined

#if defined(_ATL_MIXED) || !defined(_M_CEE)

#if defined(_M_HYBRID)
#pragma comment(linker, "/include:??3@$$hYAXPAX@Z")
#elif defined _M_ARM64EC
#pragma comment(linker, "/include:??3@$$hYAXPEAX@Z")
#elif defined _M_IX86 || defined _M_ARM
#pragma comment(linker, "/include:??3@YAXPAX@Z")
#elif defined _M_X64 || defined _M_ARM64
#pragma comment(linker, "/include:??3@YAXPEAX@Z")
#else
#error Unsupported target architecture.
#endif
#ifndef _ATL_NATIVE_INITIALIZATION
#define _ATL_NATIVE_INITIALIZATION
#endif

#endif // defined

#ifdef _UNICODE
#ifndef UNICODE
#define UNICODE
#endif // UNICODE
#endif // _UNICODE

#ifdef _DEBUG
#ifndef DEBUG
#define DEBUG
#endif // DEBUG
#endif // _DEBUG

#if !defined(_ATL_USE_WINAPI_FAMILY_DESKTOP_APP) && !defined(_UNICODE)
#error _UNICODE has to be defined to use ATL under the current WINAPI_FAMILY
#endif

#if defined(_PREFAST_) && (_MSC_VER < 1600)
#define ATLSTATIC_ASSERT(expr, comment)
#else
#define ATLSTATIC_ASSERT(expr, comment)		static_assert(expr, comment)
#endif

#ifdef _WIN64
#define _ATL_SUPPORT_VT_I8
#endif

#ifndef AtlThrow
#ifndef _ATL_CUSTOM_THROW
#define AtlThrow ATL::AtlThrowImpl
#endif
#endif // AtlThrow

#ifndef ATLASSERT
#define ATLASSERT(expr) _ASSERTE(expr)
#endif // ATLASSERT


#ifndef ATLASSUME
#define ATLASSUME(expr) do { ATLASSERT(expr); _Analysis_assume_(!!(expr)); } /*__pragma(warning(suppress:4127))*/ while (0)
#endif // ATLASSUME

#ifndef ATLVERIFY
#ifdef _DEBUG
#define ATLVERIFY(expr) ATLASSERT(expr)
#else
#define ATLVERIFY(expr) (expr)
#endif // DEBUG
#endif // ATLVERIFY

#ifndef ATLENSURE_THROW
#define ATLENSURE_THROW(expr, hr)          \
do {                                       \
	int __atl_condVal=!!(expr);            \
	ATLASSUME(__atl_condVal);              \
	if(!(__atl_condVal)) AtlThrow(hr);     \
} /*__pragma(warning(suppress:4127))*/ while (0)
#endif // ATLENSURE_THROW

#ifndef ATLENSURE
#define ATLENSURE(expr) ATLENSURE_THROW(expr, E_FAIL)
#endif // ATLENSURE

#ifndef ATLENSURE_SUCCEEDED
#define ATLENSURE_SUCCEEDED(hrExpr)								\
do {															\
	HRESULT __atl_hresult = (hrExpr);							\
	ATLENSURE_THROW(SUCCEEDED(__atl_hresult), __atl_hresult);   \
} /*__pragma(warning(suppress:4127))*/ while (0)
#endif // ATLENSURE_SUCCEEDED

#ifndef ATLENSURE_RETURN_VAL
#define ATLENSURE_RETURN_VAL(expr, val)        \
do {                                           \
	int __atl_condVal=!!(expr);                \
	ATLASSERT(__atl_condVal);                  \
	if(!(__atl_condVal)) return val;           \
} /*__pragma(warning(suppress:4127))*/ while (0)
#endif // ATLENSURE_RETURN_VAL

#ifndef ATLENSURE_RETURN
#define ATLENSURE_RETURN(expr) ATLENSURE_RETURN_HR(expr, E_FAIL)
#endif // ATLENSURE_RETURN

#ifndef ATLENSURE_RETURN_HR
#define ATLENSURE_RETURN_HR(expr, hr) ATLENSURE_RETURN_VAL(expr, hr)
#endif // ATLENSURE_RETURN_HR

#ifndef ATL_CRT_ERRORCHECK
#define ATL_CRT_ERRORCHECK(expr) AtlCrtErrorCheck(expr)
#endif // ATL_CRT_ERRORCHECK

#ifndef ATL_CRT_ERRORCHECK_SPRINTF
#define ATL_CRT_ERRORCHECK_SPRINTF(expr) \
do { \
	errno_t _saveErrno = errno; \
	errno = 0; \
	(expr); \
	if(0 != errno) \
	{ \
		AtlCrtErrorCheck(errno); \
	} \
	else \
	{ \
		errno = _saveErrno; \
	} \
} /*__pragma(warning(suppress:4127))*/ while (0)
#endif // ATL_CRT_ERRORCHECK_SPRINTF

#ifdef _ATL_DISABLE_NO_VTABLE
#define ATL_NO_VTABLE
#else
#define ATL_NO_VTABLE __declspec(novtable)
#endif

#ifdef _ATL_DISABLE_NOTHROW
#define ATL_NOTHROW
#else
#define ATL_NOTHROW __declspec(nothrow)
#endif

#ifdef _ATL_DISABLE_FORCEINLINE
#define ATL_FORCEINLINE
#else
#define ATL_FORCEINLINE __forceinline
#endif

#ifdef _ATL_DISABLE_NOINLINE
#define ATL_NOINLINE
#else
#define ATL_NOINLINE __declspec( noinline )
#endif

#ifdef _ATL_DISABLE_DEPRECATED
#define ATL_DEPRECATED(_Message)
#else
#define ATL_DEPRECATED(_Message) __declspec( deprecated(_Message) )
#endif

#ifdef _ATL_DEBUG_REFCOUNT
#ifndef _ATL_DEBUG_INTERFACES
#define _ATL_DEBUG_INTERFACES
#endif
#endif

#ifdef _DEBUG
#ifndef _ATL_DEBUG
#define _ATL_DEBUG
#endif // _ATL_DEBUG
#endif // _DEBUG

#ifdef _ATL_DEBUG_INTERFACES
#ifndef _ATL_DEBUG
#define _ATL_DEBUG
#endif // _ATL_DEBUG
#endif // _ATL_DEBUG_INTERFACES

#ifndef _ATL_HEAPFLAGS
#ifdef _MALLOC_ZEROINIT
#define _ATL_HEAPFLAGS HEAP_ZERO_MEMORY
#else
#define _ATL_HEAPFLAGS 0
#endif
#endif

#define _ATL_PACKING 8

#define ATLAPI __declspec(nothrow) HRESULT __stdcall
#define ATLAPI_(x) __declspec(nothrow) x __stdcall
#define ATLAPIINL ATLAPI
#define ATLAPIINL_(x) ATLAPI_(x)
#define ATLINLINE inline

#ifdef _ATL_NO_EXCEPTIONS
	#ifdef _AFX
	#error MFC projects cannot define _ATL_NO_EXCEPTIONS
	#endif
#else
	#ifndef _CPPUNWIND
	#define _ATL_NO_EXCEPTIONS
	#endif
#endif

#ifdef _CPPUNWIND

#ifndef ATLTRYALLOC

#ifdef _AFX
#define ATLTRYALLOC(x) try{x;} catch(CException* e){e->Delete();}
#else

#define ATLTRYALLOC(x) /*__pragma(warning(push)) __pragma(warning(disable: 4571))*/ try{x;} catch(...) {} /*__pragma(warning(pop))*/
#endif	//__AFX

#endif	//ATLTRYALLOC

#ifndef _ATLTRY
#define _ATLTRY try
#ifdef _AFX
#define _ATLCATCH( e ) catch( CException* e )
#else
#define _ATLCATCH( e ) catch( CAtlException e )
#endif

#define _ATLCATCHALL() /*__pragma(warning(push)) __pragma(warning(disable: 4571))*/ catch( ... ) /*__pragma(warning(pop))*/

#ifdef _AFX
#define _ATLDELETEEXCEPTION(e) e->Delete();
#else
#define _ATLDELETEEXCEPTION(e) e;
#endif

#define _ATLRETHROW throw
#endif	// _ATLTRY

#ifndef _ATL_COM_BEGIN
#define _ATL_COM_BEGIN \
	HRESULT __hrAtlComMethod = S_OK; \
	try \
	{
#endif

#ifdef _AFX

#define _AFX_COM_END_PART \
	catch(CException *e) \
	{ \
		if(e) \
		{ \
			e->Delete(); \
		} \
		__hrAtlComMethod = E_FAIL; \
	}
#else
#define _AFX_COM_END_PART \
	catch(CAtlException e) \
	{ \
		__hrAtlComMethod = e.m_hr; \
	}
#endif

#ifndef _ATL_COM_END
#define _ATL_COM_END \
	} \
	_AFX_COM_END_PART \
	catch(...) \
	{ \
		__hrAtlComMethod = E_FAIL; \
	} \
	return __hrAtlComMethod;
#endif

#else //_CPPUNWIND

#ifndef ATLTRYALLOC
#define ATLTRYALLOC(x) x;
#endif	//ATLTRYALLOC

#ifndef _ATLTRY
#define _ATLTRY
#define _ATLCATCH( e ) /*__pragma(warning(push)) __pragma(warning(disable: 4127))*/ if( false ) /*__pragma(warning(pop))*/
#define _ATLCATCHALL() /*__pragma(warning(push)) __pragma(warning(disable: 4127))*/ if( false ) /*__pragma(warning(pop))*/
#define _ATLDELETEEXCEPTION(e)
#define _ATLRETHROW
#endif	// _ATLTRY

#endif	//_CPPUNWIND

#ifndef ATLTRY
#define ATLTRY(x) ATLTRYALLOC(x)
#endif	//ATLTRY

#define offsetofclass(base, derived) ((DWORD_PTR)(static_cast<base*>((derived*)_ATL_PACKING))-_ATL_PACKING)

/////////////////////////////////////////////////////////////////////////////
// Main version numbers

#define _ATL     1
#define _ATL_VER 0x0E00

#ifndef _ATL_FILENAME_VER
#define _ATL_FILENAME_VER "140"
#endif

#ifndef _ATL_FILENAME_VER_NUM
#define _ATL_FILENAME_VER_NUM 140
#endif

#ifndef _ATL_VER_RBLD
#define _ATL_VER_RBLD "14.00"
#endif


/////////////////////////////////////////////////////////////////////////////
// Threading

#ifndef _ATL_SINGLE_THREADED
#ifndef _ATL_APARTMENT_THREADED
#ifndef _ATL_FREE_THREADED
#define _ATL_FREE_THREADED
#endif
#endif
#endif

// UUIDOF
#ifndef _ATL_NO_UUIDOF
#define _ATL_IIDOF(x) __uuidof(x)
#else
#define _ATL_IIDOF(x) IID_##x
#endif

// Lean and mean
#ifndef ATL_NO_LEAN_AND_MEAN
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMCX
#define NOMCX
#endif
#endif	// ATL_NO_LEAN_AND_MEAN

#ifdef NOSERVICE
#ifndef _ATL_NO_SERVICE
#define _ATL_NO_SERVICE
#endif	// _ATL_NO_SERVICE
#else
#ifdef _ATL_NO_SERVICE
#ifndef NOSERVICE
#define NOSERVICE
#endif	// NOSERVICE
#endif	// _ATL_NO_SERVICE
#endif	// NOSERVICE

#include <malloc.h>
#ifdef _DEBUG
#include <stdlib.h>
#endif
#ifndef _ATL_NO_DEBUG_CRT
	#include <crtdbg.h>
#endif

#endif // RC_INVOKED

#define ATLAXWIN_CLASS "AtlAxWin140"
#define ATLAXWINLIC_CLASS "AtlAxWinLic140"

#if defined(_ATL_SECURE_NO_DEPRECATE) && !defined(_ATL_SECURE_NO_WARNINGS)
#define _ATL_SECURE_NO_WARNINGS
#endif

// _ATL_INSECURE_DEPRECATE define
#ifndef _ATL_INSECURE_DEPRECATE
#ifdef _ATL_SECURE_NO_WARNINGS
#define _ATL_INSECURE_DEPRECATE(_Message)
#else
#define _ATL_INSECURE_DEPRECATE(_Message) __declspec(deprecated(_Message))
#endif // _ATL_SECURE_NO_WARNINGS
#endif // _ATL_INSECURE_DEPRECATE

#ifndef RC_INVOKED
 #if !defined(_ATL_FATAL_SHUTDOWN) && defined( _ATL_USE_WINAPI_FAMILY_DESKTOP_APP)
  #define _ATL_FATAL_SHUTDOWN do { ::TerminateProcess(::GetCurrentProcess(), 0); } /*__pragma(warning(suppress:4127))*/ while (0)
 #endif // _ATL_FATAL_SHUTDOWN
#endif // RC_INVOKED

#ifdef _ATL_ENABLE_PTM_WARNING
#define PTM_WARNING_DISABLE
#define PTM_WARNING_RESTORE
#else
#define PTM_WARNING_DISABLE \
	__pragma(warning( push )) \
	__pragma(warning( disable : 4867 ))
#define PTM_WARNING_RESTORE \
	__pragma(warning( pop ))
#endif //_ATL_ENABLE_PTM_WARNING

#define ATL_MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))
#define ATL_MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((WORD)(i))))
#ifdef UNICODE
#define ATL_MAKEINTRESOURCE  ATL_MAKEINTRESOURCEW
#else
#define ATL_MAKEINTRESOURCE  ATL_MAKEINTRESOURCEA
#endif // !UNICODE
#define ATL_IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16) == 0)

#if _MSC_VER >= 1900 && !defined(__EDG__)
#define _ATL_DECLSPEC_ALLOCATOR __declspec(allocator)
#else
#define _ATL_DECLSPEC_ALLOCATOR
#endif

#ifndef ATL_IUNKNOWN_NOEXCEPT
#define ATL_IUNKNOWN_NOEXCEPT
#endif


#define ATL_RT_CURSOR           ATL_MAKEINTRESOURCE(1)
#define ATL_RT_BITMAP           ATL_MAKEINTRESOURCE(2)
#define ATL_RT_ICON             ATL_MAKEINTRESOURCE(3)
#define ATL_RT_MENU             ATL_MAKEINTRESOURCE(4)
#define ATL_RT_DIALOG           ATL_MAKEINTRESOURCE(5)
#define ATL_RT_STRING           ATL_MAKEINTRESOURCE(6)
#define ATL_RT_FONTDIR          ATL_MAKEINTRESOURCE(7)
#define ATL_RT_FONT             ATL_MAKEINTRESOURCE(8)
#define ATL_RT_ACCELERATOR      ATL_MAKEINTRESOURCE(9)
#define ATL_RT_RCDATA           ATL_MAKEINTRESOURCE(10)
#define ATL_RT_MESSAGETABLE     ATL_MAKEINTRESOURCE(11)

#define ATL_DIFFERENCE     11
#define ATL_RT_GROUP_CURSOR ATL_MAKEINTRESOURCE((ULONG_PTR)ATL_RT_CURSOR + ATL_DIFFERENCE)
#define ATL_RT_GROUP_ICON   ATL_MAKEINTRESOURCE((ULONG_PTR)ATL_RT_ICON + ATL_DIFFERENCE)
#define ATL_RT_VERSION      ATL_MAKEINTRESOURCE(16)
#define ATL_RT_DLGINCLUDE   ATL_MAKEINTRESOURCE(17)
#define ATL_RT_PLUGPLAY     ATL_MAKEINTRESOURCE(19)
#define ATL_RT_VXD          ATL_MAKEINTRESOURCE(20)
#define ATL_RT_ANICURSOR    ATL_MAKEINTRESOURCE(21)
#define ATL_RT_ANIICON      ATL_MAKEINTRESOURCE(22)
#define ATL_RT_HTML         ATL_MAKEINTRESOURCE(23)

#define ATLPREFAST_SUPPRESS(x) /*__pragma(warning(push)) __pragma(warning(disable: x))*/
#define ATLPREFAST_UNSUPPRESS() /*__pragma(warning(pop))*/

#ifndef _FormatMessage_format_string_
#define _FormatMessage_format_string_
#endif

namespace ATL
{

ATLPREFAST_SUPPRESS(6001 6101)
template < typename T >
_Ret_maybenull_ _Post_writable_byte_size_(dwLen) inline __declspec(noalias) T* SAL_Assume_bytecap_for_opt_(
	_Out_writes_opt_(0) T* buf,
	_In_ size_t dwLen)
{
	(void)(dwLen);
	return buf;
}
ATLPREFAST_UNSUPPRESS()

template < typename T >
_Ret_z_ inline __declspec(noalias) T* SAL_Assume_notnull_for_opt_z_(_In_opt_z_ T* buf)
{
	ATLASSUME(buf!=0);
	return buf;
}

} // namespace ATL

#endif // __ATLDEF_H__


#define AtlGetProcAddressFn(hinst, fn) reinterpret_cast<decltype(::fn)*>(GetProcAddress(hinst, #fn))

#ifndef _WINSOCKAPI_
#include <WinSock2.h>
#endif
#include <Windows.h>

namespace ATL
{
#ifndef _ATL_CUSTOM_THROW
ATL_NOINLINE __declspec(noreturn) inline void WINAPI AtlThrowImpl(_In_ HRESULT hr);
#endif // _ATL_CUSTOM_THROW

ATL_NOINLINE __declspec(noreturn) inline void WINAPI AtlThrowLastWin32();
}

