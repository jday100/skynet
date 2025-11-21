#ifndef AFXWIN_H
#define AFXWIN_H

#include <afx.h>
#include <atltransactionmanager.h>

using ATL::CAtlTransactionManager;

/*============================================================================*/
// Classes declared in this file

//CObject
    //CException
        //CSimpleException
            class CResourceException;
            class CUserException;

    class CGdiObject;
        class CPen;
        class CBrush;
        class CFont;
        class CBitmap;
        class CPalette;
        class CRgn;

    class CDC;
        class CClientDC;
        class CWindowDC;
        class CPaintDC;

    class CImageList;

    class CMenu;

    class CCmdTarget;
        class CWnd;
            class CDialog;

            class CStatic;
            class CButton;
            class CListBox;
                class CCheckListBox;
            class CComboBox;
            class CEdit;
            class CScrollBar;

            class CMFCPreviewCtrlImpl;

            class CFrameWnd;
                class CMDIFrameWnd;
                class CMDIChildWnd;
                class CMiniFrameWnd;

            class CView;
                class CScrollView;

        class CWinThread;
            class CWinApp;

        class CDocTemplate;
            class CSingleDocTemplate;
            class CMultiDocTemplate;

        class CDocument;
        class CMFCFilterChunkValueImpl;

class CCmdUI;
class CDataExchange;
class CCommandLineInfo;
class CDocManager;

struct COleControlSiteOrWnd;

class CControlCreationInfo;

class CVariantBoolConverter;
class CMFCDynamicLayout;

/*============================================================================*/

enum AFX_HELP_TYPE
{
    afxWinHelp      = 0,
    afxHTMLHelp     = 1
};

class COccManager;

class AFX_NOVTABLE CCmdTarget : public CObject
{
    DECLARE_DYNAMIC(CCmdTarget)
public:
    CCmdTarget();

/*
    LPDISPATCH          GetIDispatch(BOOL bAddRef);

    static CCmdTarget* PASCAL FromIDispatch(LPDISPATCH lpDispatch);

    BOOL                IsResultExpected();

    void                EnableAutomation();

    void                EnableConnections();

    void                GeginWaitCursor();
    void                EndWaitCursor();
    void                RestoreWaitCursor();

    BOOL                EnumOleVerbs(LPENUMOLEVERB* ppenumOleVerb);
    BOOL                DoOleVerb(LONG iVerb, LPMSG lpMsg, HWND hWndParent, LPCRECT lpRect);

    virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
        AFX_CMDHANDLERINFO* pHandlerInfo);

    virtual void OnFinalRelease();

    virtual BOOL IsInvokeAllowed(DISPID dispid);

    void                EnableTypeLib();
    HRESULT             GetTypeInfoOfGuid(LCID lcid, const GUID& guid,
                            LPTYPEINFO* ppTypeInfo);

    virtual BOOL GetDispatchIID(IID* pIID);
    virtual UINT GetTypeInfoCount();
    virtual CTypeLibCache* GetTypeLibCache();
    virtual HRESULT GetTypeLib(LCID lcid, LPTYPELIB* ppTypeLib);
*/

public:
    virtual ~CCmdTarget() = 0;
#ifdef _DEBUG
    void AssertValid() const override;
    void Dump(CDumpContext& dc) const override;
#endif // _DEBUG

/*
    void            GetNotSupported();
    void            SetNotSupported();

protected:
    friend class CView;

    CView*          GetRoutingView();
    CFrameWnd*      GetRoutingFrame();
    static CView* PASCAL GetRoutingView_();
    static CFrameWnd* PASCAL GetRoutingFrame_();

    static const AFX_MSGMAP* PASCAL GetThisMessageMap();
    virtual const AFX_MSGMAP* GetMessageMap() const;

    DECLARE_OLECMD_MAP()
    friend class COleCmdUI;

    DECLARE_DISPATCH_MAP()
    DECLARE_CONNECTION_MAP()
    DECLARE_INTERFACE_MAP()
    DECLARE_EVENTSINK_MAP()

public:
    long            m_dwRef;
    LPUNKNOWN       m_pOuterUnknown;
    DWORD_PTR       m_xInnerUnknown;

public:
    void            EnableAggregation();
    void            ExternalDisconnect();
    LPUNKNOWN       GetControllingUnknown();

    DWORD           InternalQueryInterface(const void*, LPVOID* ppvObj);
    DWORD           InternalAddRef();
    DWORD           InternalRelease();

    DWORD           ExternalQueryInterface(const void*, LPVOID* ppvObj);
    DWORD           ExternalAddRef();
    DWORD           ExternalRelease();

    LPUNKNOWN       GetInterface(const void*);
    LPUNKNOWN       QueryAggregates(const void*);

    virtual BOOL OnCreateAggregates();
    virtual LPUNKNOWN GetInterfaceHook(const void*);

protected:
    static XDispatch
    {
        DWORD_PTR   m_vtbl;
    }m_xDispatch;
    BOOL            m_bResultExpected;

    void            GetStandardProp(const AFX_DISPMAP_ENTRY* pEntry,
                        VARIANT* pvarResult, UINT* puArgErr);
    SCODE           SetStandardProp(const AFX_DISPMAP_ENTRY* pEntry,
                        DISPPARAMS* pDispParams, UINT* puArgErr);

    static UINT PASCAL GetEntryCount(const AFX_DISPMAP* pDispMap);
    const AFX_DISPMAP_ENTRY* PASCAL GetDispEntry(LONG memid);
    static LONG PASCAL MemberIDFromName(const AFX_DISPMAP* pDispMap, LPCTSTR lpszName);
*/


};

/*============================================================================*/
// CWinThread

typedef UINT (AFX_CDECL* AFX_THREADPROC)(LPVOID);

class COleMessageFilter;

BOOL AFXAPI AfxPumpMessage();
LRESULT AFXAPI AfxProcessWndProcException(CException*, const MSG* pMsg);
BOOL __cdecl AfxPreTranslateMessage(MSG* pMsg);
BOOL __cdecl AfxIsIdleMessage(MSG* pMsg);

class CWinThread : public CCmdTarget
{
    DECLARE_DYNAMIC(CWinThread)

public:
    CWinThread();

public:
    virtual ~CWinThread();

public:
    CWinThread(AFX_THREADPROC pfnThreadProc, LPVOID pParam);
};

class CWinApp : public CWinThread
{
    DECLARE_DYNAMIC(CWinApp)
public:
    explicit CWinApp(LPCTSTR lpszAppName = NULL);

public:
    virtual ~CWinApp();
};

#endif // AFXWIN_H
