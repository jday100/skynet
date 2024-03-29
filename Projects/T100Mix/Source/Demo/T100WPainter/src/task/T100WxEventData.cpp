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

T100VOID T100WxEventData::setData(T100VOID* data)
{
    m_data  = data;
}

T100VOID* T100WxEventData::getData()
{
    return m_data;
}
