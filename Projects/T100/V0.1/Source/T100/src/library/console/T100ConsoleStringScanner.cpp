#include "T100ConsoleStringScanner.h"

namespace T100Library{

T100ConsoleStringScanner::T100ConsoleStringScanner()
    :T100Component::T100Scanner()
{
    //ctor
}

T100ConsoleStringScanner::~T100ConsoleStringScanner()
{
    //dtor
}

T100VOID T100ConsoleStringScanner::setSource(T100WSTRING line)
{
    m_line = line;
}

T100BOOL T100ConsoleStringScanner::next(T100Component::T100Token& token)
{
    m_token = (T100ConsoleStringToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100ConsoleStringScanner::run()
{

}

}
