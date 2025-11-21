

#include "stdafx.h"

/////////////////////////////////////////////////////////////////////////////
// Runtime Typing

const struct CRuntimeClass CObject::classCObject =
    {
        "CObject", sizeof(CObject), 0xffff, NULL, NULL, NULL
    };

CRuntimeClass* CObject::GetRuntimeClass() const
{
    return _RUNTIME_CLASS(CObject);
}

#ifdef _AFXDLL
CRuntimeClass* PASCAL CObject::_GetBaseClass()
{
    return NULL;
}
CRuntimeClass* PASCAL CObject::GetThisClass()
{
    return _RUNTIME_CLASS(CObject);
}
#endif // _AFXDLL

BOOL CObject::IsKindOf(const CRuntimeClass* pClass) const
{
    CRuntimeClass* pClassThis = GetRuntimeClass();

    return pClassThis->IsDerivedFrom(pClass);
}









BOOL CRuntimeClass::IsDerivedFrom(const CRuntimeClass* pBaseClass) const
{

}
