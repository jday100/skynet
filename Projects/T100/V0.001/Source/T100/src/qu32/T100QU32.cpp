#include "T100QU32.h"
#include "T100QU32Setup.h"
#include "T100HintQU32.h"
#include "T100Error.h"
#include "T100Font.h"


T100QU32::T100QU32()
    :IComputer()
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
    T100Log::trace(T100QU32_HINT_START);

    m_running       = T100FALSE;

    m_au            = T100NEW T100AU32(this);
    m_cu            = T100NEW T100CU32(this);
    m_memory        = T100NEW T100Memory32(this, T100QU32Setup::m_rom_size, T100QU32Setup::m_ram_size);
    //
    m_manager       = T100NEW T100Manager32(this);
    m_interrupt     = T100NEW T100Interrupt32(this);
    m_executor      = T100NEW T100Executor32(this);
    //
    m_created       = T100TRUE;

    m_manager->init();
}

T100VOID T100QU32::destroy()
{
    m_created       = T100FALSE;

    T100DELETE(m_executor);
    T100DELETE(m_interrupt);
    T100DELETE(m_manager);
    T100DELETE(m_memory);
    T100DELETE(m_cu);
    T100DELETE(m_au);

    T100Log::trace(T100QU32_HINT_STOP);
}

T100CU32* T100QU32::getCU32()
{
    if(!m_created)return T100NULL;
    return m_cu;
}

T100AU32* T100QU32::getAU32()
{
    if(!m_created)return T100NULL;
    return m_au;
}

T100Memory32* T100QU32::getMemory32()
{
    if(!m_created)return T100NULL;
    return m_memory;
}

T100Manager32* T100QU32::getManager32()
{
    if(!m_created)return T100NULL;
    return m_manager;
}

T100Interrupt32* T100QU32::getInterrupt32()
{
    if(!m_created)return T100NULL;
    return m_interrupt;
}

T100Executor32* T100QU32::getExecutor32()
{
    if(!m_created)return T100NULL;
    return m_executor;
}

//

ICU* T100QU32::getCU()
{
    if(!m_created)return T100NULL;
    return(ICU*)m_cu;
}

IAU* T100QU32::getAU()
{
    if(!m_created)return T100NULL;
    return(IAU*)m_au;
}

IMemory* T100QU32::getMemory()
{
    if(!m_created)return T100NULL;
    return(IMemory*)m_memory;
}

IManager* T100QU32::getManager()
{
    if(!m_created)return T100NULL;
    return(IManager*)m_manager;
}

IInterrupt* T100QU32::getInterrupt()
{
    if(!m_created)return T100NULL;
    return(IInterrupt*)m_interrupt;
}

IExecutor* T100QU32::getExecutor()
{
    if(!m_created)return T100NULL;
    return(IExecutor*)m_executor;
}

T100BOOL T100QU32::start()
{
    T100Log::info(T100HintQU32::vpc_hint("Start"));

    if(m_cu && T100QU32Setup::m_base){
        m_cu->setCBR(T100QU32Setup::m_offset);
    }

    if(m_memory && (!T100QU32Setup::m_file.empty())){
        if(m_memory->load(T100String(T100QU32Setup::m_file), T100QU32Setup::m_offset)){

        }else{
            return T100FALSE;
        }
    }

    if(!load())return T100FALSE;

    m_running = T100TRUE;
    m_executor->start();

    T100QU32Callback::callStart();

    return T100TRUE;
}

T100BOOL T100QU32::stop()
{
    m_running = T100FALSE;
    m_executor->stop();

    T100QU32Setup::m_return = m_au->getAAR();

    T100Log::info(T100HintQU32::vpc_hint("Stop"));

    return T100TRUE;
}

T100BOOL T100QU32::wait()
{
    if(m_running){
        m_executor->wait();
    }
    return T100TRUE;
}

T100BOOL T100QU32::pause()
{
    if(m_running){
        m_executor->pause();
    }
    return T100TRUE;
}

T100BOOL T100QU32::resume()
{
    if(m_running){
        m_executor->resume();
    }
    return T100TRUE;
}

T100BOOL T100QU32::step()
{
    if(m_running){
        m_executor->step();
    }
    return T100TRUE;
}

T100BOOL T100QU32::next()
{
    if(m_running){
        m_executor->next();
    }
    return T100TRUE;
}

T100BOOL T100QU32::isRunning()
{
    return m_running;
}

T100BOOL T100QU32::load(T100String file, T100WORD offset)
{
    T100BOOL    result;

    result = m_memory->load(file, offset);

    return result;
}

T100BOOL T100QU32::load()
{
    T100BOOL    result      = T100TRUE;
    T100WORD    offset      = 0;

    if(0 == T100QU32Setup::m_files.size()){
        return T100TRUE;
    }

    for(auto item : T100QU32Setup::m_files){
        if(item){
            result = load(item->FILE, item->OFFSET);
            if(!result)return T100FALSE;
            if(0 == offset){
                offset  = item->OFFSET;
            }else if(offset > item->OFFSET){
                offset  = item->OFFSET;
            }
        }else{
            return T100FALSE;
        }
    }

    if(m_cu){
        m_cu->setCBR(offset);
    }

    return result;
}


T100BOOL T100QU32::done()
{
    m_running   = T100FALSE;

    T100QU32Setup::m_return = m_au->getAAR();

    m_executor->done();

    T100Log::info(T100HintQU32::vpc_hint("Done"));

    return T100TRUE;
}

T100BOOL T100QU32::debug()
{
    m_executor->pause();

    return T100TRUE;
}
