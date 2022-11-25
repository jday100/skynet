#ifndef T100APPTESTTHREAD_H
#define T100APPTESTTHREAD_H

#include "T100Thread.h"

namespace T100{

class T100AppTestThread : public T100Library::T100Thread
{
    public:
        T100AppTestThread();
        virtual ~T100AppTestThread();

    protected:
        T100VOID            run();

    private:
};

}

#endif // T100APPTESTTHREAD_H
