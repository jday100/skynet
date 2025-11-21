#include <stdafx.h>
#include <sal.h>

extern int AFXAPI AfxWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    _In_ LPTSTR lpCmdLine, int nCmdShow);

extern "C" int WINAPI
_tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
#pragma warning(suppress : 4985)
{
    return AfxWinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}

BOOL AFXAPI AfxInitialize(BOOL bDLL, DWORD dwVersion)
{
    AFX_MODULE_STATE*   pModuleState = AfxGetModuleState();
    pModuleState->m_bDLL    = (BYTE)bDLL;
    ASSERT(dwVersion <= _MFC_VER);
    UNUSED(dwVersion);
#ifdef _AFXDLL
    pModuleState->m_dwVersion   = dwVersion;
#endif // _AFXDLL
#ifdef _MBCS
    if(!bDLL)
        _setmbcp(_MB_CP_ANSI);
#endif // _MBCS
    return TRUE;
}

#pragma warning(disable : 4074)
#pragma init_seg(lib)

#ifndef _AFXDLL
void AFX_CDECL _AfxTermAppState()
{
    AfxTermLocalData(NULL, TRUE);
    AfxCriticalTerm();

    AfxTlsRelease();
}
#endif // _AFXDLL

#ifndef _AFXDLL
char _afxInitAppState   = (char)(AfxInitialize(FALSE, _MFC_VER), atexit(&_AfxTermAppState));
#else
char _afxInitAppState   = (char)(AfxInitialize(FALSE, _MFC_VER));
#endif // _AFXDLL

