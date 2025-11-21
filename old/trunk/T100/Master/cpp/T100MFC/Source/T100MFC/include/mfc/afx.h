#ifndef AFX_H
#define AFX_H


//test
#include <crtdbg.h>
#include <windows.h>
#undef _DLL
///
#include <afxver_.h>
#include <afxstr.h>

#include <atltransactionmanager.h>

#include <atltrace.h>
#include <atltypes.h>










#ifndef __cplusplus
    #error MFC requires C++ compilation (use a .cpp suffix)
#endif // __cplusplus

#pragma once

#ifdef _DLL
#ifndef _AFXDLL
#error Building MFC application with /MD[d] (CRT dll version) requires MFC shared dll version. Please #define _AFXDLL or do not use /MD[d]
#endif
#endif // _DLL

#if !defined(_M_IX86) && !defined(_M_X64) && !defined(_M_ARM) && !defined(_M_ARM64)
	#error Compiling for unsupported platform.  Only x86, x64, ARM, and ARM64 platforms are supported by MFC.
#endif

#if defined(_MANAGED) && !defined(_M_IX86) && !defined(_M_X64) && !defined(_M_ARM64)
	#error Compiling for unsupported platform.  Managed MFC only supports x86, x64 and arm64 platforms.
#endif

#ifndef _NATIVE_WCHAR_T_DEFINED
#define _AFX_FULLTYPEINFO
#endif // _NATIVE_WCHAR_T_DEFINED

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif // _AFX_MINREBUILD

#ifdef __ATLDBGMEM_H__
#error <atldbgmem.h> cannot be used in MFC projects. See AfxEnableMemoryTracking
#endif

#ifndef _ATL_DISABLE_NOTHROW_NEW
#define _ATL_DISABLE_NOTHROW_NEW
#endif // _ATL_DISABLE_NOTHROW_NEW

#if defined(_MFC_DLL_BLD) && defined(_DEBUG)
#ifndef _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC
#endif // _CRTDBG_MAP_ALLOC
#endif // defined

#ifndef _INC_NEW
    #include <new.h>
#endif // _INC_NEW

#if defined(_MFC_BLD)
#define ISOLATION_AWARE_ENABLED     1
#endif // defined

#include <afxver_.h>

#if defined(_WIN64) || defined(_M_ARM)
#ifndef _AFX_NO_DAO_SUPPORT
#define _AFX_NO_DAO_SUPPORT
#endif // _AFX_NO_DAO_SUPPORT
#endif // defined

#ifndef _AFX_NOFORCE_LIBS

/*============================================================================*/
// Win32 libraries

#ifndef _AFXDLL
    #ifdef _AFX_NO_MFC_CONTROLS_IN_DIALOGS
        #ifdef _DEBUG
            #pragma comment(lib, "afxnmcdd.lib")
        #else
            #pragma comment(lib, "afxnmcd.lib")
        #endif // _DEBUG
        #pragma comment(linker, "/include:__afxNoMFCControlSupportInDialogs")
        #pragma commont(linker, "/include:__afxNoMFCControlSupportInDialogs")
    #endif // _AFX_NO_MFC_CONTROLS_IN_DIALOGS
    #ifndef _UNICODE
        #ifdef _DEBUG
            #pragma comment(lib, "nafxcwd.lib")
        #else
            #pragma comment(lib, "nafxcw.lib")
        #endif // _DEBUG
    #else
        #ifdef _DEBUG
            #pragma comment(lib, "uafxcwd.lib")
        #else
            #pragma comment(lib, "uafxcw.lib")
        #endif // _DEBUG
    #endif // _UNICODE
#else
    #ifndef _UNICODE
        #ifdef _DEBUG
            #pragma comment(lib, "mfc" _MFC_FILENAME_VER "d.lib")
            #pragma comment(lib, "mfcs" _MFC_FILENAME_VER "d.lib")
        #else
            #pragma comment(lib, "mfc" _MFC_FILENAME_VER ".lib)
            #pragma comment(lib, "mfcs" _MFC_FILENAME_VER ".lib)
        #endif // _DEBUG
    #else
        #ifdef _DEBUG
            #pragma comment(lib, "mfc" _MFC_FILENAME_VER "ud.lib")
            #pragma comment(lib, "mfcs" _MFC_FILENAME_VER "u.lib)
        #endif // _DEBUG
    #endif // _UNICODE
#endif // _AFXDLL

#ifdef _DLL
    #if defined(_DEBUG)
        #pragma comment(lib, "msvcrtd.lib")
    #else
        #pragma comment(lib, "msvcrt.lib")
    #endif // defined
#else
    #if defined(_DEBUG)
        #pragma comment(lib, "libcmtd.lib")
    #else
        #pragma comment(lib, "libcmt.lib")
    #endif // defined
#endif // _DLL

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "msimg32.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "winspool.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "uxtheme.lib")
#pragma comment(lib, "windowscodecs.lib")

#pragma comment(linker, "/include:__afxForceEXCLUDE")

#ifdef _USRDLL
#pragma comment(linker, "/include:__afxForceUSRDLL")
#endif // _USRDLL

#ifdef _AFXDLL
#pragma comment(linker, "/include:__afxForceSTDAFX")
#endif // _AFXDLL

#endif // _AFX_NOFORCE_LIBS

#ifdef _MANAGED
#ifndef AFX_NO_CLR_COINIT_STA
#pragma commect(linker, "/CLRTHREADATTRIBUTE:STA")
#endif // AFX_NO_CLR_COINIT_STA

#endif // _MANAGED


