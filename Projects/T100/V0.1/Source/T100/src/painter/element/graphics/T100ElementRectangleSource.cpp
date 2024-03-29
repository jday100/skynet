#include "T100ElementRectangleSource.h"

#include "T100ElementTransducerTarget.h"

namespace T100Painter{

T100ElementRectangleSource::T100ElementRectangleSource(T100ElementRectangle* element)
    :T100ElementSourceBase(), m_element(element)
{
    //ctor
}

T100ElementRectangleSource::~T100ElementRectangleSource()
{
    //dtor
}

T100BOOL T100ElementRectangleSource::serialize()
{
    T100BOOL        result          = T100FALSE;

    if(T100ElementSourceBase::m_element){
        m_element = (T100ElementRectangle*)T100ElementSourceBase::m_element;
    }

    result = m_target->setINTEGER(m_element->m_origin_x);
    if(!result)return T100FALSE;

    result = m_target->setINTEGER(m_element->m_origin_y);
    if(!result)return T100FALSE;

    result = m_target->setINTEGER(m_element->m_tail_x);
    if(!result)return T100FALSE;

    result = m_target->setINTEGER(m_element->m_tail_y);
    if(!result)return T100FALSE;

    return result;
}

T100BOOL T100ElementRectangleSource::deserialize()
{
    T100BOOL        result          = T100FALSE;

    m_element = T100NEW T100ElementRectangle();
    if(m_element){
        T100ElementSourceBase::m_element = m_element;
        result = m_target->getINTEGER(m_element->m_origin_x);
        if(result){
            result = m_target->getINTEGER(m_element->m_origin_y);
        }
        if(result){
            result = m_target->getINTEGER(m_element->m_tail_x);
        }
        if(result){
            result = m_target->getINTEGER(m_element->m_tail_y);
        }
        if(!result){
            T100SAFE_DELETE(m_element);
        }
    }

    return result;
}

}
