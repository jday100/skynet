#include "T100WxEventData.h"

T100WxEventData::T100WxEventData()
    :wxObject()
{
    //ctor
}

T100WxEventData::~T100WxEventData()
{
    //dtor
}

T100VOID T100WxEventData::setObject(T100VOID* object)
{
    m_object    = object;
}

T100VOID* T100WxEventData::getObject()
{
    return m_object;
}
