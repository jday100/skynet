#include "T100Host.h"

#include <thread>
#include <iostream>

T100Host::T100Host() :
    m_cpu(this),
    m_memory(this),
    m_counter(this),
    m_generator(this)
{
    //ctor
}

T100Host::~T100Host()
{
    //dtor
}

void T100Host::Start()
{
    m_generator.Start();

    //std::thread* thread = new std::thread(&T100Generator::Start, &m_generator);

    //std::thread thread(&T100Generator::Start, &m_generator);

    //thread.detach();
}

void T100Host::Pulse()
{
    //std::cout << "Pulse" << std::endl;

    m_counter.Pulse();
    m_cpu.Pulse();
    m_memory.Pulse();
}
