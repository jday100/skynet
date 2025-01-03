#include "T100CLSegmentParser.h"

T100CLSegmentParser::T100CLSegmentParser()
    :T100SegmentParser()
{
    //ctor
    create();
}

T100CLSegmentParser::~T100CLSegmentParser()
{
    //dtor
    destroy();
}

T100VOID T100CLSegmentParser::create()
{

}

T100VOID T100CLSegmentParser::destroy()
{

}

T100VOID T100CLSegmentParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLSentenceParser*>(parser);
}

T100ParserBase* T100CLSegmentParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLSegmentParser::isLoaded()
{

}

T100BOOL T100CLSegmentParser::read()
{
    return m_parser->next(*m_state, m_item);
}

T100BOOL T100CLSegmentParser::next(T100State& state, T100Token& token)
{
    m_parser->next(state, token);
}
