#ifndef T100WXRUNTHREAD_H
#define T100WXRUNTHREAD_H

#include "T100Thread.h"

typedef     (*T100THREAD_CALLBACK)(T100VOID*, T100BYTE);


class T100WXRunThread : public T100Thread
{
    public:
        T100WXRunThread();
        virtual ~T100WXRunThread();

    protected:

    private:
};

#endif // T100WXRUNTHREAD_H
