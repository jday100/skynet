#include "T100KeywordTable.h"

T100KeywordTable::T100KeywordTable()
{
    //ctor
    create();
}

T100KeywordTable::~T100KeywordTable()
{
    //dtor
    destroy();
}

T100VOID T100KeywordTable::create()
{
    m_keywords[T100String("ADD")]           = T100KEYWORD_ADD;
    m_keywords[T100String("SUB")]           = T100KEYWORD_SUB;
    m_keywords[T100String("MUL")]           = T100KEYWORD_MUL;
    m_keywords[T100String("DIV")]           = T100KEYWORD_DIV;

    m_keywords[T100String("AND")]           = T100KEYWORD_AND;
    m_keywords[T100String("OR")]            = T100KEYWORD_OR;
    m_keywords[T100String("NOT")]           = T100KEYWORD_NOT;
    m_keywords[T100String("XOR")]           = T100KEYWORD_XOR;

    m_keywords[T100String("LOCK")]          = T100KEYWORD_LOCK;
    m_keywords[T100String("UNLOCK")]        = T100KEYWORD_UNLOCK;
    m_keywords[T100String("NOP")]           = T100KEYWORD_NOP;
    m_keywords[T100String("HALT")]          = T100KEYWORD_HALT;
    m_keywords[T100String("CMT")]           = T100KEYWORD_CMT;
    m_keywords[T100String("DBG")]           = T100KEYWORD_DEBUG;

    m_keywords[T100String("CALL")]          = T100KEYWORD_CALL;
    m_keywords[T100String("RET")]           = T100KEYWORD_RETURN;
    m_keywords[T100String("INT")]           = T100KEYWORD_INT;
    m_keywords[T100String("IRET")]          = T100KEYWORD_IRET;

    m_keywords[T100String("JUMP")]          = T100KEYWORD_JUMP;
    m_keywords[T100String("JZ")]            = T100KEYWORD_JZ;
    m_keywords[T100String("JNZ")]           = T100KEYWORD_JNZ;
    m_keywords[T100String("LOOP")]          = T100KEYWORD_LOOP;

    m_keywords[T100String("IN")]            = T100KEYWORD_IN;
    m_keywords[T100String("OUT")]           = T100KEYWORD_OUT;
    m_keywords[T100String("MOVE")]          = T100KEYWORD_MOVE;

    m_keywords[T100String("INTEGER")]       = T100KEYWORD_INTEGER;
    m_keywords[T100String("FLOAT")]         = T100KEYWORD_FLOAT;
    m_keywords[T100String("STRING")]        = T100KEYWORD_STRING;

    m_keywords[T100String("MODE")]          = T100KEYWORD_MODE;
    m_keywords[T100String("REAL")]          = T100KEYWORD_REAL;
    m_keywords[T100String("NORMAL")]        = T100KEYWORD_NORMAL;
    m_keywords[T100String("TINY")]          = T100KEYWORD_TINY;
    m_keywords[T100String("SMALL")]         = T100KEYWORD_SMALL;
    m_keywords[T100String("BIG")]           = T100KEYWORD_BIG;
    m_keywords[T100String("DEFAULT")]       = T100KEYWORD_DEFAULT;
    m_keywords[T100String("VIRTUAL")]       = T100KEYWORD_VIRTUAL;
    m_keywords[T100String("SHARE")]         = T100KEYWORD_SHARE;
    m_keywords[T100String("LOCATION")]      = T100KEYWORD_LOCATION;
    m_keywords[T100String("LENGTH")]        = T100KEYWORD_LENGTH;

    m_keywords[T100String("IMPORT")]        = T100KEYWORD_IMPORT;
    m_keywords[T100String("CODE")]          = T100KEYWORD_CODE;
    m_keywords[T100String("DATA")]          = T100KEYWORD_DATA;
    m_keywords[T100String("PROC")]          = T100KEYWORD_PROCEDURE;
    m_keywords[T100String("END")]           = T100KEYWORD_END;

    m_keywords[T100String("COR")]           = T100KEYWORD_COR;
    m_keywords[T100String("CBR")]           = T100KEYWORD_CBR;
    m_keywords[T100String("CCR")]           = T100KEYWORD_CCR;

    m_keywords[T100String("AAR")]           = T100KEYWORD_AAR;
    m_keywords[T100String("ABR")]           = T100KEYWORD_ABR;
    m_keywords[T100String("ACR")]           = T100KEYWORD_ACR;
    m_keywords[T100String("ADR")]           = T100KEYWORD_ADR;

    m_keywords[T100String("ACF")]           = T100KEYWORD_ACF;
    m_keywords[T100String("AMF")]           = T100KEYWORD_AMF;
    m_keywords[T100String("AOF")]           = T100KEYWORD_AOF;

    m_keywords[T100String("!")]             = T100CHAR_EXCLAMATION;
    m_keywords[T100String("\"")]            = T100CHAR_DOUBLE_QUOTES;
    m_keywords[T100String("#")]             = T100CHAR_POUND;
    m_keywords[T100String("/")]             = T100CHAR_SLASH;
    m_keywords[T100String(":")]             = T100CHAR_COLON;
    m_keywords[T100String("@")]             = T100CHAR_EMAIL;
    m_keywords[T100String("[")]             = T100CHAR_OPEN_BRACKETS;
    m_keywords[T100String("]")]             = T100CHAR_CLOSED_BRACKETS;
    m_keywords[T100String("{")]             = T100CHAR_OPEN_BRACE;
    m_keywords[T100String("}")]             = T100CHAR_CLOSED_BRACE;

}

T100VOID T100KeywordTable::destroy()
{
    m_keywords.clear();
}

T100TOKEN_TYPE T100KeywordTable::find(T100String str)
{
    return m_keywords[str];
}
