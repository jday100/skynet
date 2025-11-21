#include <stdafx.h>
#include <stddef.h>

void CSimpleList::AddHead(void* p)
{
    ASSERT(p != NULL);
    ASSERT(*GetNextPtr(p) == NULL);

    *GetNextPtr(p) = m_pHead;
    m_pHead     = p;
}

BOOL CSimpleList::Remove(void* p)
{
    ASSERT(p != NULL);

    if(m_pHead == NULL)
        return FALSE;

    BOOL bResult = FALSE;
    if(m_pHead == p)
    {
        m_pHead = *GetNextPtr(p);
        DEBUG_ONLY(*GetNextPtr(p) = NULL);
        bResult = TRUE;
    }
    else
    {
        void* pTest = m_pHead;
        while(pTest != NULL && *GetNextPtr(pTest) != p)
            pTest = *GetNextPtr(pTest);
        if(pTest != NULL)
        {
            *GetNextPtr(pTest) = *GetNextPtr(p);
            DEBUG_ONLY(*GetNextPtr(p) = NULL);
            bResult = TRUE;
        }
    }
    return bResult;
}

#if defined(_DEBUG)
void* PASCAL CNoTrackObject::operator new(size_t nSize, LPCSTR, int)
{
    return CNoTrackObject::operator new(nSize);
}

void PASCAL CNoTrackObject::operator delete(void* pObject, LPCSTR, int)
{
    if(pObject != NULL)
        ::LocalFree(pObject);
}
#endif // defined

void* PASCAL CNoTrackObject::operator new(size_t nSize)
{
    void* p = ::LocalAlloc(LPTR, nSize);
    if(p == NULL)
        AfxThrowMemoryException();
    return p;
}

void PASCAL CNoTrackObject::operator delete(void* p)
{
    if(p != NULL)
        ::LocalFree(p);
}



void CThreadSlotData::AssignInstance(HINSTANCE hInstance)
{

}

void CThreadSlotData::DeleteValues(CThreadData* pData, HINSTANCE hInstance)
{

}

void CThreadSlotData::DeleteValues(HINSTANCE hInstance, BOOL bAll)
{

}



BYTE __afxThreadData[sizeof(CThreadSlotData)];
CThreadSlotData*    _afxThreadData;

struct CThreadData : public CNoTrackObject
{
    CThreadData*    pNext;
    int             nCount;
    LPVOID*         pData;
};

struct CSlotData
{
    DWORD       dwFlags;
    HINSTANCE   hInst;
};

#define SLOT_USED       0x01

CThreadSlotData::CThreadSlotData()
{

}

CThreadSlotData::~CThreadSlotData()
{

}

CNoTrackObject* CThreadLocalObject::GetData(
    CNoTrackObject* (AFXAPI* pfnCreateObject)())
{

}

CNoTrackObject* CThreadLocalObject::GetDataNA()
{

}

CThreadLocalObject::~CThreadLocalObject()
{

}


CNoTrackObject* CProcessLocalObject::GetData(
    CNoTrackObject* (AFXAPI* pfnCreateObject)())
{

}

CProcessLocalObject::~CProcessLocalObject()
{

}



void AFXAPI AfxInitLocalData(HINSTANCE hInstance)
{
    if(_afxThreadData != NULL)
        _afxThreadData->AssignInstance(hInstance);
}

void AFXAPI AfxTermLocalData(HINSTANCE hInstance, BOOL bAll)
{
    if(_afxThreadData != NULL)
        _afxThreadData->DeleteValues(hInstance, bAll);
}


AFX_STATIC_DATA long _afxTlsRef = 0;

void AFXAPI AfxTlsAddRef()
{
    ++_afxTlsRef;
}

void AFXAPI AfxTlsRelease()
{
    if(_afxTlsRef == 0 || --_afxTlsRef == 0)
    {
        if(_afxThreadData != NULL)
        {
            _afxThreadData->~CThreadSlotData();
            _afxThreadData = NULL;
        }
    }
}
