#include "T100Generator.h"

#include "T100Host.h"

T100Generator::T100Generator(T100Host* host) :
    m_host(host)
{
    //ctor
    m_running   = false;
}

T100Generator::~T100Generator()
{
    //dtor
}

void T100Generator::Start()
{
    m_running   = true;
    while(m_running){
        m_host->Pulse();
    }
}

void T100Generator::Stop()
{
    m_running   = false;
}
