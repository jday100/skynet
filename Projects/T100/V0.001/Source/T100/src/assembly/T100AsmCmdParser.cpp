#include "T100AsmCmdParser.h"


T100AsmCmdParser::T100AsmCmdParser()
{
    //ctor
}

T100AsmCmdParser::~T100AsmCmdParser()
{
    //dtor
}

T100INTEGER T100AsmCmdParser::parse(T100COMMAND_VECTOR& cmd)
{
    T100BOOL        result      = T100FALSE;
    T100WORD        size;

    size = cmd.size();

    switch(size)
    {
    case 1:
        {
            //quit
            //step
            //run
            if("step" == cmd[0]){
                result = step();
            }else if("run" == cmd[0]){
                result = run();
            }
        }
        break;
    case 2:
        {
            //log       on|off|n|byte|string|keyword|sentence|segment|file
            //detail    true|false
            //show      n
            if("log" == cmd[0]){
                result = log(cmd[1]);
            }else if("detail" == cmd[0]){
                result = detail(cmd[1]);
            }else if("show" == cmd[0]){
                result = show(cmd[1]);
            }
        }
        break;
    case 3:
        {
            //show n l
            if("show" == cmd[0]){
                result = show(cmd[1], cmd[2]);
            }
        }
        break;
    };

    if(result){
        return 0;
    }

    return -1;
}

T100BOOL T100AsmCmdParser::quit()
{
    return T100FALSE;
}

T100BOOL T100AsmCmdParser::step()
{
    return T100FALSE;
}

T100BOOL T100AsmCmdParser::run()
{
    return T100FALSE;
}

T100BOOL T100AsmCmdParser::log(T100STDSTRING para)
{
    if("on" == para){
        T100AssemblyLog::start();
    }else if("off" == para){
        T100AssemblyLog::stop();
    }else if("byte" == para){
        T100AssemblyLog::m_level = T100LOG_BYTE;
    }else if("char" == para){
        T100AssemblyLog::m_level = T100LOG_CHAR;
    }else if("string" == para){
        T100AssemblyLog::m_level = T100LOG_STRING;
    }else if("keyword" == para){
        T100AssemblyLog::m_level = T100LOG_KEYWORD;
    }else if("sentence" == para){
        T100AssemblyLog::m_level = T100LOG_SENTENCE;
    }else if("file" == para){
        T100AssemblyLog::m_level = T100LOG_FILE;
    //}else if("all" == para){
    //    T100AssemblyLog::m_level = T100LOG_ALL;
    }else if("fatal" == para){
        T100AssemblyLog::m_type = T100LOG_TYPE_FATAL;
    }else if("error" == para){
        T100AssemblyLog::m_type = T100LOG_TYPE_ERROR;
    }else if("warn" == para){
        T100AssemblyLog::m_type = T100LOG_TYPE_WARN;
    }else if("debug" == para){
        T100AssemblyLog::m_type = T100LOG_TYPE_DEBUG;
    }else if("trace" == para){
        T100AssemblyLog::m_type = T100LOG_TYPE_TRACE;
    }else if("info" == para){
        T100AssemblyLog::m_type = T100LOG_TYPE_INFO;
    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100AsmCmdParser::detail(T100STDSTRING para)
{
    if("on" == para){
        T100AssemblyHint::m_detail  = T100TRUE;
    }else if("off" == para){
        T100AssemblyHint::m_detail  = T100FALSE;
    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100AsmCmdParser::show(T100STDSTRING para)
{
    if("on" == para){
        T100AssemblyLog::start();
    }else if("off" == para){
        T100AssemblyLog::stop();
    }else if("byte" == para){
        T100AssemblyLog::m_level = T100LOG_BYTE;
    }else if("char" == para){
        T100AssemblyLog::m_level = T100LOG_CHAR;
    }else if("string" == para){
        T100AssemblyLog::m_level = T100LOG_STRING;
    }else if("keyword" == para){
        T100AssemblyLog::m_level = T100LOG_KEYWORD;
    }else if("sentence" == para){
        T100AssemblyLog::m_level = T100LOG_SENTENCE;
    }else if("file" == para){
        T100AssemblyLog::m_level = T100LOG_FILE;
    }else if("all" == para){
        T100AssemblyLog::m_level = T100LOG_ALL;
    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100AsmCmdParser::show(T100STDSTRING level, T100STDSTRING type)
{
    if("on" == type){
        T100AssemblyLog::start();
    }else if("off" == type){
        T100AssemblyLog::stop();
    }else if("byte" == type){
        T100AssemblyLog::m_level = T100LOG_BYTE;
    }else if("char" == type){
        T100AssemblyLog::m_level = T100LOG_CHAR;
    }else if("string" == type){
        T100AssemblyLog::m_level = T100LOG_STRING;
    }else if("keyword" == type){
        T100AssemblyLog::m_level = T100LOG_KEYWORD;
    }else if("sentence" == type){
        T100AssemblyLog::m_level = T100LOG_SENTENCE;
    }else if("file" == type){
        T100AssemblyLog::m_level = T100LOG_FILE;
    }else if("all" == type){
        T100AssemblyLog::m_level = T100LOG_ALL;
    };

    if("on" == level){
        T100AssemblyLog::start();
    }else if("off" == level){
        T100AssemblyLog::stop();
    }else if("fatal" == level){
        T100AssemblyLog::m_type = T100LOG_TYPE_FATAL;
    }else if("error" == level){
        T100AssemblyLog::m_type = T100LOG_TYPE_ERROR;
    }else if("warn" == level){
        T100AssemblyLog::m_type = T100LOG_TYPE_WARN;
    }else if("debug" == level){
        T100AssemblyLog::m_type = T100LOG_TYPE_DEBUG;
    }else if("trace" == level){
        T100AssemblyLog::m_type = T100LOG_TYPE_TRACE;
    }else if("info" == level){
        T100AssemblyLog::m_type = T100LOG_TYPE_INFO;
    }else if("all" == level){
        T100AssemblyLog::m_type = T100LOG_TYPE_ALL;
    }else{
        return T100FALSE;
    }

    return T100TRUE;
}
