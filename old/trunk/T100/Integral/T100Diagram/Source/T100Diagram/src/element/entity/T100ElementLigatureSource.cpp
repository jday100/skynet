#include "T100ElementLigatureSource.h"

#include "T100ElementTransducerTarget.h"

T100ElementLigatureSource::T100ElementLigatureSource(T100ElementLigature* element) :
    T100ElementSourceBase(),
    m_element(element)
{
    //ctor
}

T100ElementLigatureSource::~T100ElementLigatureSource()
{
    //dtor
}

T100BOOL T100ElementLigatureSource::Serialize()
{
    T100BOOL        result          = T100FALSE;

    if(T100ElementSourceBase::m_element){
        m_element = (T100ElementLigature*)T100ElementSourceBase::m_element;
    }

    result = m_target->SetUINT(m_element->m_startIndex);
    if(!result)return T100FALSE;

    result = m_target->SetUINT(m_element->m_endIndex);
    if(!result)return T100FALSE;

    return result;
}

T100BOOL T100ElementLigatureSource::Deserialize()
{
    T100BOOL        result          = T100FALSE;

    m_element = T100NEW T100ElementLigature();
    if(m_element){
        T100ElementSourceBase::m_element = m_element;

        result = m_target->GetUINT(m_element->m_startIndex);
        if(result){
            result = m_target->GetUINT(m_element->m_endIndex);
        }
        if(!result){
            T100SAFE_DELETE(m_element);
        }
    }

    return result;
}
