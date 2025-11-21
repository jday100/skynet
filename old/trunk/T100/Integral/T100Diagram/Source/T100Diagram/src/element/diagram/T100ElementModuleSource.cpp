#include "T100ElementModuleSource.h"

#include "T100ElementTransducerTarget.h"

T100ElementModuleSource::T100ElementModuleSource(T100ElementModule* element) :
    T100ElementSourceBase(),
    m_element(element)
{
    //ctor
}

T100ElementModuleSource::~T100ElementModuleSource()
{
    //dtor
}

T100BOOL T100ElementModuleSource::Serialize()
{
    T100BOOL        result          = T100FALSE;

    if(T100ElementSourceBase::m_element){
        m_element = (T100ElementModule*)T100ElementSourceBase::m_element;
    }

    result = m_target->SetSTRING(m_element->m_name);
    if(!result)return T100FALSE;

    result = m_target->SetUINT(m_element->m_originX);
    if(!result)return T100FALSE;

    result = m_target->SetUINT(m_element->m_originY);
    if(!result)return T100FALSE;

    result = m_target->SetUINT(m_element->m_width);
    if(!result)return T100FALSE;

    result = m_target->SetUINT(m_element->m_height);
    if(!result)return T100FALSE;

    return result;
}

T100BOOL T100ElementModuleSource::Deserialize()
{
    T100BOOL        result          = T100FALSE;

    m_element = T100NEW T100ElementModule();
    if(m_element){
        T100ElementSourceBase::m_element = m_element;

        result = m_target->GetSTRING(m_element->m_name);
        if(result){
            result = m_target->GetUINT(m_element->m_originX);
        }
        if(result){
            result = m_target->GetUINT(m_element->m_originY);
        }
        if(result){
            result = m_target->GetUINT(m_element->m_width);
        }
        if(result){
            result = m_target->GetUINT(m_element->m_height);
        }
        if(!result){
            T100SAFE_DELETE(m_element);
        }
    }

    return result;
}
