#include "T100Host64.h"

T100Host64::T100Host64() :
    T100Host(),
    m_cpu(this),
    m_bus(this),
    m_memory(this),
    m_counter(this),
    m_generator(this),
    m_port(this)
{
    //ctor
    init();
}

T100Host64::~T100Host64()
{
    //dtor
    uninit();
}

T100VOID T100Host64::init()
{
    m_generator.SetFrequency(128 * 1024 * 1024);

    m_bus.PlugMemory(&m_memory);
}

T100VOID T100Host64::uninit()
{

}

T100BOOL T100Host64::Start()
{
    //m_generator.Start();

    m_thread    = T100NEW std::thread(&T100Generator64::Start, &m_generator);
}

T100BOOL T100Host64::Stop()
{
    m_generator.Stop();
}

T100VOID T100Host64::Debug()
{
    m_thread    = T100NEW std::thread(&T100Generator64::Start, &m_generator);
}

T100VOID T100Host64::Step()
{
    m_generator.Pulse();
}

T100VOID T100Host64::Info(T100DebugFrame* frame)
{
    m_cpu.Info(frame);
}

T100BOOL T100Host64::Pulse()
{
    m_counter.Pulse();
    m_cpu.Pulse();
    m_bus.Pulse();
    m_memory.Pulse();
}
