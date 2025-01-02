#include "T100CLKeywordParser.h"

T100CLKeywordParser::T100CLKeywordParser()
    :T100KeywordParser()
{
    //ctor
}

T100CLKeywordParser::~T100CLKeywordParser()
{
    //dtor
}

T100VOID T100CLKeywordParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLStringParser*>(parser);
}

T100ParserBase* T100CLKeywordParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLKeywordParser::next()
{

}
