#include "T100LogNew.h"

#include "T100LogBase.h"


namespace T100Library{

T100LogNew::T100LogNew()
    :T100Class(),
    m_logs()
{
    //ctor
    create();
}

T100LogNew::~T100LogNew()
{
    //dtor
    destroy();
}

T100VOID T100LogNew::create()
{
    m_running   = T100FALSE;
    m_type      = T100LOG_TYPE_INFO;
}

T100VOID T100LogNew::destroy()
{
    m_logs.clear();
}

T100BOOL T100LogNew::start()
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    if(m_running){
        return T100FALSE;
    }

    m_running = T100TRUE;

    return T100TRUE;
}

T100BOOL T100LogNew::stop()
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    if(m_running){
        m_running = T100FALSE;
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100LogNew::running()
{
    return m_running;
}

T100BOOL T100LogNew::append(T100LogBase* log)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    T100LOG_VECTOR::iterator it;

    for(it = m_logs.begin(); it != m_logs.end(); it++){
        if(log == *it){
            return T100FALSE;
        }
    }

    m_logs.append(log);

    return T100TRUE;
}

T100BOOL T100LogNew::remove(T100LogBase* log)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    m_logs.remove(log);
    return T100FALSE;
}

T100VOID T100LogNew::fatal(T100WSTRING msg)
{
    outline(T100LOG_TYPE_FATAL, msg);
}

T100VOID T100LogNew::error(T100WSTRING msg)
{
    outline(T100LOG_TYPE_ERROR, msg);
}

T100VOID T100LogNew::warn(T100WSTRING msg)
{
    outline(T100LOG_TYPE_WARN, msg);
}

T100VOID T100LogNew::debug(T100WSTRING msg)
{
    outline(T100LOG_TYPE_DEBUG, msg);
}

T100VOID T100LogNew::trace(T100WSTRING msg)
{
    outline(T100LOG_TYPE_TRACE, msg);
}

T100VOID T100LogNew::info(T100WSTRING msg)
{
    outline(T100LOG_TYPE_INFO, msg);
}

T100VOID T100LogNew::outline(T100LOG_TYPE type, T100WSTRING msg)
{
    if(!m_running)return;
    if(type > m_type)return;

    std::lock_guard<std::mutex>     lock(m_mutex);

    T100LOG_VECTOR::iterator it;

    for(it = m_logs.begin(); it != m_logs.end(); it++){
        T100LogBase* log = *it;

        if(T100NULL == log){

        }else{
            log->outline(type, msg);
        }
    }
}

}
