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

    return TRUE;
}

void AFX_CDECL _AfxTermAppState()
{
    //AfxTermLocalData(NULL, TRUE);
    //AfxCriticalTerm();

    //AfxTlsRelease();
}


char _afxInitAppState   = (char)(AfxInitialize(FALSE, _MFC_VER), atexit(&_AfxTermAppState));
