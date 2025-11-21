
#include <stdafx.h>
#include <sal.h>

#include <afxres.h>


CException::CException()
{

}

CException::CException(BOOL bAutoDelete)
{

}




void AFXAPI AfxThrowLastCleanup()
{

}


IMPLEMENT_DYNAMIC(CException, CObject)
IMPLEMENT_DYNAMIC(CSimpleException, CException)

IMPLEMENT_DYNAMIC(CMemoryException, CSimpleException)
CMemoryException _simpleMemoryException(FALSE, AFX_IDS_MEMORY_EXCEPTION);

IMPLEMENT_DYNAMIC(CNotSupportedException, CSimpleException)
CNotSupportedException _simpleNotSupportedException(FALSE, AFX_IDS_NOT_SUPPORTED_EXCEPTION);

IMPLEMENT_DYNAMIC(CInvalidArgException, CSimpleException)
CInvalidArgException _simpleInvalidArgException(FALSE, AFX_IDS_INVALID_ARG_EXCEPTION);

/////////////////////////////////////////////////////////////////////////////
// Standard exceptions

void CSimpleException::InitString()
{

}

/*
_Success_(return != 0)
BOOL CSimpleException::GetErrorMessage(_Out_writes_z_(nMaxError) LPTSTR lpszError,
        _In_ UINT nMaxError, _Out_opt_ PUINT pnHelpContext) const
{

}
*/

void __declspec(noreturn) AFXAPI AfxThrowMemoryException()
{
    THROW(&_simpleMemoryException);
}

void __declspec(noreturn) AFXAPI AfxThrowNotSuppertedException()
{
    THROW(&_simpleNotSupportedException);
}

void __declspec(noreturn) AFXAPI AfxThrowInvalidArgException()
{
    THROW(&_simpleInvalidArgException);
}
