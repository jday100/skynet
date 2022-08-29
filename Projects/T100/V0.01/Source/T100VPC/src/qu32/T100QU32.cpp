#include "T100QU32.h"

#include "T100String.h"


T100QU32::T100QU32()
{
    //ctor
    create();
}

T100QU32::~T100QU32()
{
    //dtor
    destroy();
}

T100VOID T100QU32::create()
{

}

T100VOID T100QU32::destroy()
{

}

T100CU32* T100QU32::getCU32()
{
    return m_cu;
}

T100AU32* T100QU32::getAU32()
{
    return m_au;
}

T100Memory32* T100QU32::getMemory32()
{
    return m_memory;
}

T100Port32* T100QU32::getPort32()
{
    return m_port;
}

T100Interrupt32* T100QU32::getInterrupt32()
{
    return m_interrupt;
}

T100Executor32* T100QU32::getExecutor32()
{
    return m_executor;
}

T100BOOL T100QU32::start()
{
    m_cu        = T100NEW T100CU32(this);
    m_au        = T100NEW T100AU32(this);
    m_memory    = T100NEW T100Memory32(this);
    m_port      = T100NEW T100Port32(this);
    m_interrupt = T100NEW T100Interrupt32(this);
    m_executor  = T100NEW T100Executor32(this);

    m_port->create();

    if(!load()){
        return T100FALSE;
    }

    return m_executor->start();
}

T100BOOL T100QU32::stop()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = m_executor->stop();

    T100SAFE_DELETE(m_executor);
    T100SAFE_DELETE(m_interrupt);
    T100SAFE_DELETE(m_port);
    T100SAFE_DELETE(m_memory);
    T100SAFE_DELETE(m_au);
    T100SAFE_DELETE(m_cu);

    return T100TRUE;
}

T100BOOL T100QU32::done()
{

}

T100BOOL T100QU32::load(T100STRING file, T100WORD location, T100WORD length)
{
    return m_memory->load(file, location, length);
}

T100BOOL T100QU32::load()
{
    T100BOOL            result          = T100TRUE;

    if(T100QU32Setup::needLoadRom){
        T100String      file;

        file = T100QU32Setup::getRomFile();
        result = m_memory->load(file, 0, 0);
        if(!result){
            return T100FALSE;
        }
    }

    return result;
}
