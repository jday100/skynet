#include "T100CLFileParser.h"

T100CLFileParser::T100CLFileParser()
    :T100ParserBase()
{
    //ctor
}

T100CLFileParser::~T100CLFileParser()
{
    //dtor
}

T100VOID T100CLFileParser::setSource(T100ParserBase* parser)
{

}

T100ParserBase* T100CLFileParser::getSource()
{
    m_parser;
}

T100BOOL T100CLFileParser::open(T100WString filename)
{
    m_file.open(filename);
}

T100BOOL T100CLFileParser::close()
{
    m_file.close();
}

T100BOOL T100CLFileParser::next(T100State& state, T100Token& token)
{
    T100WChar*      data;
    T100WORD        length;

    m_file.read(data, length);
}