/*============================================================================*/
// Classes declared in this file
//   in addition to standard primitive data types and various helper macros

struct CRuntimeClass;

class CObject;

    class CException;
        class CArchiveException;
        class CFileException;
        class CSimpleException;
            class CMemoryException;
            class CNotSupportedException;
            class CInvalidArgException;

    class CFile;
        class CStdioFile;
        class CMemFile;

struct CFileStatus;
struct CMemoryState;

class CArchive;
class CDumpContext;

/*============================================================================*/
// Other includes from standard "C" runtimes

#ifndef _INC_STRING
    #include <string.h>
#endif // _INC_STRING
#ifndef _INC_STDIO
    #include <stdio.h>
#endif // _INC_STDIO
#ifndef _INC_STDLIB
    #include <stdlib.h>
#endif // _INC_STDLIB
#ifndef _INC_TIME
    #include <time.h>
#endif // _INC_TIME
#ifndef _INC_LIMITS
    #include <limits.h>
#endif // _INC_LIMITS
#ifndef _INC_STDDEF
    #include <stddef.h>
#endif // _INC_STDDEF
#ifndef _INC_STDARG
    #include <stdarg.h>
#endif // _INC_STDARG
#ifndef _INC_ERRNO
    #include <errno.h>
#endif // _INC_ERRNO

#include <malloc.h>

#ifndef _INC_CRTDBG
    #include <crtdbg.h>
#endif // _INC_CRTDBG

#ifdef _AFX_OLD_EXCEPTIONS
#error MFC no longer supports setjmp/longjmp exception handling.
#endif // _AFX_OLD_EXCEPTIONS

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif // _AFX_PACKING

/*============================================================================*/
// Basic types
// abstract iteration position

struct __POSITION {};
typedef __POSITION* POSITION;

#undef FALSE
#undef TRUE
#undef NULL

#define FALSE   0
#define TRUE    1
#define NULL    0


/*============================================================================*/
// _AFX_FUNCNAME definition
#ifdef UNICODE
#define _AFX_FUNCNAME(_Name) _Name##W
#else
#define _AFX_FUNCNAME(_Name) _Name##A
#endif // UNICODE

/*============================================================================*/
// Turn off warnings for /W4
// To resume any of these warning: #pragma warning(default: 4xxx)
// which should be placed after the AFX include files

#pragma warning(disable : 4505)
#pragma warning(disable : 4511)
#pragma warning(disable : 4512)
#pragma warning(disable : 4514)
#pragma warning(disable : 4710)
#pragma warning(disable : 4127)

#ifdef _AFXDLL
#pragma warning(disable : 4275)
#pragma warning(disable : 4251)
#endif // _AFXDLL

#ifdef _AFX_ALL_WARNINGS
#pragma warning( push )
#endif // _AFX_ALL_WARNINGS


#pragma warning(disable : 4201)
#pragma warning(disable : 4191)
#ifndef _DEBUG
#pragma warning(disable : 4701)
#pragma warning(disable : 4702)
#pragma warning(disable : 4189)
#pragma warning(disable : 4390)
#endif // _DEBUG

#ifdef _AFXDLL
#pragma warning(disable : 4204)
#endif // _AFXDLL
#pragma warning(disable : 4263 4264 4266)

/*============================================================================*/
// Diagnostic support

#ifdef _DEBUG

#define _CrtDbgReport(a, b, c, d, e)    TRUE

inline BOOL AFXAPI AfxAssertFailedLine(LPCSTR lpszFileName, int nLine)
{
    MSG         msg;
    BOOL        bQuit   = PeekMessage(&msg, NULL, WM_QUIT, WM_QUIT, PM_REMOVE);
    BOOL        bResult = _CrtDbgReport(_CRT_ASSERT, lpszFileName, nLine, NULL, NULL);
    if(bQuit)
        PostQuitMessage((int)msg.wParam);
    return bResult;
}

void    AFX_CDECL AfxTrace(LPCTSTR lpszFormat, ...);

void    AFXAPI AfxAssertValidObject(const CObject* pOb,
            LPCSTR lpszFileName, int nLine);

void    AFXAPI AfxDump(const CObject* pOb);

#include <atltrace.h>

#define TRACE   ATLTRACE

#define THIS_FILE           __FILE__
#define VERIFY(f)           ASSERT(f)
#define DEBUG_ONLY(f)       (f)


#define TRACE0(sz)                  TRACE(_T("%Ts", _T(sz))
#define TRACE1(sz, p1)              TRACE(_T(sz), p1)
#define TRACE2(sz, p1, p2)          TRACE(_T(sz), p1, p2)
#define TRACE3(sz, p1, p2, p3)      TRACE(_T(sz), p1, p2, p3)

#define AFX_DUMP0(dc, sz)           dc << _T(sz)
#define AFX_DUMP1(dc, sz, p1)       dc << _T(sz) << p1

#else

#define VERIFY(f)           ((void)(f))
#define DEBUG_ONLY(f)       ((void)0)
#pragma warning( push )
#pragma warning(disable : 4793)
inline void AFX_CDECL AfxTrace(...) {}
#pragma warning( pop )
#define TRACE           __noop
#define TRACE0(sz)
#define TRACE1(sz, p1)
#define TRACE2(sz, p1, p2)
#define TRACE3(sz, p1, p2, p3)

#endif // _DEBUG

#define ASSERT(f)   DEBUG_ONLY((void)((f) || !::AfxAssertFailedLine(THIS_FILE, __LINE__) || (AfxDebugBreak(), 0)))

