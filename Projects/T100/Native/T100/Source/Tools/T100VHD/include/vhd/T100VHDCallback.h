#ifndef T100VHDCALLBACK_H
#define T100VHDCALLBACK_H

#include "T100WXRunThread.h"
#include "T100VDiskCallback.h"


class T100VHDCallback : public T100VDiskCallback
{
    public:
        T100VHDCallback();
        virtual ~T100VHDCallback();

        virtual T100VOID            create(T100VOID*, T100BYTE);
        virtual T100VOID            create_finished(T100VOID*, T100BYTE);

        virtual T100VOID            open(T100VOID*, T100BYTE);
        virtual T100VOID            open_finished(T100VOID*, T100BYTE);

        T100VOID    setCreateCallback(T100THREAD_CALLBACK);
        T100VOID    setCreateFinishedCallback(T100THREAD_CALLBACK);

        T100VOID    setOpenCallback(T100THREAD_CALLBACK);
        T100VOID    setOpenFinishedCallback(T100THREAD_CALLBACK);

        T100THREAD_CALLBACK         getCreateCallback();
        T100THREAD_CALLBACK         getOpenCallback();

    protected:

    private:
        T100THREAD_CALLBACK         m_create_callback           = T100NULL;
        T100THREAD_CALLBACK         m_create_finished_callback  = T100NULL;

        T100THREAD_CALLBACK         m_open_callback             = T100NULL;
        T100THREAD_CALLBACK         m_open_finished_callback    = T100NULL;
};

#endif // T100VHDCALLBACK_H
