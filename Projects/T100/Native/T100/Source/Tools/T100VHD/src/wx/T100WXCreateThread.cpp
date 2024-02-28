#include "T100WXCreateThread.h"

#include <wx/event.h>
#include "T100VDisk.h"
#include "T100CreateProgressDialog.h"


T100WXCreateThread::T100WXCreateThread()
    :T100WXRunThread()
{
    //ctor
}

T100WXCreateThread::~T100WXCreateThread()
{
    //dtor
}

T100VOID T100WXCreateThread::setValue(T100VOID* value)
{
    m_value     = value;
}

T100VOID T100WXCreateThread::setCallback(T100VDiskCallback* callback)
{
    m_callback  = callback;
}

T100VOID T100WXCreateThread::callback(T100VOID* frame, T100BYTE range)
{
    wxThreadEvent       event(wxEVT_THREAD, T100CreateProgressDialog::ID_THREAD_PROGRESS);

    event.SetInt(range);

    wxQueueEvent((wxEvtHandler*)frame, event.Clone());
}

T100VOID T100WXCreateThread::run()
{
    m_vdisk     = T100NEW T100VDisk(m_filename, m_length);

    m_vdisk->setValue(m_value);
    m_vdisk->setCallback(m_callback);
    m_vdisk->create(m_type, m_storage);

    m_condition.notify_all();

    T100DELETE  m_vdisk;
    m_vdisk = T100NULL;
}

T100VOID T100WXCreateThread::wait()
{
    std::unique_lock<std::mutex>        locker(m_mutex);

    m_condition.wait(locker);
    locker.unlock();
}

T100VOID T100WXCreateThread::cancel()
{
    m_vdisk->cancel();
}
