#include "T100CLByteParser.h"

#include "T100CLFileToken.h"

T100CLByteParser::T100CLByteParser()
    :T100ParserBase()
{
    //ctor
}

T100CLByteParser::~T100CLByteParser()
{
    //dtor
}

T100VOID T100CLByteParser::setSource(T100ParserBase* parser)
{
    m_parser    = dynamic_cast<T100CLFileParser*>(parser);
}

T100ParserBase* T100CLByteParser::getSource()
{
    return m_parser;
}

T100BOOL T100CLByteParser::isLoaded()
{

}

T100BOOL T100CLByteParser::read()
{
    return m_parser->next(*m_state, m_item);
}

T100BOOL T100CLByteParser::next(T100State& state, T100Token& token)
{
    T100BOOL        result;

    m_state     = &state;
    m_token     = dynamic_cast<T100CLByteToken*>(&token);

    if(m_token){
        if(!isLoaded()){
            result  = read();
        }else{
            result  = T100TRUE;
        }

        if(result){
            m_token->value  = m_item.value[m_current++];
            return T100TRUE;
        }
    }

}