#if defined(_PREFAST_) || defined(_DEBUG)
#define AFXASSUME(cond) \
    do { bool __afx_condVal=!!(cond); ASSERT(__afx_condVal); \
        _Analysis_assume_(__afx_condVal); } \
        /*__pragma(warning(suppress:4127))*/ \
        while(0)

#else
#define AFXASSUME(cond)     ((void)0)
#endif // definde

#define ASSERT_VALID(pOb)  DEBUG_ONLY((::AfxAssertValidObject(pOb, THIS_FILE, __LINE__)))

#define ENSURE_THROW(cond, exception)	\
	do { int __afx_condVal=!!(cond); ASSERT(__afx_condVal); if (!(__afx_condVal)){exception;} } /*__pragma(warning(suppress:4127))*/ while (false)

#define ENSURE(cond)        ENSURE_THROW(cond, ::AfxThrowInvalidArgException() )
#define ENSURE_ARG(cond)    ENSURE_THROW(cond, ::AfxThrowInvalidArgException() )

#define ENSURE_VALID_THROW(pOb, exception) \
    do { ASSERT_VALID(pOb); if (!(pOb)){exception;} } \
        /*__pragma(warning(suppress:4127))*/ while (fasle)

#define ENSURE_VALID(pOb)   ENSURE_VALID_THROW(pOb, ::AfxThrowInvalidArgException() )

#define ASSERT_POINTER(p, type) \
    ASSERT(((p) != NULL) && AfxIsValidAddress((p), sizeof(type), FALSE))

#define ASSERT_NULL_OR_POINTER(p, type) \
    ASSERT(((p) == NULL) || AfxIsValidAddress((p), sizeof(type), FALSE))

#ifdef _DEBUG
#define UNUSED(x)
#else
#define UNUSED(x)           UNREFERENCED_PARAMETER(x)
#endif // _DEBUG
#define UNUSED_ALWAYS(x)    UNREFERENCED_PARAMETER(x)

