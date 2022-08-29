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
    m_keywords[T100String(L"ADD")]          = T100KEYWORD_ADD;
    m_keywords[T100String(L"SUB")]          = T100KEYWORD_SUB;
    m_keywords[T100String(L"MUL")]          = T100KEYWORD_MUL;
    m_keywords[T100String(L"DIV")]          = T100KEYWORD_DIV;

    m_keywords[T100String(L"AND")]          = T100KEYWORD_AND;
    m_keywords[T100String(L"OR")]           = T100KEYWORD_OR;
    m_keywords[T100String(L"NOT")]          = T100KEYWORD_NOT;
    m_keywords[T100String(L"XOR")]          = T100KEYWORD_XOR;

    m_keywords[T100String(L"LOCK")]         = T100KEYWORD_LOCK;
    m_keywords[T100String(L"UNLOCK")]       = T100KEYWORD_UNLOCK;
    m_keywords[T100String(L"NOP")]          = T100KEYWORD_NOP;
    m_keywords[T100String(L"HALT")]         = T100KEYWORD_HALT;
    m_keywords[T100String(L"CMT")]          = T100KEYWORD_CMT;
    m_keywords[T100String(L"DBG")]          = T100KEYWORD_DEBUG;

    m_keywords[T100String(L"CALL")]         = T100KEYWORD_CALL;
    m_keywords[T100String(L"RET")]          = T100KEYWORD_RETURN;
    m_keywords[T100String(L"INT")]          = T100KEYWORD_INT;
    m_keywords[T100String(L"IRET")]         = T100KEYWORD_IRET;

    m_keywords[T100String(L"JUMP")]         = T100KEYWORD_JUMP;
    m_keywords[T100String(L"JZ")]           = T100KEYWORD_JZ;
    m_keywords[T100String(L"JNZ")]          = T100KEYWORD_JNZ;
    m_keywords[T100String(L"LOOP")]         = T100KEYWORD_LOOP;

    m_keywords[T100String(L"IN")]           = T100KEYWORD_IN;
    m_keywords[T100String(L"OUT")]          = T100KEYWORD_OUT;
    m_keywords[T100String(L"MOVE")]         = T100KEYWORD_MOVE;

    m_keywords[T100String(L"INTEGER")]      = T100KEYWORD_INTEGER;
    m_keywords[T100String(L"FLOAT")]        = T100KEYWORD_FLOAT;
    m_keywords[T100String(L"STRING")]       = T100KEYWORD_STRING;

    m_keywords[T100String(L"MODE")]         = T100KEYWORD_MODE;
    m_keywords[T100String(L"REAL")]         = T100KEYWORD_REAL;
    m_keywords[T100String(L"TINY")]         = T100KEYWORD_TINY;
    m_keywords[T100String(L"VIRTUAL")]      = T100KEYWORD_VIRTUAL;
    m_keywords[T100String(L"LOCATION")]     = T100KEYWORD_LOCATION;
    m_keywords[T100String(L"LENGTH")]       = T100KEYWORD_LENGTH;
    m_keywords[T100String(L"DEFAULT")]      = T100KEYWORD_DEFAULT;

    m_keywords[T100String(L"IMPORT")]       = T100KEYWORD_IMPORT;
    m_keywords[T100String(L"CODE")]         = T100KEYWORD_CODE;
    m_keywords[T100String(L"DATA")]         = T100KEYWORD_DATA;
    m_keywords[T100String(L"PROC")]         = T100KEYWORD_PROCEDURE;
    m_keywords[T100String(L"END")]          = T100KEYWORD_END;

    m_keywords[T100String(L"COR")]          = T100KEYWORD_COR;
    m_keywords[T100String(L"CBR")]          = T100KEYWORD_CBR;
    m_keywords[T100String(L"CCR")]          = T100KEYWORD_CCR;

    m_keywords[T100String(L"AAR")]          = T100KEYWORD_AAR;
    m_keywords[T100String(L"ABR")]          = T100KEYWORD_ABR;
    m_keywords[T100String(L"ACR")]          = T100KEYWORD_ACR;
    m_keywords[T100String(L"ADR")]          = T100KEYWORD_ADR;

    m_keywords[T100String(L"ACF")]          = T100KEYWORD_ACF;
    m_keywords[T100String(L"AMF")]          = T100KEYWORD_AMF;
    m_keywords[T100String(L"AOF")]          = T100KEYWORD_AOF;

    m_keywords[T100String(L"!")]            = T100CHAR_EXCLAMATION;
    m_keywords[T100String(L"\"")]           = T100CHAR_DOUBLE_QUOTES;
    m_keywords[T100String(L"#")]            = T100CHAR_POUND;
    m_keywords[T100String(L"/")]            = T100CHAR_SLASH;
    m_keywords[T100String(L":")]            = T100CHAR_COLON;
    m_keywords[T100String(L"@")]            = T100CHAR_EMAIL;
    m_keywords[T100String(L"[")]            = T100CHAR_OPEN_BRACKETS;
    m_keywords[T100String(L"]")]            = T100CHAR_CLOSED_BRACKETS;
    m_keywords[T100String(L"{")]            = T100CHAR_OPEN_BRACE;
    m_keywords[T100String(L"}")]            = T100CHAR_CLOSED_BRACE;

}

T100VOID T100KeywordTable::destroy()
{
    m_keywords.clear();
}

T100TOKEN_TYPE T100KeywordTable::find(T100String str)
{
    return m_keywords[str];
}
