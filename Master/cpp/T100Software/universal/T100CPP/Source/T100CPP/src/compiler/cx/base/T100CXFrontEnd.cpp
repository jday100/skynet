#include "T100CXFrontEnd.h"

#include "T100CXParser.h"

T100CXFrontEnd::T100CXFrontEnd() :
    T100FrontEnd()
{
    //ctor
    init();
}

T100CXFrontEnd::~T100CXFrontEnd()
{
    //dtor
    uninit();
}

T100VOID T100CXFrontEnd::init()
{
    m_parser        = T100NEW T100CXParser();
}

T100VOID T100CXFrontEnd::uninit()
{
    T100SAFE_DELETE(m_parser);
}
