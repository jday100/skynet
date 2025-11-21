#include "stdafx.h"
#include <stddef.h>

/////////////////////////////////////////////////////////////////////////////
// _AFX_THREAD_STATE implementation

_AFX_THREAD_STATE::_AFX_THREAD_STATE()
{
#ifdef _DEBUG
    m_nDisablePumpCount = 0;
#endif // _DEBUG
    m_msgCur.message    = WM_NULL;
    m_nMsgLast          = WM_NULL;

    m_ptCursorLast      = CPoint(0, 0);
}

_AFX_THREAD_STATE::~_AFX_THREAD_STATE()
{
    if(m_hHookOldMsgFilter != NULL)
        ::UnhookWindowsHookEx(m_hHookOldMsgFilter);
    if(m_hHookOldCbtFilter != NULL)
        ::UnhookWindowsHookEx(m_hHookOldCbtFilter);

    if(m_pSafetyPoolBuffer != NULL)
        free(m_pSafetyPoolBuffer);

    ASSERT(m_pWndPark == NULL);
}

#ifdef _AFXDLL
AFX_MODULE_STATE::AFX_MODULE_STATE(BOOL bDLL, WNDPROC pfnAfxWndProc,
    DWORD dwVersion, BOOL bSystem)
#else
AFX_MODULE_STATE::AFX_MODULE_STATE(BOOL bDLL)
#endif // _AFXDLL
{

}

AFX_MODULE_STATE::~AFX_MODULE_STATE()
{

}

THREAD_LOCAL(_AFX_THREAD_STATE, _afxThreadState)

LRESULT CALLBACK AfxWndProcBase(HWND, UINT, WPARAM, LPARAM);

class _AFX_BASE_MODULE_STATE : public AFX_MODULE_STATE
{
public:
#ifdef _AFXDLL
    _AFX_BASE_MODULE_STATE() : AFX_MODULE_STATE(TRUE, AfxWndProcBase, _MFC_VER)
#else
    _AFX_BASE_MODULE_STATE() : AFX_MODULE_STATE(TRUE)
#endif // _AFXDLL
    {

    }
};

PROCESS_LOCAL(_AFX_BASE_MODULE_STATE, _afxBaseModuleState)


AFX_MODULE_STATE* AFXAPI AfxGetAppModuleState()
{
    return _afxBaseModuleState.GetData();
}

AFX_MODULE_STATE* AFXAPI AfxGetModuleState()
{
    _AFX_THREAD_STATE* pState = _afxThreadState;
    ENSURE(pState);
    AFX_MODULE_STATE* pResult;
    if(pState->m_pModuleState != NULL)
    {
        pResult = pState->m_pModuleState;
    }
    else
    {
        pResult = _afxBaseModuleState.GetData();
    }
    ENSURE(pResult != NULL);
    return pResult;
}