#ifdef _DEBUG
#define REPORT_EXCEPTION(pException, szMsg) \
    do { \
        TCHAR szErrorMessage[512]; \
        if(pException->GetErrorMessage(szErrorMessage, sizeof(szErrorMessage) / sizeof(*szErrorMessage), 0)) \
            TRACE(traceAppMsg, 0, _T("%Ts ("%Ts:%d)\n%Ts\n"), szMsg, _T(__FILE__), __LINE__, szErrorMessage); \
        else \
            TRACE(traceAppMsg, 0, _T("%Ts (%Ts:%d)\n"), szMsg, _T(__FILE__), __LINE__); \
        ASSERT(FALSE); \
        /*__pragma(warning(suppress : 4127))*/ \
    } while (0)
#else
#define REPORT_EXCEPTION(pException, szMsg) \
    do { \
        CString strMsg; \
        TCHAR szErrorMessage[512]; \
        if(pException->GetErrorMessage(szErrorMessage, sizeof(szErrorMessage) / sizeof(*szErrorMessage), 0)) \
            strMsg.Format(_T("%Ts ("%Ts:%d)\n%Ts"), szMsg, _T(__FILE__), __LINE__, szErrorMessage); \
        else \
            strMsg.Format(_T("%Ts (%Ts:%d)"), szMsg, _T(__FILE__), __LINE__); \
        AfxMessageBox(strMsg); \
        /*__pragma(warning(suppress : 4127))*/ \
    } while (0)
#endif // _DEBUG

#define EXCEPTION_IN_DTOR(pException) \
    do { \
        REPORT_EXCEPTION((pException), _T("Exception thrown in destructor")); \
        delete pException; \
        /*__pragma(warning(suppress : 4127))*/ \
    } while (0)

#define AFX_BEGIN_DESTRUCTOR    try {
#define AFX_END_DESTRUCTOR      } catch (CException* pException) { EXCEPTION_IN_DTOR(pException); }

/*============================================================================*/
// Other implementation helpers
#define BEFORE_START_POSITION   ((POSITION)-1L)

/*============================================================================*/
// explicit initialization for general purpose classes
BOOL AFXAPI AfxInitialize(BOOL bDLL = FALSE, DWORD dwVersion = _MFC_VER);

#undef AFX_DATA
#define AFX_DATA AFX_CORE_DATA

/*============================================================================*/
// Basic object model

void AFXAPI AfxClassInit(CRuntimeClass* pNewClass);
struct AFX_CLASSINIT
    {
        AFX_CLASSINIT(CRuntimeClass* pNewClass)
            {
                AfxClassInit(pNewClass);
            }
    };

struct CRuntimeClass
{
    LPCSTR          m_lpszClassName;
    int             m_nObjectSize;
    UINT            m_wSchema;
    CObject* (PASCAL* m_pfnCreateObject)();
#ifdef _AFXDLL
    CRuntimeClass* (PASCALL* m_pfnGetBaseClass)();
#else
    CRuntimeClass*  m_pBaseClass;
#endif // _AFXDLL

    CObject*        CreateObject();
    BOOL            IsDerivedFrom(const CRuntimeClass* pBaseClass) const;

    static CRuntimeClass* PASCAL FromName(LPCSTR lpszClassName);
    static CRuntimeClass* PASCAL FromName(LPCWSTR lpszClassName);
    static CObject* PASCAL CreateObject(LPCSTR lpszClassName);
    static CObject* PASCAL CreateObject(LPCWSTR lpszClassName);

    void            Store(CArchive& ar) const;
    static          CRuntimeClass* PASCAL Load(CArchive& ar, UINT* pwSchemaNum);

    CRuntimeClass*  m_pNextClass;
    const AFX_CLASSINIT* m_pClassInit;
};

/*============================================================================*/
// Standard exception throws
void __declspec(noreturn) AFXAPI AfxThrowMemoryException();
void __declspec(noreturn) AFXAPI AfxThrowNotSupportedException();
void __declspec(noreturn) AFXAPI AfxThrowInvalidArgException();
void __declspec(noreturn) AFXAPI AfxThrowArchiveException(int cause, LPCTSTR lpszArchiveName = NULL);
void __declspec(noreturn) AFXAPI AfxThrowFileException(int cause, LONG lOsError = -1,
    LPCTSTR lpszFileName = NULL);
void __declspec(noreturn) AFXAPI AfxThrowOleException(LONG sc);

/*============================================================================*/
// CRT functions

inline errno_t AfxCrtErrorCheck(errno_t error)
{
    switch(error)
    {
    case ENOMEM:
        AfxThrowMemoryException();
        break;
    case EINVAL:
    case ERANGE:
        AfxThrowInvalidArgException();
        break;
    case STRUNCATE:
    case 0:
        break;
    default:
        AfxThrowInvalidArgException();
        break;
    }
    return error;
}

#define AFX_CRT_ERRORCHECK(expr) \
    AfxCrtErrorCheck(expr)

inline void __cdecl Afx_clearerr_s(FILE* stream)
{
    AFX_CRT_ERRORCHECK(::clearerr_s(stream));
}

/*============================================================================*/
// Strings

#ifndef _OLEAUTO_H_
    typedef _Null_terminated_ LPWSTR BSTR;
#endif // _OLEAUTO_H_

/*============================================================================*/
// class CObject is the root of all compliant objects

class AFX_NOVTABLE CObject
{
public:
    virtual CRuntimeClass* GetRuntimeClass() const;
    virtual ~CObject() = 0;

    void* PASCAL operator new(size_t nSize);
    void* PASCAL operator new(size_t, void* p);
    void PASCAL operator delete(void* p);
    void PASCAL operator delete(void* p, void* pPlace);

#if defined(_DEBUG)
    void* PASCAL operator new(size_t nSize, LPCSTR lpszFileName, int nLine);
    void PASCAL operator delete(void* p, LPCSTR lpszFileName, int nLine);
#endif // defined

protected:
    CObject();
private:
    CObject(const CObject& objectSrc);
    void operator=(const CObject& objectSrc);

public:
    BOOL        IsSerializable() const;
    BOOL        IsKindOf(const CRuntimeClass* pClass) const;

    virtual void Serialize(CArchive& ar);

#if defined(_DEBUG) || defined(_AFXDLL)
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif // defined

public:
    static const CRuntimeClass classCObject;
#ifdef _AFXDLL
    static CRuntimeClass* PASCAL _GetBaseClass();
    static CRuntimeClass* PASCAL GetThisClass();
#endif // _AFXDLL
};

// Helper macros
#define _RUNTIME_CLASS(class_name) ((CRuntimeClass*)(&class_name::class##class_name))
#ifdef _AFXDLL
#define RUNTIME_CLASS(class_name) (class_name::GetThisClass())
#else
#define RUNTIME_CLASS(class_name) _RUNTIME_CLASS(class_name)
#endif // _AFXDLL
#define ASSERT_KINDOF(class_name, object) \
    ASSERT((object)->IsKindOf(RUNTIME_CLASS(class_name)))

// RTTI helper macros/functions
const CObject* AFX_CDECL AfxDynamicDownCast(CRuntimeClass* pClass, const CObject* pObject);
CObject* AFX_CDECL AfxDynamicDownCast(CRuntimeClass* pClass, CObject* pObject);
#define DYNAMIC_DOWNCAST(class_name, object) \
    (class_name*)AfxDynamicDownCast(RUNTIME_CLASS(class_name), object)

#ifdef _DEBUG
const CObject* AFX_CDECL AfxStaticDownCast(CRuntimeClass* pClass, const CObject* pObject);
CObject* AFX_CDECL AfxStaticDownCast(CRuntimeClass* pClass, CObject* pObject);
#define STATIC_DOWNCAST(class_name, object) \
    (static_cast<class_name*>(AfxStaticDownCast(RUNTIME_CLASS(class_name), object)))
#else
#define STATIC_DOWNCAST(class_name, object)(static_cast<class_name*>(object))
#endif // _DEBUG


/*============================================================================*/
// Helper macros for declaring CRuntimeClass compatible classes

#ifdef _AFXDLL
#define DECLARE_DYNAMIC(class_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
	static const CRuntimeClass class##class_name; \
	static CRuntimeClass* PASCAL GetThisClass(); \
	/*__pragma(warning(suppress:26433))*/ \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define _DECLARE_DYNAMIC(class_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
	static CRuntimeClass class##class_name; \
	static CRuntimeClass* PASCAL GetThisClass(); \
	/*__pragma(warning(suppress:26433))*/ \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#else
#define DECLARE_DYNAMIC(class_name) \
public: \
	static const CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define _DECLARE_DYNAMIC(class_name) \
public: \
	static CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#endif

// not serializable, but dynamically constructable
#define DECLARE_DYNCREATE(class_name) \
	DECLARE_DYNAMIC(class_name) \
	static CObject* PASCAL CreateObject();

#define _DECLARE_DYNCREATE(class_name) \
	_DECLARE_DYNAMIC(class_name) \
	static CObject* PASCAL CreateObject();

#define DECLARE_SERIAL(class_name) \
	_DECLARE_DYNCREATE(class_name) \
	AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, class_name* &pOb);

#ifdef _AFXDLL
#define IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	CRuntimeClass* PASCAL class_name::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			&class_name::_GetBaseClass, NULL, class_init }; \
	CRuntimeClass* PASCAL class_name::GetThisClass() \
		{ return _RUNTIME_CLASS(class_name); } \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS(class_name); }

#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	CRuntimeClass* PASCAL class_name::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	AFX_COMDAT CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			&class_name::_GetBaseClass, NULL, class_init }; \
	CRuntimeClass* PASCAL class_name::GetThisClass() \
		{ return _RUNTIME_CLASS(class_name); } \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS(class_name); }

#else
#define IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); }

#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); }

#endif

#define IMPLEMENT_DYNAMIC(class_name, base_class_name) \
	IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL, NULL)

#define IMPLEMENT_DYNCREATE(class_name, base_class_name) \
	CObject* PASCAL class_name::CreateObject() \
		{ return new class_name; } \
	IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, \
		class_name::CreateObject, NULL)

