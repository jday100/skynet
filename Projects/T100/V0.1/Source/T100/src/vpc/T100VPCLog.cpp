#include "T100VPCLog.h"

namespace T100VPC{

T100Library::T100LogNew         T100VPCLog::m_log;

T100VPCLog::T100VPCLog()
{
    //ctor
}

T100VPCLog::~T100VPCLog()
{
    //dtor
}

T100BOOL T100VPCLog::start()
{
    return m_log.start();
}

T100BOOL T100VPCLog::stop()
{
    return m_log.stop();
}

T100BOOL T100VPCLog::running()
{
    return m_log.running();
}

T100BOOL T100VPCLog::append(T100Library::T100LogBase* log)
{
    return m_log.append(log);
}

T100BOOL T100VPCLog::remove(T100Library::T100LogBase* log)
{
    return m_log.remove(log);
}

T100VOID T100VPCLog::fatal(T100STRING msg)
{
    m_log.fatal(msg.to_wstring());
}

T100VOID T100VPCLog::error(T100STRING msg)
{
    m_log.error(msg.to_wstring());
}

T100VOID T100VPCLog::warn(T100STRING msg)
{
    m_log.warn(msg.to_wstring());
}

T100VOID T100VPCLog::debug(T100STRING msg)
{
    m_log.debug(msg.to_wstring());
}

T100VOID T100VPCLog::trace(T100STRING msg)
{
    m_log.trace(msg.to_wstring());
}

T100VOID T100VPCLog::info(T100STRING msg)
{
    m_log.info(msg.to_wstring());
}

}
