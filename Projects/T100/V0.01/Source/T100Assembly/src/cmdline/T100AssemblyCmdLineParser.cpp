#include "T100AssemblyCmdLineParser.h"

#include "T100CmdLineExec.h"
#include "T100CmdLineSwitch.h"
#include "T100CmdLineOption.h"
#include "T100CmdLineParam.h"
#include "T100AssemblyCmdLineParameterScanner.h"



T100AssemblyCmdLineParser::T100AssemblyCmdLineParser()
{
    //ctor
}

T100AssemblyCmdLineParser::~T100AssemblyCmdLineParser()
{
    //dtor
}

T100BOOL T100AssemblyCmdLineParser::classify(T100CmdLineInfo& info, T100CmdLineResult& data)
{
    T100BOOL            result          = T100TRUE;
    T100AssemblyCmdLineResult&          temp    = static_cast<T100AssemblyCmdLineResult&>(data);

    switch(info.type){
    case T100CMDLINE_EXEC:
        {
            T100CmdLineExec&    item    = static_cast<T100CmdLineExec&>(info);

            temp.exec = item.value;
        }
        break;
    case T100CMDLINE_SWITCH:
        {
            T100CmdLineSwitch&  item    = static_cast<T100CmdLineSwitch&>(info);

            result = setSwitch(item, temp);
        }
        break;
    case T100CMDLINE_OPTION:
        {
            T100CmdLineOption&  item    = static_cast<T100CmdLineOption&>(info);

            result = setOption(item, temp);
        }
        break;
    case T100CMDLINE_PARAM:
        {
            T100CmdLineParam&   item    = static_cast<T100CmdLineParam&>(info);

            result = setParam(item, temp);
        }
        break;
    }

    return result;
}

T100BOOL T100AssemblyCmdLineParser::setSwitch(T100CmdLineSwitch& info, T100AssemblyCmdLineResult& data)
{
    T100BOOL            result          = T100TRUE;

    switch(info.value){
    case L't':
        {
            data.TEST   = T100TRUE;
        }
        break;
    default:
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyCmdLineParser::setOption(T100CmdLineOption& info, T100AssemblyCmdLineResult& data)
{
    T100BOOL            result          = T100TRUE;

    switch(info.key){
    case L'u':
        {
            data.UNIT   = T100TRUE;
            data.NAME   = info.value;
        }
        break;
    default:
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyCmdLineParser::setParam(T100CmdLineParam& info, T100AssemblyCmdLineResult& data)
{
    T100BOOL            result          = T100TRUE;

    switch(m_index){
    case 0:
        {
            data.SOURCE = info.value;
            m_index++;
        }
        break;
    case 1:
        {
            data.TARGET = info.value;
            m_index++;
        }
        break;
    default:
        result = T100FALSE;
    }

    return result;
}