#define IMPLEMENT_SERIAL(class_name, base_class_name, wSchema) \
	CObject* PASCAL class_name::CreateObject() \
		{ return new class_name; } \
	extern AFX_CLASSINIT _init_##class_name; \
	_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, \
		class_name::CreateObject, &_init_##class_name) \
	AFX_CLASSINIT _init_##class_name(RUNTIME_CLASS(class_name)); \
	CArchive& AFXAPI operator>>(CArchive& ar, class_name* &pOb) \
		{ pOb = (class_name*) ar.ReadObject(RUNTIME_CLASS(class_name)); \
			return ar; }

// optional bit for schema number that enables object versioning
#define VERSIONABLE_SCHEMA  (0x80000000)

/*============================================================================*/
// Exceptions

class AFX_NOVTABLE CException : public CObject
{
    DECLARE_DYNAMIC(CException)

public:
    CException();
    explicit CException(BOOL bAutoDelete);

    void        Delete();

    _Success_(return != 0)
    virtual BOOL GetErrorMessage(_Out_writes_z_(nMaxError) LPTSTR lpszError,
        _In_ UINT nMaxError, _Out_opt_ PUINT pnHelpContext = NULL) const;
    _Success_(return != 0)
    virtual BOOL GetErrorMessage(_Out_writes_z_(nMaxError) LPTSTR lpszError,
        _In_ UINT nMaxError, _Out_opt_ PUINT pnHelpContext = NULL);
    virtual int ReportError(UINT nType = MB_OK, UINT nMessageID = 0);

public :
    virtual ~CException() = 0;
    BOOL        m_bAutoDelete;
#ifdef _DEBUG
    void PASCAL operator delete(void* pbData);
    void PASCAL operator delete(void* pbData, LPCSTR lpszFileName, int nLine);
protected:
    BOOL        m_bReadyForDelete;
#endif // _DEBUG
};

#include <afxstr.h>

// ATL Classes
class CSimpleException : public CException
{
    DECLARE_DYNAMIC(CSimpleException)

public:
    CSimpleException();
    explicit CSimpleException(BOOL bAutoDelete);

    _Success_(return != 0)
    BOOL GetErrorMessage(_Out_writes_z_(nMaxError) LPTSTR lpszError,  _In_ UINT nMaxError,
        _Out_opt_ PUINT pnHelpContext = NULL) const override;

public:
    virtual ~CSimpleException() = 0;
    BOOL        m_bAutoDelete;

    void        InitString();

protected:
    BOOL        m_bInitialized;
    BOOL        m_bLoaded;
    TCHAR       m_szMessage[128];
    UINT        m_nResourceID;

#ifdef _DEBUG
    BOOL        m_bReadyForDelete;
#endif // _DEBUG
};


void AFXAPI AfxThrowLastCleanup();

void AFXAPI AfxTryCleanup();

#ifndef _AFX_JUMPBUF
#define _AFX_JUMPBUF    jmp_buf
#endif // _AFX_JUMPBUF


struct AFX_EXCEPTION_LINK
{
    AFX_EXCEPTION_LINK*     m_pLinkPrev;
    CException*             m_pException;

    AFX_EXCEPTION_LINK();
    ~AFX_EXCEPTION_LINK()
        {
            AfxTryCleanup();
        }
};


struct AFX_EXCEPTION_CONTEXT
{
    AFX_EXCEPTION_LINK*     m_pLinkTop;
};

#ifndef _PNH_DEFINED
typedef int (__cdecl * _PNH)( size_t )
#define _PNH_DEFINED
#endif // _PNH_DEFINED

_PNH AFXAPI AfxGetNewHandler();
_PNH AFXAPI AfxSetNewHandler(_PNH pfnNewHandler);
int AFX_CDECL AfxNewHandler(size_t nSize);

void AFXAPI AfxAbort();


/*============================================================================*/
// Exception macros using try, catch and throw
//  (for backward compatibility to previous versions of MFC)

#define TRY { AFX_EXCEPTION_LINK _afxExceptionLink; try {

#define CATCH(class, e) } catch (class* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(class))); \
		_afxExceptionLink.m_pException = e;

#define AND_CATCH(class, e) } catch (class* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(class))); \
		_afxExceptionLink.m_pException = e;

#define END_CATCH } }

#define THROW(e) throw e
#define THROW_LAST() (AfxThrowLastCleanup(), throw)

