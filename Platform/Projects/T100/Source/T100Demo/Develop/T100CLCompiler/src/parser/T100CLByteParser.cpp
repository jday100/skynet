#include "T100CLByteParser.h"

T100CLByteParser::T100CLByteParser()
    :T100ParserBase()
{
    //ctor
}

T100CLByteParser::~T100CLByteParser()
{
    //dtor
}

T100VOID T100CLByteParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLFileParser*>(parser);
}

T100ParserBase* T100CLByteParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLByteParser::next()
{
    m_parser->next();
}
