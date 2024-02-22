#ifndef T100WXCREATETHREAD_H
#define T100WXCREATETHREAD_H

#include <mutex>
#include <condition_variable>
#include "T100WXRunThread.h"
#include "T100VDISKCommon.h"
#include "T100VHDCommon.h"


class T100WXCreateThread : public T100WXRunThread
{
    public:
        T100WXCreateThread();
        virtual ~T100WXCreateThread();

        T100STRING                  m_filename;
        T100INT64                   m_length                = 0LL;
        T100VDISK_TYPE              m_type                  = T100VDISK_TYPE_NONE;
        T100VDISK_STORAGE_TYPE      m_storage               = T100VDISK_STORAGE_TYPE_NONE;

        T100VOID                    setCallback(T100THREAD_CALLBACK);
        T100VOID                    setValue(T100VOID*);

        virtual T100VOID            wait();

    protected:
        virtual T100VOID            run();

        static T100VOID             callback(T100VOID*, T100BYTE);

    private:
        std::mutex                  m_mutex;
        std::condition_variable     m_condition;
        T100THREAD_CALLBACK         m_callback          = T100NULL;
        T100VOID*                   m_value             = T100NULL;
};

#endif // T100WXCREATETHREAD_H