// Advanced macros for smaller code
#define CATCH_ALL(e) } catch (CException* e) \
	{ { ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); \
		_afxExceptionLink.m_pException = e;

#define AND_CATCH_ALL(e) } catch (CException* e) \
	{ { ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); \
		_afxExceptionLink.m_pException = e;

#define END_CATCH_ALL } } }

#define END_TRY } catch (CException* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); \
		_afxExceptionLink.m_pException = e; } }

/*============================================================================*/
// Standard Exception classes

class CMemoryException : public CSimpleException
{
    DECLARE_DYNAMIC(CMemoryException)

public:
    CMemoryException();

public:
    explicit CMemoryException(BOOL bAutoDelete);
    CMemoryException(BOOL bAutoDelete, UINT nResourceID);
    virtual ~CMemoryException();
};

class CNotSupportedException : public CSimpleException
{
    DECLARE_DYNAMIC(CNotSupportedException)

public:
    CNotSupportedException();

public:
    explicit CNotSupportedException(BOOL bAutoDelete);
    CNotSupportedException(BOOL bAutoDelete, UINT nResourceID);
    virtual ~CNotSupportedException();
};

class CInvalidArgException : public CSimpleException
{
    DECLARE_DYNAMIC(CInvalidArgException)

public:
    CInvalidArgException();

public:
    CInvalidArgException(BOOL bAutoDelete);
    CInvalidArgException(BOOL bAutoDelete, UINT nResourceID);
    virtual ~CInvalidArgException();
};

class CArchiveException : public CException
{
    DECLARE_DYNAMIC(CArchiveException)

public:
    enum {
        none,
        genericException,
        readOnly,
        endOfFile,
        writeOnly,
        badIndex,
        badClass,
        badSchema,
        bufferFull
    };

#pragma warning( push )
#pragma warning(disable : 4996)
	//AFX_DEPRECATED("CArchiveException::generic clashes with future language keyword generic and should not be used. Use CArchiveException::genericException instead.") static const int __identifier(generic) = genericException;
#pragma warning( pop )

    explicit CArchiveException(int cause = CArchiveException::none,
        LPCTSTR lpszArchiveName = NULL);

    int         m_cause;
    CString     m_strFileName;

public:
    virtual ~CArchiveException();
#ifdef _DEBUG
    void Dump(CDumpContext& dc) const override;
#endif // _DEBUG
    _Success_(return != 0)
    BOOL GetErrorMessage(_Out_writes_z_(nMaxError) LPTSTR lpszError, _In_ UINT nMaxError,
        _Out_opt_ PUINT pnHelpContext = NULL) const override;
};

class CFileException : public CException
{
    DECLARE_DYNAMIC(CFileException)

public:
    enum {
        none,
        genericException,
        fileNotFound,
        badPath,
        tooManyOpenFiles,
        accessDenied,
        invalidFile,
        removeCurrentDir,
        directoryFull,
        badSeek,
        hardIO,
        sharingViolation,
        lockViolation,
        diskFull,
        endOfFile
    };

#pragma warning( push )
#pragma warning(disable : 4996)
	//AFX_DEPRECATED("CFileException::generic clashes with future language keyword generic and should not be used. Use CFileException::genericException instead.") static const int __identifier(generic) = genericException;
#pragma warning( pop )

    explicit CFileException(int cause = CFileException::none, LONG lOsError = -1,
        LPCTSTR lpszArchiveName = NULL);

    int         m_cause;
    LONG        m_lOsError;
    CString     m_strFileName;

    static int PASCAL OsErrorToException(LONG lOsError);
    static int PASCAL ErrnoToException(int nErrno);

    [[noreturn]] static void PASCAL ThrowOsError(LONG lOsError, LPCTSTR lpszFileName = NULL);
	static void PASCAL ThrowErrno(int nErrno, LPCTSTR lpszFileName = NULL);

public:
    virtual ~CFileException();
#ifdef _DEBUG
    void Dump(CDumpContext& dc) const override;
#endif // _DEBUG
    _Success_(return != 0)
    BOOL GetErrorMessage(_Out_writes_z_(nMaxError) LPTSTR lpszError, _In_ UINT nMaxError,
        _Out_opt_ PUINT pnHelpContext = NULL) const override;
};


/*============================================================================*/
// File - raw unbuffered disk file I/O

#ifndef __ATLTRANSACTIONMANAGER_H__
#include <atltransactionmanager.h>
#endif

using ATL::CAtlTransactionManager;

class CFile : public CObject
{
    DECLARE_DYNAMIC(CFile)

public:
    enum OpenFlags {
        modeRead            =   (int) 0x00000,
		modeWrite           =   (int) 0x00001,
		modeReadWrite       =   (int) 0x00002,
		shareCompat         =   (int) 0x00000,
		shareExclusive      =   (int) 0x00010,
		shareDenyWrite      =   (int) 0x00020,
		shareDenyRead       =   (int) 0x00030,
		shareDenyNone       =   (int) 0x00040,
		modeNoInherit       =   (int) 0x00080,
#ifdef _UNICODE
		typeUnicode         =   (int) 0x00400,
#endif
		modeCreate          =   (int) 0x01000,
		modeNoTruncate      =   (int) 0x02000,
		typeText            =   (int) 0x04000,
		typeBinary          =   (int) 0x08000,
		osNoBuffer          =   (int) 0x10000,
		osWriteThrough      =   (int) 0x20000,
		osRandomAccess      =   (int) 0x40000,
		osSequentialScan    =   (int) 0x80000,
    };

