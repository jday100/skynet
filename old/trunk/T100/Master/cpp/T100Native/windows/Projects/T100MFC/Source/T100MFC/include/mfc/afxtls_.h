#ifndef AFXTLS__H
#define AFXTLS__H

class AFX_NOVTABLE CNoTrackObject
{
public:
    void* PASCAL operator new(size_t nSize);
    void PASCAL operator delete(void*);

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

};

template<class TYPE>
class CThreadLocal : public CThreadLocalObject
{
public:
    AFX_INLINE TYPE* GetData()
        {
            TYPE* pData = (TYPE*)CThreadLocalObject::GetData(&CreateObject);
            //ENSURE(pData != NULL);
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


void AFXAPI AfxInitLocalData(HINSTANCE hInstance);
void AFXAPI AfxTermLocalData(HINSTANCE hInstance, BOOL bAll = FALSE);


#endif // AFXTLS__H
