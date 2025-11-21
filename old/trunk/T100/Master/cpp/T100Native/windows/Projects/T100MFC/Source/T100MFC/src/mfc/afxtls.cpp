#include <stdafx.h>
#include <stddef.h>



void* PASCAL CNoTrackObject::operator new(size_t nSize)
{
    void* p = ::LocalAlloc(LPTR, nSize);
    //if(p == NULL)
        //AfxThrowMemoryException();
    return p;
}

void PASCAL CNoTrackObject::operator delete(void* p)
{
    if(p != NULL)
        ::LocalFree(p);
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
