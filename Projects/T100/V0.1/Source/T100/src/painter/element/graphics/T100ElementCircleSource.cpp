#include "T100ElementCircleSource.h"

#include "T100ElementTransducerTarget.h"

namespace T100Painter{

T100ElementCircleSource::T100ElementCircleSource(T100ElementCircle* element)
    :T100ElementSourceBase(), m_element(element)
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

    if(T100ElementSourceBase::m_element){
        m_element = (T100ElementCircle*)T100ElementSourceBase::m_element;
    }

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
    T100BOOL        result          = T100FALSE;

    m_element = T100NEW T100ElementCircle();
    if(m_element){
        T100ElementSourceBase::m_element = m_element;
        result = m_target->getWORD(m_element->m_origin_x);
        if(result){
            result = m_target->getWORD(m_element->m_origin_y);
        }
        if(result){
            result = m_target->getFLOAT(m_element->m_radius);
        }
        if(!result){
            T100SAFE_DELETE(m_element);
        }
    }

    return result;
}

}
