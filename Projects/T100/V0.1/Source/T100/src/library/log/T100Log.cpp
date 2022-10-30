#include "T100Log.h"

#include "T100LogBase.h"

namespace T100Library{

std::atomic_bool                T100Log::m_running;
T100LOG_TYPE                    T100Log::m_type                 = T100LOG_TYPE_INFO;
T100LOG_VECTOR                  T100Log::m_logs;


T100Log::T100Log()
    :T100Class()
{
    //ctor
    create();
}

T100Log::~T100Log()
{
    //dtor
    destroy();
}

T100VOID T100Log::create()
{
    m_running = T100FALSE;
}

T100VOID T100Log::destroy()
{

}

T100BOOL T100Log::start()
{
    if(m_running){
        return T100FALSE;
    }

    m_running = T100TRUE;

    return T100TRUE;
}

T100BOOL T100Log::stop()
{
    if(m_running){
        m_running = T100FALSE;
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Log::running()
{
    return m_running;
}

T100BOOL T100Log::append(T100LogBase* log)
{
    T100LOG_VECTOR::iterator it;

    for(it = m_logs.begin(); it != m_logs.end(); it++){
        if(log == *it){
            return T100FALSE;
        }
    }

    m_logs.push_back(log);

    return T100TRUE;
}

T100BOOL T100Log::remove(T100LogBase* log)
{
    T100LOG_VECTOR::iterator it;

    for(it = m_logs.begin(); it != m_logs.end(); it++){
        if(log == *it){
            m_logs.erase(it);
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100VOID T100Log::fatal(T100WSTRING msg)
{
    outline(T100LOG_TYPE_FATAL, msg);
}

T100VOID T100Log::error(T100WSTRING msg)
{
    outline(T100LOG_TYPE_ERROR, msg);
}

T100VOID T100Log::warn(T100WSTRING msg)
{
    outline(T100LOG_TYPE_WARN, msg);
}

T100VOID T100Log::debug(T100WSTRING msg)
{
    outline(T100LOG_TYPE_DEBUG, msg);
}

T100VOID T100Log::trace(T100WSTRING msg)
{
    outline(T100LOG_TYPE_TRACE, msg);
}

T100VOID T100Log::info(T100WSTRING msg)
{
    outline(T100LOG_TYPE_INFO, msg);
}

T100VOID T100Log::outline(T100LOG_TYPE type, T100WSTRING msg)
{
    if(!m_running)return;
    if(type > m_type)return;

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
