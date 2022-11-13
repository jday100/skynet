#include "T100AssemblyLog.h"

namespace T100Assembly{

T100LOG_LEVEL       T100AssemblyLog::m_level            = T100LOG_SENTENCE;

T100AssemblyLog::T100AssemblyLog()
    :T100Library::T100Log()
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

    }
}

}
