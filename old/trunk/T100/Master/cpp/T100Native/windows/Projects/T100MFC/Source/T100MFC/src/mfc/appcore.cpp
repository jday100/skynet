

#include <stdafx.h>
#include <malloc.h>
#include <sal.h>


CWinApp::CWinApp() :
    CWinThread()
{

}

CWinApp::~CWinApp()
{

}

BOOL CWinApp::InitInstance()
{

}


IMPLEMENT_DYNAMIC(CWinApp, CWinThread)
