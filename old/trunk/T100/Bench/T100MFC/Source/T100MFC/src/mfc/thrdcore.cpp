

#include <new.h>
#include <stdafx.h>




/////////////////////////////////////////////////////////////////////////////
// CWinThread construction

CWinThread::CWinThread(AFX_THREADPROC pfnThreadProc, LPVOID pParam)
{

}

CWinThread::CWinThread()
{

}

CWinThread::~CWinThread()
{

}


IMPLEMENT_DYNAMIC(CWinThread, CCmdTarget)

struct _AFX_THREAD_STARTUP
{
    _AFX_THREAD_STATE*      pThreadState;
    CWinThread*             pThread;
    DWORD                   dwCreateFlags;
    _PNH                    pfnNewHandler;

    HANDLE                  hEvent;
    HANDLE                  hEvent2;

    BOOL                    bError;
};


UINT APIENTRY _AfxThreadEntry(void* pParam)
{
    _AFX_THREAD_STARTUP* pStartup = (_AFX_THREAD_STARTUP*)pParam;


    CWinThread* pThread = pStartup->pThread;

    pThread->InitInstance();
}

BOOL CWinThread::InitInstance()
{

}
