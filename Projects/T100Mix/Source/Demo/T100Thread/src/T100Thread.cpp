#include "T100Thread.h"

#include <chrono>
#include <functional>

T100Thread::T100Thread()
{
    //ctor
}

T100Thread::~T100Thread()
{
    //dtor
}

void T100Thread::start()
{
    //auto  method = std::bind(T100Thread::run, this);
    //m_thread    = new std::thread(method);

    m_thread    = new std::thread(m_method);
}

void T100Thread::stop()
{

}

void T100Thread::run()
{

}

void T100Thread::sleep(int value)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(value));
}
