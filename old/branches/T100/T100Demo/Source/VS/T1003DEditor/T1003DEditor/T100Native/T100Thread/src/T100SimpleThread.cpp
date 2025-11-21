#include "T100SimpleThread.h"

#include <functional>

T100SimpleThread::T100SimpleThread()
{
    //ctor
}

template<typename _Callable, typename... _Args>
T100SimpleThread::T100SimpleThread(_Callable&& __f, _Args&&... __args)
{
    //ctor
    T100NEW std::thread(std::forward<_Args>(__args)...);
}

template<typename _Callable>
T100SimpleThread::T100SimpleThread(_Callable&& __f, void*&& v)
{

}

T100SimpleThread::~T100SimpleThread()
{
    //dtor
}

/*
T100VOID T100SimpleThread::Start()
{
    T100NEW std::thread(run, instance);
}
*/
