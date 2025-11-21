#ifndef T100SIMPLETHREAD_H
#define T100SIMPLETHREAD_H

#include <thread>
#include "T100Common.h"

class T100SimpleThread
{
    public:
        T100SimpleThread();
        template<typename _Callable, typename... _Args> explicit
        T100SimpleThread(_Callable&& __f, _Args&&... __args);

        template<typename _Callable> explicit
        T100SimpleThread(_Callable&& __f, void*&&);

        virtual ~T100SimpleThread();

    protected:

    private:
};

#endif // T100SIMPLETHREAD_H
