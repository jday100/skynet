#include "T100CLSourceParser.h"

T100CLSourceParser::T100CLSourceParser()
    :T100SourceParser()
{
    //ctor
}

T100CLSourceParser::~T100CLSourceParser()
{
    //dtor
}

T100VOID T100CLSourceParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLSegmentParser*>(parser);
}

T100ParserBase* T100CLSourceParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLSourceParser::next()
{
    m_parser->next();
}
