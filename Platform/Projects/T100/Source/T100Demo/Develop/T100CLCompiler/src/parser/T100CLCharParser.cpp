#include "T100CLCharParser.h"

T100CLCharParser::T100CLCharParser()
    :T100CharParser()
{
    //ctor
}

T100CLCharParser::~T100CLCharParser()
{
    //dtor
}

T100VOID T100CLCharParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLByteParser*>(parser);
}

T100ParserBase* T100CLCharParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLCharParser::isLoaded()
{

}

T100BOOL T100CLCharParser::read()
{
    return m_parser->next(*m_state, m_item);
}

T100BOOL T100CLCharParser::next(T100State& state, T100Token& token)
{
    m_parser->next(state, token);
}
