#include "T100ElementModuleSource.h"

#include "T100ElementTransducerTarget.h"

namespace T100Painter{

T100ElementModuleSource::T100ElementModuleSource(T100ElementModule* element)
    :T100ElementSourceBase(), m_element(element)
{
    //ctor
}

T100ElementModuleSource::~T100ElementModuleSource()
{
    //dtor
}

T100BOOL T100ElementModuleSource::serialize()
{
    T100BOOL        result          = T100FALSE;

    if(T100ElementSourceBase::m_element){
        m_element = (T100ElementModule*)T100ElementSourceBase::m_element;
    }

    result = m_target->setSTRING(m_element->m_name);
    if(!result)return T100FALSE;

    result = m_target->setINTEGER(m_element->m_origin_x);
    if(!result)return T100FALSE;

    result = m_target->setINTEGER(m_element->m_origin_y);
    if(!result)return T100FALSE;

    result = m_target->setWORD(m_element->m_width);
    if(!result)return T100FALSE;

    result = m_target->setWORD(m_element->m_height);
    if(!result)return T100FALSE;

    return result;
}

T100BOOL T100ElementModuleSource::deserialize()
{
    T100BOOL        result          = T100FALSE;

    m_element = T100NEW T100ElementModule();
    if(m_element){
        T100ElementSourceBase::m_element = m_element;

        result = m_target->getSTRING(m_element->m_name);
        if(result){
            result = m_target->getINTEGER(m_element->m_origin_x);
        }
        if(result){
            result = m_target->getINTEGER(m_element->m_origin_y);
        }
        if(result){
            result = m_target->getWORD(m_element->m_width);
        }
        if(result){
            result = m_target->getWORD(m_element->m_height);
        }
        if(!result){
            T100SAFE_DELETE(m_element);
        }
    }

    return result;
}

}
