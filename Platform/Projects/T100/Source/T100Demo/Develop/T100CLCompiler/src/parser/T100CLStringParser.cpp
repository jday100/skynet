#include "T100CLStringParser.h"

T100CLStringParser::T100CLStringParser()
    :T100StringParser()
{
    //ctor
}

T100CLStringParser::~T100CLStringParser()
{
    //dtor
}

T100VOID T100CLStringParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLCharParser*>(parser);
}

T100ParserBase* T100CLStringParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLStringParser::next(T100State& state, T100Token& token)
{
    m_parser->next(state, token);
}
