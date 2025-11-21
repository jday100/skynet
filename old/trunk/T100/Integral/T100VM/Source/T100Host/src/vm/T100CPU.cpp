#include "T100CPU.h"

#include <iostream>
#include "T100Host.h"

T100CPU::T100CPU(T100Host* host) :
    m_host(host)
{
    //ctor
    m_flag  = false;
    m_ready = false;
    m_request   = false;
    m_count = 0;
}

T100CPU::~T100CPU()
{
    //dtor
}

void T100CPU::Pulse()
{
    if(m_flag){
        m_count++;
        if(m_count >= 3){
            if(m_request){
                m_ready = m_host->m_memory.Ready();
                if(m_ready){
                    m_host->m_memory.Read();
                    m_flag  = false;
                    m_ready = false;
                    m_request   = false;
                    m_count = 0;
                }
            }else{
                m_host->m_memory.Request();
                m_request   = true;
            }
        }
        //std::cout << "count" << m_count << std::endl;
    }else{
        m_count = 0;
        m_request   = false;
        m_ready = false;
        m_flag  = true;
    }
}
