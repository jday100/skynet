#include "stdafx.h"
#include <stddef.h>

_AFX_THREAD_STATE::_AFX_THREAD_STATE()
{

}

_AFX_THREAD_STATE::~_AFX_THREAD_STATE()
{

}

THREAD_LOCAL(_AFX_THREAD_STATE, _afxThreadState)


AFX_MODULE_STATE::AFX_MODULE_STATE(BOOL bDLL)
{

}

AFX_MODULE_STATE::~AFX_MODULE_STATE()
{

}


AFX_MODULE_STATE* AFXAPI AfxGetModuleState()
{
    _AFX_THREAD_STATE* pState = _afxThreadState;
}
