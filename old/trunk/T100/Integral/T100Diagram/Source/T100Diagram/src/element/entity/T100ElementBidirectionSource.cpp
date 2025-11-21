#include "T100ElementBidirectionSource.h"

#include "T100ElementTransducerTarget.h"

T100ElementBidirectionSource::T100ElementBidirectionSource(T100ElementBidirection* element) :
    T100ElementSourceBase(),
    m_element(element)
{
    //ctor
}

T100ElementBidirectionSource::~T100ElementBidirectionSource()
{
    //dtor
}

T100BOOL T100ElementBidirectionSource::Serialize()
{
    T100BOOL        result          = T100FALSE;

    if(T100ElementSourceBase::m_element){
        m_element = (T100ElementBidirection*)T100ElementSourceBase::m_element;
    }

    result = m_target->SetUINT(m_element->m_startIndex);
    if(!result)return T100FALSE;

    result = m_target->SetUINT(m_element->m_endIndex);
    if(!result)return T100FALSE;

    return result;
}

T100BOOL T100ElementBidirectionSource::Deserialize()
{
    T100BOOL        result          = T100FALSE;

    m_element = T100NEW T100ElementBidirection();
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
