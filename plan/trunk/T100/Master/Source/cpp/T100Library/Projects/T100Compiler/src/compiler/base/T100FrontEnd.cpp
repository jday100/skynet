#include "T100FrontEnd.h"

namespace T100LIBRARY{

T100FrontEnd::T100FrontEnd() :
    T100Class()
{
    //ctor
    init();
}

T100FrontEnd::~T100FrontEnd()
{
    //dtor
    uninit();
}

T100VOID T100FrontEnd::init()
{
    //m_parser    = T100NEW T100Parser();
}

T100VOID T100FrontEnd::uninit()
{
    //T100SAFE_DELETE(m_parser);
}

T100VOID T100FrontEnd::SetParser(T100Parser* parser)
{
    m_parser        = parser;
}

T100Parser* T100FrontEnd::GetParser()
{
    return m_parser;
}

T100BOOL T100FrontEnd::Parse(const T100WSTRING& file, T100FrontInfo& info)
{
    m_parser->Parse(file, info);
}

}
