#include "T100ElementCircleSource.h"

#include "T100DiagramTransducerTarget.h"

T100ElementCircleSource::T100ElementCircleSource(T100ElementCircle* element)
    :T100ElementBaseSource()
{
    //ctor
    T100ElementBaseSource::setElement(element);
    create();
}

T100ElementCircleSource::~T100ElementCircleSource()
{
    //dtor
    destroy();
}

T100VOID T100ElementCircleSource::create()
{

}

T100VOID T100ElementCircleSource::destroy()
{

}

T100BOOL T100ElementCircleSource::serialize()
{
    T100BOOL                result          = T100FALSE;
    T100ElementCircle*      element         = T100NULL;

    element = dynamic_cast<T100ElementCircle*>(m_element);
    if(!element)return T100FALSE;

    result  = m_target->setINTEGER(element->m_origin_x);
    if(!result)return T100FALSE;

    result  = m_target->setINTEGER(element->m_origin_y);
    if(!result)return T100FALSE;

    result  = m_target->setFLOAT(element->m_radius);
    if(!result)return T100FALSE;

    return result;
}

T100BOOL T100ElementCircleSource::deserialize()
{
    T100BOOL                result          = T100FALSE;
    T100ElementCircle*      element         = T100NULL;

    element = T100NEW T100ElementCircle();
    if(element){
        result  = m_target->getINTEGER(element->m_origin_x);
        if(result){
            result  = m_target->getINTEGER(element->m_origin_y);
            if(result){
                result  = m_target->getFLOAT(element->m_radius);
            }
        }

        if(result){
            m_element   = element;
        }else{
            T100DELETE  element;
            element     = T100NULL;
        }
    }

    return result;
}
