#include "T100DiagramInfo.h"

T100DiagramInfo::T100DiagramInfo()
{
    //ctor
}

T100DiagramInfo::~T100DiagramInfo()
{
    //dtor
}

T100WPAINTER_ELEMENT_VECTOR* T100DiagramInfo::getElements()
{
    return &m_elements;
}
