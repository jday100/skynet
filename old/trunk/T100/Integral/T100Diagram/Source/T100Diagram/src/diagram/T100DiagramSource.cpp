#include "T100DiagramSource.h"

#include "T100DiagramCommon.h"
#include "T100DiagramTransducerTarget.h"

T100DiagramSource::T100DiagramSource() :
    T100DiagramSourceBase()
{
    //ctor
}

T100DiagramSource::~T100DiagramSource()
{
    //dtor
}

T100UINT T100DiagramSource::GetSign()
{
    return m_sign;
}

T100UINT T100DiagramSource::GetType()
{
    return m_type;
}

T100UINT T100DiagramSource::GetVersion()
{
    return m_version;
}

T100UINT T100DiagramSource::GetWidth()
{
    return m_width;
}

T100UINT T100DiagramSource::GetHeight()
{
    return m_height;
}

T100BOOL T100DiagramSource::Serialize()
{
    T100BOOL                result      = T100FALSE;
    T100DIAGRAM_HEAD*       head        = T100NULL;

    head = m_diagram->GetHead();

    if(head){
        result = m_target->SetUINT(head->COMMON.SIGN);
        if(!result)return T100FALSE;

        result = m_target->SetUINT(head->TYPE);
        if(!result)return T100FALSE;

        result = m_target->SetUINT(head->VERSION);
    }

    T100DIAGRAM_CANVAS*     canvas      = T100NULL;

    canvas  = m_diagram->GetCanvas();
    if(result && canvas){
        result = m_target->SetUINT(canvas->WIDTH);
        if(!result)return T100FALSE;

        result = m_target->SetUINT(canvas->HEIGHT);
        if(!result)return T100FALSE;
    }
    return result;
}

T100BOOL T100DiagramSource::Deserialize()
{
    T100BOOL        result          = T100FALSE;

    if(m_diagram){
        result = m_target->GetUINT(m_diagram->GetHead()->COMMON.SIGN);
        if(!result)return T100FALSE;

        result = m_target->GetUINT(m_diagram->GetHead()->TYPE);
        if(!result)return T100FALSE;

        result = m_target->GetUINT(m_diagram->GetHead()->VERSION);
        if(!result)return T100FALSE;

        result = m_target->GetUINT(m_diagram->GetCanvas()->WIDTH);
        if(!result)return T100FALSE;

        result = m_target->GetUINT(m_diagram->GetCanvas()->HEIGHT);
        if(!result)return T100FALSE;

    }else{
        result = m_target->GetUINT(m_sign);
        if(!result)return T100FALSE;

        result = m_target->GetUINT(m_type);
        if(!result)return T100FALSE;

        result = m_target->GetUINT(m_version);
        if(!result)return T100FALSE;

        result = m_target->GetUINT(m_width);
        if(!result)return T100FALSE;

        result = m_target->GetUINT(m_height);
        if(!result)return T100FALSE;
    }

    return result;
}
