#include "T100ElementSource.h"

#include "T100ElementTransducerTarget.h"

T100ElementSource::T100ElementSource() :
    T100ElementSourceBase()
{
    //ctor
}

T100ElementSource::~T100ElementSource()
{
    //dtor
}

T100UINT T100ElementSource::GetType()
{
    return m_type;
}

T100UINT T100ElementSource::GetIndex()
{
    return m_index;
}

T100BOOL T100ElementSource::Serialize()
{
    T100BOOL        result          = T100FALSE;

    result = m_target->SetUINT(m_element->GetType());

    if(result){
        result = m_target->SetUINT(m_element->GetIndex());
    }

    return result;
}

T100BOOL T100ElementSource::Deserialize()
{
    T100BOOL        result          = T100FALSE;

    if(m_element){
        result = m_target->GetUINT(m_element->m_type);
        if(result){
            result = m_target->GetUINT(m_element->m_index);
        }
    }else{
        result = m_target->GetUINT(m_type);
        if(result){
            result = m_target->GetUINT(m_index);
        }
    }

    return result;
}