    enum Attribute {
        normal      = 0x00,
		readOnly    = FILE_ATTRIBUTE_READONLY,
		hidden      = FILE_ATTRIBUTE_HIDDEN,
		system      = FILE_ATTRIBUTE_SYSTEM,
		volume      = 0x08,
		directory   = FILE_ATTRIBUTE_DIRECTORY,
		archive     = FILE_ATTRIBUTE_ARCHIVE,
		device      = FILE_ATTRIBUTE_DEVICE,
		temporary   = FILE_ATTRIBUTE_TEMPORARY,
		sparse      = FILE_ATTRIBUTE_SPARSE_FILE,
		reparsePt   = FILE_ATTRIBUTE_REPARSE_POINT,
		compressed  = FILE_ATTRIBUTE_COMPRESSED,
		offline     = FILE_ATTRIBUTE_OFFLINE,
		notIndexed  = FILE_ATTRIBUTE_NOT_CONTENT_INDEXED,
		encrypted   = FILE_ATTRIBUTE_ENCRYPTED
    };

    enum SeekPosition {
        begin       = 0x0,
        current     = 0x1,
        end         = 0x2
    };

    static AFX_DATA const HANDLE hFileNull;

public:
    CFile();
    CFile(CAtlTransactionManager* pTM);

    CFile(HANDLE hFile);
    CFile(LPCTSTR lpszFileName, UINT nOpenFlags);

    CFile(LPCTSTR lpszFileName, UINT nOpenFlags, CAtlTransactionManager* pTM);

    HANDLE          m_hFile;
    operator HANDLE() const;

    BOOL            GetStatus(CFileStatus& rStatus) const;

    virtual ULONGLONG GetPosition() const;
    virtual CString GetFileName() const;
    virtual CString GetFileTitle() const;
    virtual CString GetFilePath() const;
    virtual void SetFilePath(LPCTSTR lpszNewName);

    virtual BOOL Open(LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL);
    virtual BOOL Open(LPCTSTR lpszFileName, UINT nOpenFlags, CAtlTransactionManager* pTM,
        CFileException* pError);
    static void PASCAL Rename(LPCTSTR lpszOldName, LPCTSTR lpszNewName,
        CAtlTransactionManager* pTM = NULL);
    static void PASCAL Remove(LPCTSTR lpszFileName, CAtlTransactionManager* pTM = NULL);
    static BOOL PASCAL GetStatus(LPCTSTR lpszFileName, CFileStatus& rStatus,
        CAtlTransactionManager* pTM = NULL);

    ULONGLONG       SeekToEnd();
    void            SeekToBegin();

    virtual CFile* Duplicate() const;

    virtual ULONGLONG Seek(LONGLONG lOff, UINT nFrom);
    virtual void SetLength(ULONGLONG dwNewLen);
    virtual ULONGLONG GetLength() const;

    virtual UINT Read(void* lpBuf, UINT nCount);
    virtual void Write(const void* lpBuf, UINT nCount);

    virtual void LockRange(ULONGLONG dwPos, ULONGLONG dwCount);
    virtual void UnlockRange(ULONGLONG dwPos, ULONGLONG dwCount);

    virtual void Abort();
    virtual void Flush();
    virtual void Close();

public:
    virtual ~CFile();
#ifdef _DEBUG
    void AssertValid() const override;
    void Dump(CDumpContext& dc) const override;
#endif // _DEBUG
    enum BufferCommand { bufferRead, bufferWrite, bufferCommit, bufferCheck };
    enum BufferFlags {
        bufferDirect        = 0x01,
        bufferBlocking      = 0x02
    };
    virtual UINT GetBufferPtr(UINT nCommand, UINT nCount = 0,
        void** ppBufStart = NULL, void** ppBufMax = NULL);

protected:
    void        CommonBaseInit(HANDLE hFile, CAtlTransactionManager* pTM);
    void        CommonInit(LPCTSTR lpszFileName, UINT nOpenFlags, CAtlTransactionManager* pTM);

    BOOL        m_bCloseOnDelete;
    CString     m_strFileName;

    CAtlTransactionManager*     m_pTM;
};

/*============================================================================*/
// STDIO file implementation

class CStdioFile : public CFile
{
    DECLARE_DYNAMIC(CStdioFile)

public:
    CStdioFile();

    CStdioFile(CAtlTransactionManager* pTM);

    CStdioFile(FILE* pOpenStream);
    CStdioFile(LPCTSTR lpszFileName, UINT nOpenFlags);

    CStdioFile(LPCTSTR lpszFileName, UINT nOpenFlags, CAtlTransactionManager* pTM);

    FILE*       m_pStream;

    virtual void WriteString(LPCTSTR lpsz);
    virtual LPTSTR ReadString(_Out_writes_z_(nMax) LPTSTR lpsz, _In_ UINT nMax);
    virtual BOOL ReadString(CString& rString);

public:
    virtual ~CStdioFile();
#ifdef _DEBUG
    void Dump(CDumpContext& dc) const override;
#endif // _DEBUG
    ULONGLONG       GetPosition() const override;
    ULONGLONG       GetLength() const override;
    BOOL            Open(LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL) override;

    BOOL            Open(LPCTSTR lpszFileName, UINT nOpenFlags, CAtlTransactionManager* pTM,
                         CFileException* pError) override;

    UINT            Read(void* lpBuf, UINT nCount) override;
    void            Write(const void* lpBuf, UINT nCount) override;
    ULONGLONG       Seek(LONGLONG lOff, UINT nFrom) override;

    void            Abort() override;
    void            Flush() override;
    void            Close() override;

