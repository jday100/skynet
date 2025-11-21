
#ifndef AFX_H_TEMPLATE_INCLUDE_GUARD
#define AFX_H_TEMPLATE_INCLUDE_GUARD



#endif // AFX_H_TEMPLATE_INCLUDE_GUARD






#ifdef _AFX_INLINE
#ifndef AFX_INL_INCLUDE_GUARD
#define AFX_INL_INCLUDE_GUARD

// CObject
_AFX_INLINE CObject::CObject() {}
_AFX_INLINE CObject::~CObject() {}
_AFX_INLINE void CObject::Serialize(CArchive&) {}
_AFX_INLINE void* PASCAL CObject::operator new(size_t, void* p)
    {
        return p;
    }
#ifndef _DEBUG
_AFX_INLINE void PASCAL CObject::operator delete(void* p)
    {
        ::operator delete(p);
    }
_AFX_INLINE void PASCAL CObject::operator delete(void* p, void*)
    {
        ::operator delete(p);
    }
_AFX_INLINE void* PASCAL CObject::operator new(size_t nSize)
    {
        return ::operator new(nSize);
    }
#ifdef _AFXDLL
_AFX_INLINE void CObject::AssertValid() const {}
_AFX_INLINE void CObject::Dump(CDumpContext&) const {}
#endif // _AFXDLL
#endif // _DEBUG


/*
_AFX_INLINE CException::~CException() {}
_AFX_INLINE CSimpleException::CSimpleException()
    {
        m_bInitialized = FALSE; m_bLoaded = FALSE;
    }
_AFX_INLINE CSimpleException::CSimpleException(BOOL bAutoDelete)
    : CException(bAutoDelete)
    {
        m_bInitialized = FALSE; m_bLoaded = FALSE;
    }
_AFX_INLINE CSimpleException::~CSimpleException() {}

_AFX_INLINE CMemoryException::CMemoryException()
    : CSimpleException() {}
_AFX_INLINE CMemoryException::CMemoryException(BOOL bAutoDelete, UINT nResourceID)
    : CSimpleException(bAutoDelete) { m_nResourceID = nResourceID; }
_AFX_INLINE CMemoryException::~CMemoryException() {}

_AFX_INLINE CNotSupportedException::CNotSupportedException()
    : CSimpleException() {}
_AFX_INLINE CNotSupportedException::CNotSupportedException(BOOL bAutoDelete, UINT nResourceID)
    : CSimpleException(bAutoDelete) { m_nResourceID = nResourceID; }
_AFX_INLINE CNotSupportedException::~CNotSupportedException() {}

_AFX_INLINE CInvalidArgException::CInvalidArgException()
    : CSimpleException() {}
_AFX_INLINE CInvalidArgException::CInvalidArgException(BOOL bAutoDelete, UINT nResourceID)
    : CSimpleException(bAutoDelete) { m_nResourceID = nResourceID; }
_AFX_INLINE CInvalidArgException::~CInvalidArgException() {}
*/

/*
_AFX_INLINE CArchiveException::CArchiveException(int cause,
    LPCTSTR lpszFilename)
    {
        m_cause = cause; m_strFileName = lpszFileName;
    }
_AFX_INLINE CArchiveException::~CArchiveException() {}
*/

#endif // AFX_INL_INCLUDE_GUARD
#endif // _AFX_INLINE

