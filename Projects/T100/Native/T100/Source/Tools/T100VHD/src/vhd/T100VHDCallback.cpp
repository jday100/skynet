#include "T100VHDCallback.h"

T100VHDCallback::T100VHDCallback()
    :T100VDiskCallback()
{
    //ctor
}

T100VHDCallback::~T100VHDCallback()
{
    //dtor
}

T100VOID T100VHDCallback::setCreateCallback(T100THREAD_CALLBACK callback)
{
    m_create_callback   = callback;
}

T100VOID T100VHDCallback::setCreateFinishedCallback(T100THREAD_CALLBACK callback)
{
    m_create_finished_callback  = callback;
}

T100THREAD_CALLBACK T100VHDCallback::getCreateCallback()
{
    return m_create_callback;
}

T100VOID T100VHDCallback::create(T100VOID* frame, T100BYTE range)
{
    m_create_callback(frame, range);
}

T100VOID T100VHDCallback::create_finished(T100VOID* frame, T100BYTE range)
{
    m_create_finished_callback(frame, range);
}
