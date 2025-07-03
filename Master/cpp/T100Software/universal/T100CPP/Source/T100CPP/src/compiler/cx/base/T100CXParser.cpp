#include "T100CXParser.h"

#include "compiler/cx/scanner/T100CXScannerTools.h"

T100CXParser::T100CXParser() :
    T100Parser()
{
    //ctor
    init();
}

T100CXParser::~T100CXParser()
{
    //dtor
    uninit();
}

T100VOID T100CXParser::init()
{
    m_state     = T100NEW T100LeafState();
    m_token     = T100NEW T100SourceToken();

    T100CXScannerTools::CreateScanner(m_sourceScanner, m_fileScanner);
}

T100VOID T100CXParser::uninit()
{
    T100SAFE_DELETE(m_sourceScanner);
    T100SAFE_DELETE(m_token);
    T100SAFE_DELETE(m_state);
}
