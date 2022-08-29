#include "T100CmdLineStringScanner.h"

#include "T100CmdLineCommon.h"
#include "T100Unicode.h"


T100CmdLineStringScanner::T100CmdLineStringScanner()
{
    //ctor
}

T100CmdLineStringScanner::~T100CmdLineStringScanner()
{
    //dtor
}

T100VOID T100CmdLineStringScanner::setSource(int argc, wchar_t** argv)
{
    m_index     = 0;
    m_argc      = argc;
    m_argv      = argv;
}

T100BOOL T100CmdLineStringScanner::next(T100Token& token)
{
    m_token = (T100CmdLineStringToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100CmdLineStringScanner::run()
{
    T100STDSTRING           result;

    if(m_index < m_argc){
        /*
        result = m_argv[m_index++];
        m_token->value  = T100Unicode::to_wstring(result);
        */
        m_token->value  = m_argv[m_index++];
        if(1 == m_index){
            m_token->type   = T100CMDLINE_TOKEN_EXEC;
        }else{
            m_token->type   = T100CMDLINE_TOKEN_STRING;
        }

        return T100TRUE;
    }else{
        m_token->eof    = T100TRUE;
        m_token->type   = T100CMDLINE_TOKEN_EOF;
    }
    return T100FALSE;
}
