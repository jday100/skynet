#include "T100Bus64.h"

#include "T100Memory64.h"


T100Bus64::T100Bus64()
{
    //ctor
}

T100Bus64::~T100Bus64()
{
    //dtor
}

T100VOID T100Bus64::setCpu(T100Cpu64* cpu)
{
    m_cpu       = cpu;
}

T100VOID T100Bus64::setMemory(T100Memory64* memory)
{
    m_memory    = memory;
}

T100VOID T100Bus64::setPort(T100Port64* port)
{
    m_port      = port;
}

T100VOID T100Bus64::read(T100BUS_SIGNAL signal, INT64 offset, INT64& data)
{
    switch(signal){
    case T100BUS_SELECT_CPU:
        {

        }
        break;
    case T100BUS_SELECT_MEMORY:
        {
            m_memory->read(offset, data);
        }
        break;
    case T100BUS_SELECT_PORT:
        {

        }
        break;
    }
}

T100VOID T100Bus64::write(T100BUS_SIGNAL signal, INT64 offset, INT64 data)
{
    switch(signal){
    case T100BUS_SELECT_CPU:
        {

        }
        break;
    case T100BUS_SELECT_MEMORY:
        {

        }
        break;
    case T100BUS_SELECT_PORT:
        {

        }
        break;
    }
}
