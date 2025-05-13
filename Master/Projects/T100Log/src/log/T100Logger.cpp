#include "T100Logger.h"

#include "log/T100LogBase.h"

std::atomic_bool                T100Logger::m_running;
T100LOG_TYPE                    T100Logger::m_logType           = T100LOG_TYPE_INFO;
T100LOG_VECTOR                  T100Logger::m_logs;

T100Logger::T100Logger() :
    T100Class()
{
    //ctor
}

T100Logger::~T100Logger()
{
    //dtor
}

T100VOID T100Logger::init()
{
    m_running   = T100FALSE;
}

T100VOID T100Logger::uninit()
{

}

T100VOID T100Logger::Start()
{
    if(m_running){
        return;
    }

    m_running   = T100TRUE;
}

T100VOID T100Logger::Stop()
{
    if(m_running){
        m_running   = T100FALSE;
    }
}

T100BOOL T100Logger::IsRunning()
{
    return m_running;
}

T100BOOL T100Logger::Append(T100LogBase* log)
{
    T100LOG_VECTOR::iterator    it;

    for(it = m_logs.begin(); it != m_logs.end(); it++){
        if(log == *it){
            return T100FALSE;
        }
    }

    m_logs.push_back(log);
    return T100TRUE;
}

T100BOOL T100Logger::Remove(T100LogBase* log)
{
    T100LOG_VECTOR::iterator    it;

    for(it = m_logs.begin(); it != m_logs.end(); it++){
        if(log == *it){
            m_logs.erase(it);
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100VOID T100Logger::Fatal(T100WSTRING value)
{
    OutLine(T100LOG_TYPE_FATAL, value);
}

T100VOID T100Logger::Error(T100WSTRING value)
{
    OutLine(T100LOG_TYPE_ERROR, value);
}

T100VOID T100Logger::Warn(T100WSTRING value)
{
    OutLine(T100LOG_TYPE_WARN, value);
}

T100VOID T100Logger::Debug(T100WSTRING value)
{
    OutLine(T100LOG_TYPE_DEBUG, value);
}

T100VOID T100Logger::Trace(T100WSTRING value)
{
    OutLine(T100LOG_TYPE_TRACE, value);
}

T100VOID T100Logger::Info(T100WSTRING value)
{
    OutLine(T100LOG_TYPE_INFO, value);
}

T100VOID T100Logger::OutLine(T100LOG_TYPE type, T100WSTRING value)
{
    if(!m_running)return;
    if(type > m_logType)return;

    T100LOG_VECTOR::iterator it;

    for(it = m_logs.begin(); it != m_logs.end(); it++){
        T100LogBase* log = *it;

        if(T100NULL == log){

        }else{
            log->OutLine(type, value);
        }
    }
}
