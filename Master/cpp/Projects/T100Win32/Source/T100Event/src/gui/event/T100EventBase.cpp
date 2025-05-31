#include "gui/event/T100EventBase.h"

T100EventBase::T100EventBase(T100WindowMessageData& data) :
    T100Class(),
    m_messageData(data)
{
    //ctor
}

T100EventBase::~T100EventBase()
{
    //dtor
}

T100WindowMessageData& T100EventBase::GetMessageData()
{
    return m_messageData;
}
