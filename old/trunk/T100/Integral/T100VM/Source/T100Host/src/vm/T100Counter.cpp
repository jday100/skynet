#include "T100Counter.h"

#include <iostream>
#include "T100Host.h"

T100Counter::T100Counter(T100Host* host) :
    m_host(host)
{
    //ctor
    m_count     = 0;
}

T100Counter::~T100Counter()
{
    //dtor
}

void T100Counter::Pulse()
{
    std::cout << m_count << std::endl;
    m_count++;

    if(m_count > 100){
        m_host->m_generator.Stop();
    }
}
