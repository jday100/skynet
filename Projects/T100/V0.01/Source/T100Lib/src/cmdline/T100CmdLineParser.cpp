#include "T100CmdLineParser.h"

#include "T100CmdLineExec.h"
#include "T100CmdLineSwitch.h"
#include "T100CmdLineOption.h"
#include "T100CmdLineParam.h"


T100CmdLineParser::T100CmdLineParser()
{
    //ctor
}

T100CmdLineParser::~T100CmdLineParser()
{
    //dtor
}

T100BOOL T100CmdLineParser::parse(int argc, wchar_t** argv, T100CmdLineResult& data)
{
    T100BOOL            result          = T100TRUE;
    T100CmdLineStringScanner            strscanner;
    T100CmdLineCharScanner              chscanner;

    strscanner.setSource(argc, argv);
    chscanner.setSource(&strscanner);

    result = parse(chscanner, data);

    return result;
}

T100BOOL T100CmdLineParser::parse(T100CmdLineCharScanner& scanner, T100CmdLineResult& data)
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    T100CmdLineCharToken        token;
    T100WCHAR                   first;

READ_NEXT:
    value = scanner.next(token);
    if(!value){
        if(token.eof){
            return T100TRUE;
        }else{
            return T100FALSE;
        }
    }

    switch(token.type){
    case T100CMDLINE_TOKEN_EXEC:
        {
            T100CmdLineExec     exec;

            exec.value = token.exec;
            value = classify(exec, data);
            if(!value){
                return T100FALSE;
            }

            goto READ_NEXT;
        }
        break;
    case T100CMDLINE_TOKEN_PROMPT:
        {
            value = scanner.next(token);
            if(!value){
                return T100FALSE;
            }

            switch(token.type){
            case T100CMDLINE_TOKEN_CHAR:
                {
                    first = token.value;

                    value = scanner.next(token);
                    if(!value){
                        return T100FALSE;
                    }

                    switch(token.type){
                    case T100CMDLINE_TOKEN_EQUAL:
                        {
                            //result = T100NEW T100CmdLineOption();

                        }
                        break;
                    case T100CMDLINE_TOKEN_CHAR:
                        {
                            //result = T100NEW T100CmdLineSwitch();

                            //result = T100NEW T100CmdLineSwitch();
                        }
                        break;
                    default:
                        return T100FALSE;
                    }
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100CMDLINE_TOKEN_END:
        {
            return T100FALSE;
        }
        break;
    case T100CMDLINE_TOKEN_EOF:
        {
            return T100TRUE;
        }
        break;
    case T100CMDLINE_TOKEN_CHAR:
        {
            T100CmdLineParam        param;

            param.value += token.value;

PARAM_READ_NEXT:
            value = scanner.next(token);
            if(!value){
                return T100FALSE;
            }

            switch(token.type){
            case T100CMDLINE_TOKEN_END:
                {
                    value = classify(param, data);
                    if(!value){
                        return T100FALSE;
                    }
                    goto READ_NEXT;
                }
                break;
            case T100CMDLINE_TOKEN_EOF:
                {
                    value = classify(param, data);
                    if(!value){
                        return T100FALSE;
                    }
                    return T100TRUE;
                }
                break;
            case T100CMDLINE_TOKEN_CHAR:
                {
                    param.value += token.value;
                    goto PARAM_READ_NEXT;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    default:
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100CmdLineParser::classify(T100CmdLineInfo& info, T100CmdLineResult& data)
{
    return T100FALSE;
}
