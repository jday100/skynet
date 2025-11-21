#ifndef AFXSTAT__H
#define AFXSTAT__H

#include <afxtls_.h>
#include <atltypes.h>


class AFX_MODULE_STATE : public CNoTrackObject
{
public:
#ifdef _AFXDLL
    AFX_MODULE_STATE(BOOL bDLL, WNDPROC pfnAfxWndProc, DWORD dwVersion,
        BOOL bSystem = FALSE);
#else
    explicit AFX_MODULE_STATE(BOOL bDLL);
#endif // _AFXDLL
    ~AFX_MODULE_STATE();

    CWinApp*        m_pCurrentWinApp;
    HINSTANCE       m_hCurrentInstanceHandle;
    HINSTANCE       m_hCurrentResourceHandle;
    LPCTSTR         m_lpszCurrentAppName;
    BYTE            m_bDLL;
    BYTE            m_bSystem;
    BYTE            m_bReserved[2];

    DWORD           m_fRegisteredClasses;
};

AFX_MODULE_STATE* AFXAPI AfxGetAppModuleState();
#ifdef _AFXDLL
AFX_MODULE_STATE* AFXAPI AfxSetModuleState(AFX_MODULE_STATE* pNewState) throw();
#endif // _AFXDLL
AFX_MODULE_STATE* AFXAPI AfxGetModuleState();
BOOL AFXAPI AfxIsModuleDll();
BOOL AFXAPI AfxInitCurrentStateApp();
AFX_MODULE_STATE* AFXAPI AfxGetStaticModuleState();
HINSTANCE AFXAPI AfxGetinstanceHandleHelper();



class CView;
class CToolTipCtrl;
class CControlBar;
class CPushRoutingFrame;
class CPushRoutingView;

#define _AFX_TEMP_CLASS_NAME_SIZE       96
class _AFX_THREAD_STATE : public CNoTrackObject
{
public:
    _AFX_THREAD_STATE();
    virtual ~_AFX_THREAD_STATE();

    AFX_MODULE_STATE*           m_pModuleState;
    AFX_MODULE_STATE*           m_pPrevModuleState;

    void*                       m_pSafetyPoolBuffer;

    AFX_EXCEPTION_CONTEXT       m_exceptionContext;

    CWnd*           m_pWndInit;
    CWnd*           m_pAlternateWndInit;
    DWORD           m_dwPropStyle;
    DWORD           m_dwPropExStyle;
    HWND            m_hWndInit;
    HHOOK           m_hHookOldCbtFilter;
    HHOOK           m_hHookOldMsgFilter;

    MSG             m_msgCur;
    CPoint          m_ptCursorLast;
    UINT            m_nMsgLast;

#ifdef _DEBUG
    int             m_nDisablePumpCount;
#endif // _DEBUG



    CWnd*           m_pWndPark;
    long            m_nCtrlRef;
    BOOL            m_bNeedTerm;
};


#endif // AFXSTAT__H
