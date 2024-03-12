#include "T100Asm64StringScanner.h"

#include "T100Log.h"
#include "T100Asm64Common.h"

T100Asm64StringScanner::T100Asm64StringScanner()
{
    //ctor
}

T100Asm64StringScanner::~T100Asm64StringScanner()
{
    //dtor
}

T100VOID T100Asm64StringScanner::setSource(T100Scanner* scanner)
{
    m_scanner   = dynamic_cast<T100Asm64LetterScanner*>(scanner);
}

T100Scanner* T100Asm64StringScanner::getSource()
{
    return m_scanner;
}

T100BOOL T100Asm64StringScanner::next(T100Token& token)
{
    while(m_scanner->next(m_item)){
        T100STRING      value;

        value   = m_item.value;
        T100Log::log(value);

        classify();
    }
}

T100BOOL T100Asm64StringScanner::read()
{
    T100BOOL        result          = T100FALSE;

    result = m_scanner->next(m_item);

    if(result){
        setLoaded(T100TRUE);
    }

    return result;
}

T100BOOL T100Asm64StringScanner::append()
{
    T100WCHAR       ch;

    ch  = m_item.value;
    m_token->value += ch;

    return T100TRUE;
}

T100VOID T100Asm64StringScanner::clear()
{

}

T100BOOL T100Asm64StringScanner::classify()
{
    if(T100TOKEN_NONE == m_type){
        m_token->type   = m_item.type;
        m_type          = m_item.type;
        append();
        setLoaded(T100FALSE);
        return T100FALSE;
    }else if(m_type == m_item.type){
        if(isOperator()){
            return T100TRUE;
        }else{
            append();
            setLoaded(T100FALSE);
            return T100FALSE;
        }
    }
    return T100TRUE;
}

T100BOOL T100Asm64StringScanner::isOperator()
{
    T100BOOL        result          = T100FALSE;

    switch(m_item.type){
    case T100CHAR_DOUBLE_QUOTES:
    case T100CHAR_POUND:
    case T100CHAR_DOLLAR:
    case T100CHAR_PERCENT:
    case T100CHAR_AND:
    case T100CHAR_OPEN_PARENS:
    case T100CHAR_CLOSED_PARENS:
    case T100CHAR_ASTERISK:
    case T100CHAR_PLUS:
    case T100CHAR_MINUS:
    case T100CHAR_DOT:
    case T100CHAR_SLASH:
    case T100CHAR_COLON:
    case T100CHAR_EMAIL:
    case T100CHAR_OPEN_BRACKETS:
    case T100CHAR_CLOSED_BRACKETS:
    case T100CHAR_UNDERLINE:
        {
            result = T100TRUE;
        }
        break;
    case T100TOKEN_EOF:
        {
            result = T100TRUE;
        }
        break;
    };

    return result;
}
