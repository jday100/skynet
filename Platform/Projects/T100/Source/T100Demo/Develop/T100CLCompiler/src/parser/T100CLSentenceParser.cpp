#include "T100CLSentenceParser.h"

T100CLSentenceParser::T100CLSentenceParser()
    :T100SentenceParser()
{
    //ctor
}

T100CLSentenceParser::~T100CLSentenceParser()
{
    //dtor
}

T100VOID T100CLSentenceParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLKeywordParser*>(parser);
}

T100ParserBase* T100CLSentenceParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLSentenceParser::next(T100State& state, T100Token& token)
{
    m_parser->next(state, token);
}
