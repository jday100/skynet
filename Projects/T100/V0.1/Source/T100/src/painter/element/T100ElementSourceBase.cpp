#include "T100ElementSourceBase.h"

namespace T100Painter{

T100ElementSourceBase::T100ElementSourceBase()
    :T100ElementTransducerSource()
{
    //ctor
}

T100ElementSourceBase::~T100ElementSourceBase()
{
    //dtor
}

T100VOID T100ElementSourceBase::setElement(T100ElementBase* element)
{
    m_element = element;
}

}
