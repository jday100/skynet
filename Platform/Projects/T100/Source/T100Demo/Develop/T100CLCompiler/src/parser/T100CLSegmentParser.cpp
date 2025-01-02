#include "T100CLSegmentParser.h"

T100CLSegmentParser::T100CLSegmentParser()
    :T100SegmentParser()
{
    //ctor
}

T100CLSegmentParser::~T100CLSegmentParser()
{
    //dtor
}

T100VOID T100CLSegmentParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLSentenceParser*>(parser);
}

T100ParserBase* T100CLSegmentParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLSegmentParser::next()
{
    m_parser->next();
}
