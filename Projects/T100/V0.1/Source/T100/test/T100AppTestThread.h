#ifndef T100APPTESTTHREAD_H
#define T100APPTESTTHREAD_H

#include "T100String.h"
#include "T100Thread.h"

namespace T100{

class T100AppTestThread : public T100Library::T100Thread
{
    public:
        T100AppTestThread();
        virtual ~T100AppTestThread();

        T100VOID            unit(T100WSTRING);

        T100VOID            list();

    protected:
        T100VOID            run();

    private:
        T100BOOL            m_list          = T100FALSE;
        T100WSTRING         m_name;

};

}

#endif // T100APPTESTTHREAD_H
