#include "T100CLKeywordParser.h"

T100CLKeywordParser::T100CLKeywordParser()
    :T100KeywordParser()
{
    //ctor
    create();
}

T100CLKeywordParser::~T100CLKeywordParser()
{
    //dtor
    destroy();
}

T100VOID T100CLKeywordParser::create()
{

}

T100VOID T100CLKeywordParser::destroy()
{

}

T100VOID T100CLKeywordParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLStringParser*>(parser);
}

T100ParserBase* T100CLKeywordParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLKeywordParser::isLoaded()
{

}

T100BOOL T100CLKeywordParser::read()
{
    return m_parser->next(*m_state, m_item);
}

T100BOOL T100CLKeywordParser::next(T100State& state, T100Token& token)
{

}
