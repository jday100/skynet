#include "T100CLSentenceParser.h"

T100CLSentenceParser::T100CLSentenceParser()
    :T100SentenceParser()
{
    //ctor
    create();
}

T100CLSentenceParser::~T100CLSentenceParser()
{
    //dtor
    destroy();
}

T100VOID T100CLSentenceParser::create()
{

}

T100VOID T100CLSentenceParser::destroy()
{

}

T100VOID T100CLSentenceParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLKeywordParser*>(parser);
}

T100ParserBase* T100CLSentenceParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLSentenceParser::isLoaded()
{

}

T100BOOL T100CLSentenceParser::read()
{
    return m_parser->next(*m_state, m_item);
}

T100BOOL T100CLSentenceParser::next(T100State& state, T100Token& token)
{

}
