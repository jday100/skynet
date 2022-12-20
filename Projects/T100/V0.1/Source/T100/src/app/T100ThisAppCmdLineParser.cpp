#include "T100ThisAppCmdLineParser.h"

#include "T100CmdLineExec.h"
#include "T100CmdLineSwitch.h"
#include "T100CmdLineOption.h"
#include "T100CmdLineParam.h"


T100ThisAppCmdLineParser::T100ThisAppCmdLineParser()
    :T100Library::T100CmdLineParser()
{
    //ctor
}

T100ThisAppCmdLineParser::~T100ThisAppCmdLineParser()
{
    //dtor
}

T100BOOL T100ThisAppCmdLineParser::classify(T100Library::T100CmdLineInfo& info, T100Library::T100CmdLineResult& data)
{
    T100BOOL        result          = T100TRUE;
    T100ThisAppCmdLineResult&       value       = static_cast<T100ThisAppCmdLineResult&>(data);

    switch(info.type){
    case T100Library::T100CMDLINE_EXEC:
        {
            T100Library::T100CmdLineExec&       item        = static_cast<T100Library::T100CmdLineExec&>(info);

            value.exec = item.value;
        }
        break;
    case T100Library::T100CMDLINE_SWITCH:
        {
            T100Library::T100CmdLineSwitch&     item        = static_cast<T100Library::T100CmdLineSwitch&>(info);

            result = setSwitch(item, value);
        }
        break;
    case T100Library::T100CMDLINE_OPTION:
        {
            T100Library::T100CmdLineOption&     item        = static_cast<T100Library::T100CmdLineOption&>(info);

            result = setOption(item, value);
        }
        break;
    case T100Library::T100CMDLINE_PARAM:
        {
            T100Library::T100CmdLineParam&      item        = static_cast<T100Library::T100CmdLineParam&>(info);

            result = setParam(item, value);
        }
        break;
    }

    return result;
}

T100BOOL T100ThisAppCmdLineParser::setSwitch(T100Library::T100CmdLineSwitch& info, T100ThisAppCmdLineResult& data)
{
    T100BOOL        result          = T100TRUE;

    switch(info.value){
    case L'?':
        {
            data.HELP       = T100TRUE;
        }
        break;
    case L'T':
        {
            data.TEST       = T100TRUE;
        }
        break;
    case L'F':
        {
            data.FONT       = T100TRUE;
        }
        break;
    case L'D':
        {
            data.VDISK      = T100TRUE;
        }
        break;
    case L'A':
        {
            data.ASSEMBLY   = T100TRUE;
        }
        break;
    case L'V':
        {
            data.VPC        = T100TRUE;
        }
        break;
    case L'l':
        {
            data.LIST       = T100TRUE;
        }
        break;
    default:
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100ThisAppCmdLineParser::setOption(T100Library::T100CmdLineOption& info, T100ThisAppCmdLineResult& data)
{
    T100BOOL        result          = T100TRUE;

    switch(info.key){
    case L'u':
        {
            data.UNIT   = T100TRUE;
            data.NAME   = info.value;
        }
        break;
    case L'p':
        {
            data.PATHS.push_back(info.value);
        }
        break;
    default:
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100ThisAppCmdLineParser::setParam(T100Library::T100CmdLineParam& info, T100ThisAppCmdLineResult& data)
{
    T100BOOL        result          = T100TRUE;

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
