#include "T100Memory.h"

#include <iostream>

T100Memory::T100Memory(T100Host* host) :
    m_host(host)
{
    //ctor
    m_flag  = false;
    m_count = 0;
}

T100Memory::~T100Memory()
{
    //dtor
}

void T100Memory::Pulse()
{
    if(m_flag){
        m_count++;
        if(m_count >= 5){
            m_ready = true;
        }
    }
}

void T100Memory::Request()
{
    m_flag  = true;
}

bool T100Memory::Ready()
{
    return m_ready;
}

void T100Memory::Read()
{
    if(m_flag){
        if(m_count >= 5){
            std::cout << "Read" << std::endl;
            m_flag  = false;
            m_ready = false;
            m_count = 0;
        }
    }else{
        m_count = 0;
        m_flag  = true;
    }
}
