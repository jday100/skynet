#ifndef AFXTLS__H
#define AFXTLS__H

#pragma once

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif // _AFX_PACKING

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif // _AFX_MINREBUILD

#undef AFX_DATA
#define AFX_DATA AFX_CORE_DATA

#include <afx.h>


class CSimpleList;
class CThreadSlotData;
class CThreadLocalObject;
class CProcessLocalObject;
class CNoTrackObject;


class CSimpleList
{
public:
    CSimpleList(int nNextOffset = 0);
    void        Construct(int nNextOffset);

    BOOL        IsEmpty() const;
    void        AddHead(void* p);
    void        RemoveAll();
    void*       GetHead()const;
    void*       GetNext(void* p) const;
    BOOL        Remove(void* p);

    void*       m_pHead;
    size_t      m_nNextOffset;

    void**      GetNextPtr(void* p) const;
};

AFX_INLINE CSimpleList::CSimpleList(int nNextOffset)
    {
        m_pHead = NULL; m_nNextOffset = nNextOffset;
    }
AFX_INLINE void CSimpleList::Construct(int nNextOffset)
    {
        ASSERT(m_pHead == NULL); m_nNextOffset = nNextOffset;
    }
AFX_INLINE BOOL CSimpleList::IsEmpty() const
    {
        return m_pHead == NULL;
    }
AFX_INLINE void** CSimpleList::GetNextPtr(void* p) const
    {
        ENSURE_ARG(p != NULL);
        /*
        do {
                int __afx_condVal=!!(p != NULL);
                ASSERT(__afx_condVal);
                if (!(__afx_condVal)){
                        ::AfxThrowInvalidArgException();
                }
            }
            #pragma(warning(suppress:4127))
            while (false);
        */
        return(void**)((BYTE*)p + m_nNextOffset);
    }
AFX_INLINE void CSimpleList::RemoveAll()
    {
        m_pHead = NULL;
    }
AFX_INLINE void* CSimpleList::GetHead() const
    {
        return m_pHead;
    }
AFX_INLINE void* CSimpleList::GetNext(void* prevElement) const
    {
        return *GetNextPtr(prevElement);
    }


template<class TYPE>
class CTypedSimpleList : public CSimpleList
{
public:
    CTypedSimpleList(int nNextOffset = 0)
        : CSimpleList(nNextOffset) {}
    void AddHead(TYPE p)
        {
            CSimpleList::AddHead(p);
        }
    TYPE GetHead()
        {
            return (TYPE)CSimpleList::GetHead();
        }
    TYPE GetNext(TYPE p)
        {
            return (TYPE)CSimpleList::GetNext(p);
        }
    BOOL Remove(TYPE p)
        {
            return CSimpleList::Remove(p);
        }
    operator TYPE();
};
template<class TYPE>
inline CTypedSimpleList<TYPE>::operator TYPE()
{
    return (TYPE)CSimpleList::GetHead();
}

/////////////////////////////////////////////////////////////////////////////
// CThreadSlotData - manages owned array of "slots" for thread local storage

struct CThreadData;
struct CSlotData;

class CThreadSlotData
{
public:
    CThreadSlotData();

    int         AllocSlot();
    void        FreeSlot(int nSlot);
    void        SetValue(int nSlot, void* pValue);

    void        DeleteValues(HINSTANCE hInstance, BOOL bAll = FALSE);

    void        AssignInstance(HINSTANCE hInstance);

    DWORD       m_tlsIndex;

    int         m_nAlloc;
    int         m_nRover;
    int         m_nMax;
    CSlotData*  m_pSlotData;
    CTypedSimpleList<CThreadData*>   m_list;
    CRITICAL_SECTION    m_sect;

    void*       GetThreadValue(int nSlot);
    void*       PASCAL operator new(size_t, void* p)
        {
            return p;
        }

    void        DeleteValues(CThreadData* pData, HINSTANCE hInstance);
    ~CThreadSlotData();
};



class AFX_NOVTABLE CNoTrackObject
{
public:
    void* PASCAL operator new(size_t nSize);
    void PASCAL operator delete(void*);

#if defined(_DEBUG)
    void* PASCAL operator new(size_t nSize, LPCSTR, int);
    void PASCAL operator delete(void* pObject, LPCSTR, int);
#endif // defined

    virtual ~CNoTrackObject() {};
};

class AFX_NOVTABLE CThreadLocalObject
{
public:
    CNoTrackObject* GetData(CNoTrackObject* (AFXAPI* pfnCreateObject)());
    CNoTrackObject* GetDataNA();

    int     m_nSlot;
    ~CThreadLocalObject();
};

class AFX_NOVTABLE CProcessLocalObject
{
public:
    CNoTrackObject* GetData(CNoTrackObject* (AFXAPI* pfnCreateObject)());

    CNoTrackObject* volatile m_pObject;
    ~CProcessLocalObject();
};

template<class TYPE>
class CThreadLocal : public CThreadLocalObject
{
public:
    AFX_INLINE TYPE* GetData()
        {
            TYPE* pData = (TYPE*)CThreadLocalObject::GetData(&CreateObject);
            ENSURE(pData != NULL);
            return pData;
        }
    AFX_INLINE TYPE* GetDataNA()
        {
            TYPE* pData = (TYPE*)CThreadLocalObject::GetDataNA();
            return pData;
        }
    AFX_INLINE operator TYPE*()
        {
            return GetData();
        }
    AFX_INLINE TYPE* operator->()
    {
        return GetData();
    }

public:
    static CNoTrackObject* AFXAPI CreateObject()
        {
            return new TYPE;
        }
};

#define THREAD_LOCAL(class_name, ident_name) \
    AFX_COMDAT CThreadLocal<class_name> ident_name;
#define EXTERN_THREAD_LOCAL(class_name, ident_name) \
    extern CThreadLocal<class_name> ident_name;

template<class TYPE>
class CProcessLocal : public CProcessLocalObject
{
public:
    AFX_INLINE TYPE* GetData()
        {
            TYPE* pData = (TYPE*)CProcessLocalObject::GetData(&CreateObject);
            ENSURE(pData != NULL);
            return pData;
        }
    AFX_INLINE TYPE* GetDataNA()
        {
            return (TYPE*)m_pObject;
        }
    AFX_INLINE operator TYPE*()
        {
            return GetData();
        }
    AFX_INLINE TYPE* operator->()
        {
            return GetData();
        }

public:
    static CNoTrackObject* AFXAPI CreateObject()
        {
            return new TYPE;
        }
};

#define PROCESS_LOCAL(class_name, ident_name) \
    AFX_COMDAT CProcessLocal<class_name> ident_name;
#define EXTERN PROCESS_LOCAL(class_name, ident_name) \
    extern CProcessLocal<class_name> ident_name;

void AFXAPI AfxInitLocalData(HINSTANCE hInstance);
void AFXAPI AfxTermLocalData(HINSTANCE hInstance, BOOL bAll = FALSE);
void AFXAPI AfxTlsAddRef();
void AFXAPI AfxTlsRelease();

#ifdef _AFX_MINREBUILD
#pragma componect(minrebuild, on)
#endif // _AFX_MINREBUILD

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif // _AFX_PACKING

#undef AFX_DATA
#define AFX_DATA

#endif // AFXTLS__H
