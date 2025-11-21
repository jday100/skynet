#include "T100ElementServe.h"

#include "T100DiagramCommon.h"
#include "T100AllElements.h"

T100ElementServe::T100ElementServe()
{
    //ctor
    m_index     = 0;
    m_width     = 0;
    m_height    = 0;
}

T100ElementServe::~T100ElementServe()
{
    //dtor
}

T100VOID T100ElementServe::SetElement(T100ElementBase* element)
{
    m_current   = element;
}

T100ElementBase* T100ElementServe::GetElement()
{
    return m_current;
}

T100ElementBase* T100ElementServe::GetElement(T100UINT index)
{
    return m_elements[index];
}

T100UINT T100ElementServe::GetWidth()
{
    return m_width;
}

T100UINT T100ElementServe::GetHeight()
{
    return m_height;
}

T100ElementBase* T100ElementServe::Create(T100UINT value)
{
    T100ElementBase*    result      = T100NULL;

    switch(value){
    case T100ELEMENT_LIGATURE:
        {
            result  = T100NEW T100ElementLigature();
        }
        break;
    case T100ELEMENT_SINGLE_TRACK:
        {
            result  = T100NEW T100ElementSingleTrack();
        }
        break;
    case T100ELEMENT_BIDIRECTION:
        {
            result  = T100NEW T100ElementBidirection();
        }
        break;
    case T100ELEMENT_MODULE:
        {
            result  = T100NEW T100ElementModule();
        }
        break;
    }

    if(result){
        m_index++;
        result->SetIndex(m_index);

        m_elements[m_index]     = result;
    }

    return result;
}

T100VOID T100ElementServe::Load(T100DIAGRAM_ELEMENT_VECTOR* elements)
{
    if(!elements){
        return;
    }

    for(T100ElementBase* element : *elements){
        T100UINT    index   = element->GetIndex();
        if(index > m_index){
            m_index = index;
        }

        if(element->GetOriginX() > m_width){
            m_width     = element->GetOriginX();
        }
        if(element->GetOriginY() > m_height){
            m_height    = element->GetOriginY();
        }
        m_elements[index]     = element;
    }
}
