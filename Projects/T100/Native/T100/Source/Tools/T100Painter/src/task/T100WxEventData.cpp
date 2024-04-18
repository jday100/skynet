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

T100VOID T100WxEventData::setIndex(T100INT index)
{
    m_index = index;
}

T100INT T100WxEventData::getIndex()
{
    return m_index;
}

T100VOID T100WxEventData::setTitle(T100STRING title)
{
    m_title = title;
}

T100STRING T100WxEventData::getTitle()
{
    return m_title;
}

T100VOID T100WxEventData::setData(T100VOID* data)
{
    m_data  = data;
}

T100VOID* T100WxEventData::getData()
{
    return m_data;
}
