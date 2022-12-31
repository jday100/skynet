#include "T100ElementCircleSource.h"

#include "T100TransducerTarget.h"

namespace T100Painter{

T100ElementCircleSource::T100ElementCircleSource(T100ElementCircle* element)
    :T100ElementTransducerSource(), m_element(element)
{
    //ctor
}

T100ElementCircleSource::~T100ElementCircleSource()
{
    //dtor
}

T100BOOL T100ElementCircleSource::serialize()
{
    T100BOOL        result          = T100FALSE;

    result = m_target->setWORD(m_element->m_type);
    if(!result)return T100FALSE;

    result = m_target->setWORD(m_element->m_origin_x);
    if(!result)return T100FALSE;

    result = m_target->setWORD(m_element->m_origin_y);
    if(!result)return T100FALSE;

    result = m_target->setFLOAT(m_element->m_radius);
    if(!result)return T100FALSE;

    return result;
}

T100BOOL T100ElementCircleSource::deserialize()
{

}

}
