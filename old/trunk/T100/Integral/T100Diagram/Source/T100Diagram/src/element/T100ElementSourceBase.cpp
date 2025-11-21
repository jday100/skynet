#include "T100ElementSourceBase.h"

T100ElementSourceBase::T100ElementSourceBase() :
    T100ElementTransducerSource()
{
    //ctor
}

T100ElementSourceBase::~T100ElementSourceBase()
{
    //dtor
}

T100VOID T100ElementSourceBase::SetElement(T100ElementBase* element)
{
    m_element = element;
}

T100ElementBase* T100ElementSourceBase::GetElement()
{
    return m_element;
}
