#include "T100ElementCircleSource.h"

#include "T100DiagramTransducerTarget.h"

T100ElementCircleSource::T100ElementCircleSource(T100ElementCircle* element)
    :T100ElementBaseSource(), m_element(element)
{
    //ctor
    create();
}

T100ElementCircleSource::~T100ElementCircleSource()
{
    //dtor
    destroy();
}

T100VOID T100ElementCircleSource::create()
{
    T100ElementBaseSource::setElement(m_element);
}

T100VOID T100ElementCircleSource::destroy()
{

}

T100BOOL T100ElementCircleSource::serialize()
{
    T100BOOL            result          = T100FALSE;

    result  = m_target->setINTEGER(m_element->m_origin_x);
    if(!result)return T100FALSE;

    result  = m_target->setINTEGER(m_element->m_origin_y);
    if(!result)return T100FALSE;

    result  = m_target->setFLOAT(m_element->m_radius);
    if(!result)return T100FALSE;

    return result;
}

T100BOOL T100ElementCircleSource::deserialize()
{
    T100BOOL            result          = T100FALSE;

    m_element   = T100NEW T100ElementCircle();
    if(m_element){
        result  = m_target->getINTEGER(m_element->m_origin_x);
        if(!result)return T100FALSE;

        result  = m_target->getINTEGER(m_element->m_origin_y);
        if(!result)return T100FALSE;

        result  = m_target->getFLOAT(m_element->m_radius);
        if(result){

        }else{
            T100DELETE m_element;
            m_element   = T100NULL;
        }
    }

    return result;
}
