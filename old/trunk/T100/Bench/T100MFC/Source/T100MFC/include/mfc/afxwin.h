#ifndef AFXWIN_H
#define AFXWIN_H

#include <afx.h>
#include <windows.h>


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

class CCmdTarget : public CObject
{
    DECLARE_DYNAMIC(CCmdTarget)

public:
    CCmdTarget();

    ~CCmdTarget();


protected:
    friend UINT APIENTRY _AfxThreadEntry(void* pParam);

};

typedef UINT (AFX_CDECL* AFX_THREADPROC)(LPVOID);

class CWinThread : public CCmdTarget
{
    DECLARE_DYNAMIC(CWinThread)

public:
    CWinThread();
    BOOL CreateThread(DWORD dwCreateFlags = 0, UINT nStackSize = 0,
        LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);

    ~CWinThread();

    virtual BOOL InitInstance();

public:
    CWinThread(AFX_THREADPROC pfnThreadProc, LPVOID pParam);
};

class CWinApp : public CWinThread
{
    DECLARE_DYNAMIC(CWinApp)

public:
    CWinApp();
    ~CWinApp();



    virtual BOOL InitInstance();

};



#endif // AFXWIN_H
