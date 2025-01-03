#include "T100CLSourceParser.h"

T100CLSourceParser::T100CLSourceParser()
    :T100SourceParser()
{
    //ctor
    create();
}

T100CLSourceParser::~T100CLSourceParser()
{
    //dtor
    destroy();
}

T100VOID T100CLSourceParser::create()
{

}

T100VOID T100CLSourceParser::destroy()
{

}

T100BOOL T100CLSourceParser::isLoaded()
{

}

T100BOOL T100CLSourceParser::read()
{
    return m_parser->next(*m_state, m_item);
}

T100VOID T100CLSourceParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLSegmentParser*>(parser);
}

T100ParserBase* T100CLSourceParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLSourceParser::next(T100State& state, T100Token& token)
{
    m_parser->next(state, token);
}
