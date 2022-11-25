#include "T100QU32.h"

#include "T100String.h"

namespace T100QU32{

T100QU32::T100QU32()
{
    //ctor
}

T100QU32::~T100QU32()
{
    //dtor
    destroy();
}

T100BOOL T100QU32::create()
{
    m_cu            = T100NEW T100CU32(this);
    m_au            = T100NEW T100AU32(this);
    m_memory        = T100NEW T100Memory32(this);
    m_port          = T100NEW T100Port32(this);
    m_interrupt     = T100NEW T100Interrupt32(this);
    m_executor      = T100NEW T100Executor32(this);

    m_port->create();
    return T100TRUE;
}

T100VOID T100QU32::destroy()
{

}

T100WORD T100QU32::getReturn()
{
    return m_return;
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
    if(!load()){
        return T100FALSE;
    }

    if(!m_callback->notify_start()){
        return T100FALSE;
    }
    return m_executor->start();
}

T100BOOL T100QU32::stop()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = m_executor->stop();

    if(value){
        if(!m_callback->notify_stop()){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    T100SAFE_DELETE(m_executor);
    T100SAFE_DELETE(m_interrupt);
    T100SAFE_DELETE(m_port);
    T100SAFE_DELETE(m_memory);
    T100SAFE_DELETE(m_au);
    T100SAFE_DELETE(m_cu);

    return result;
}

T100BOOL T100QU32::wait()
{
    m_executor->wait();
    return T100TRUE;
}

T100BOOL T100QU32::running()
{
    if(m_executor){
        return m_executor->running();
    }
    return T100FALSE;
}

T100BOOL T100QU32::exec(T100WORD base, T100WORD offset)
{
    m_cu->setCBR(base);
    m_cu->setCOR(offset);
    return m_executor->start();
}

T100BOOL T100QU32::pause()
{
    m_executor->pause();

    m_executor->hangup();
    return T100TRUE;
}

T100BOOL T100QU32::run()
{
    m_executor->resume();

    m_executor->wakeup();
    return T100TRUE;
}

T100BOOL T100QU32::resume()
{
    m_executor->wakeup();
    return T100TRUE;
}

T100BOOL T100QU32::step()
{
    m_executor->step();
    return T100TRUE;
}

T100BOOL T100QU32::next()
{
    m_executor->next();
    return T100TRUE;
}

T100BOOL T100QU32::nextComment()
{
    m_executor->nextComment();
    return T100TRUE;
}

T100BOOL T100QU32::nextCall()
{
    m_executor->nextCall();
    return T100TRUE;
}

T100BOOL T100QU32::nextReturn()
{
    m_executor->nextReturn();
    return T100TRUE;
}

T100BOOL T100QU32::halt()
{
    m_executor->stop();
    return T100TRUE;
}

T100BOOL T100QU32::load(T100STRING file, T100WORD location)
{
    return m_memory->load(file, location);
}

T100BOOL T100QU32::load()
{
    T100BOOL        result          = T100TRUE;

    if(T100QU32Setup::NEED_LOAD_ROM){
        T100STRING      file;

        file    = T100QU32Setup::getRomFile();
        result  = m_memory->load(file, 0);
        if(!result){
            return T100FALSE;
        }
    }

    for(T100PRELOAD_ITEM*   item : T100QU32Setup::getPreloadFiles()){
        if(item){
            result = m_memory->load(item->FILE, item->OFFSET);
            if(!result){
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100VOID T100QU32::setCallback(T100QU32Interface* callback)
{
    m_callback = callback;
}

T100QU32Interface* T100QU32::getCallback()
{
    return m_callback;
}

T100QU32Notifier& T100QU32::getNotifier()
{
    return m_notifier;
}

}
