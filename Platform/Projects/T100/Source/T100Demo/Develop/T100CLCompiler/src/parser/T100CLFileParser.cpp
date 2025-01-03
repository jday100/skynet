#include "T100CLFileParser.h"

#include "T100CLFileToken.h"

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
    return m_file.open(filename);
}

T100BOOL T100CLFileParser::close()
{
    return m_file.close();
}

T100BOOL T100CLFileParser::next(T100State& state, T100Token& token)
{
    T100BOOL            result      = T100FALSE;
    T100CLFileToken*    data        = T100NULL;

    data    = dynamic_cast<T100CLFileToken*>(&token);
    if(data){
        result  = m_file.read(data->value, data->length);
    }
    return result;
}