    CFile*          Duplicate() const override;
    void            LockRange(ULONGLONG dwPos, ULONGLONG dwCount) override;
    void            UnlockRange(ULONGLONG dwPos, ULONGLONG dwCount) override;

protected:
    void            CommonBaseInit(FILE* pOpenStream, CAtlTransactionManager* pTM);
    void            CommonInit(LPCTSTR lpszFileName, UINT nOpenFlags, CAtlTransactionManager* pTM);
};

/*============================================================================*/
// Memory based file implementation

class CMemFile : public CFile
{
    DECLARE_DYNAMIC(CMemFile)

public:
    explicit CMemFile(UINT nGrowBytes = 1024);
    CMemFile(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes = 0);

    void        Attach(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes = 0);
    BYTE*       Detach();

protected:
    virtual BYTE* Alloc(SIZE_T nBytes);
    virtual BYTE* Realloc(BYTE* lpMem, SIZE_T nBytes);
    virtual BYTE* Memcpy(BYTE* lpMemTarget, const BYTE* lpMemSource, SIZE_T nBytes);
    virtual void Free(BYTE* lpMem);
    virtual void GrowFile(SIZE_T dwNewLen);

protected:
    SIZE_T          m_nGrowBytes;
    SIZE_T          m_nPosition;
    SIZE_T          m_nBufferSize;
    SIZE_T          m_nFileSize;
    BYTE*           m_lpBuffer;
    BOOL            m_bAutoDelete;

public:
    virtual ~CMemFile();
#ifdef _DEBUG
    void AssertValid() const override;
    void Dump(CDumpContext& dc) const override;
#endif // _DEBUG
    ULONGLONG       GetPosition() const override;
    BOOL            GetStatus(CFileStatus& rStatus) const;
    ULONGLONG       Seek(LONGLONG lOff, UINT nFrom) override;
    void            SetLength(ULONGLONG dwNewLen) override;
    UINT            Read(void* lpBuf, UINT nCount) override;
    void            Write(const void* lpBuf, UINT nCount) override;

    void            Abort() override;
    void            Flush() override;
    void            Close() override;

    UINT            GetBufferPtr(UINT nCommand, UINT nCount = 0,
                        void** ppBufStart = NULL, void** ppBufMax = NULL) override;
    ULONGLONG       GetLength() const override;

    CFile*          Duplicate() const override;
    void            LockRange(ULONGLONG dwPos, ULONGLONG dwCount) override;
    void            UnlockRange(ULONGLONG dwPos, ULONGLONG dwCount) override;
};

/*============================================================================*/
// Local file searches

#include <atltime.h>
using ATL::CTime;
using ATL::CTimeSpan;

class CFileFind : public CObject
{
    //DECLARE_DYNAME(CFileFind)

public:
    CFileFind();
    CFileFind(CAtlTransactionManager* pTM);

public:
    ULONGLONG       GetLength() const;
    virtual CString GetFileName() const;
    virtual CString GetFilePath() const;
    virtual CString GetFileTitle() const;
    virtual CString GetFileURL() const;
    virtual CString GetRoot() const;

    virtual BOOL GetLastWriteTime(FILETIME* pTimeStamp) const;
    virtual BOOL GetLastAccessTime(FILETIME* pTimeStamp) const;
    virtual BOOL GetCreationTime(FILETIME* pTimeStamp) const;
    virtual BOOL GetLastWriteTime(CTime& refTime) const;
    virtual BOOL GetLastAccessTime(CTime& refTime) const;
    virtual BOOL GetCreationTime(CTime& refTime) const;

    virtual BOOL MatchesMask(DWORD dwMask) const;

    virtual BOOL IsDots() const;

    BOOL        IsReadOnly() const;
    BOOL        IsDirectory() const;
    BOOL        IsCompressed() const;
    BOOL        IsSystem() const;
    BOOL        IsHidden() const;
    BOOL        IsTemporary() const;
    BOOL        IsNormal() const;
    BOOL        IsArchived() const;

    void        Close();
    virtual BOOL FindFile(LPCTSTR pstrName = NULL, DWORD dwUnused = 0);
    virtual BOOL FindNextFile();

protected:
    virtual void CloseContext();

protected:
    void*       m_pFoundInfo;
    void*       m_pNextInfo;
    HANDLE      m_hContext;
    CString     m_strRoot;
    TCHAR       m_chDirSeparator;

    CAtlTransactionManager*     m_pTM;

public:
    virtual ~CFileFind();
#ifdef _DEBUG
    void AssertValid() const override;
    void Dump(CDumpContext& dc) const override;
#endif // _DEBUG
};

#ifdef _DEBUG
CDumpContext& AFXAPI operator<<(CDumpContext& dc, CTimeSpan dateSpanSrc);
#endif // _DEBUG
CArchive& AFXAPI operator<<(CArchive& ar, CTimeSpan dateSpanSrc);
CArchive& AFXAPI operator>>(CArchive& ar, CTimeSpan& dateSpanSrc);

#ifdef _DEBUG
CDumpContext& AFXAPI operator<<(CDumpContext& dc, CTime dateSrc);
#endif // _DEBUG
CArchive& AFXAPI operator<<(CArchive& ar, CTime dateSrc);
CArchive& AFXAPI operator>>(CArchive& ar, CTime& dateSrc);

/*============================================================================*/
// File status

struct CFileStatuc
{
    CTime       m_ctime;
    CTime       m_mtime;
    CTime       m_atime;
    ULONGLONG   m_size;
    DWORD       m_attribute;
    TCHAR       m_szFullName[_MAX_PATH];

#ifdef _DEBUG
    void Dump(CDumpContext& dc) const;
#endif // _DEBUG
};

#include <afx.inl>

#endif // AFX_H
