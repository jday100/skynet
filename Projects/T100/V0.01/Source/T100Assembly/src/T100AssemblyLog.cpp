#include "T100AssemblyLog.h"

T100LOG_LEVEL       T100AssemblyLog::m_level     = T100LOG_SENTENCE;


T100AssemblyLog::T100AssemblyLog()
{
    //ctor
}

T100AssemblyLog::~T100AssemblyLog()
{
    //dtor
}

T100VOID T100AssemblyLog::info(T100LOG_LEVEL level, T100WSTRING msg)
{
    if(level >= m_level){
        //T100WinConsole::out(msg);
    }
}
