#include "T100KeywordTable.h"

namespace T100Assembly{

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
    m_keywords[T100STRING(L"ADD")]          = T100KEYWORD_ADD;
    m_keywords[T100STRING(L"SUB")]          = T100KEYWORD_SUB;
    m_keywords[T100STRING(L"MUL")]          = T100KEYWORD_MUL;
    m_keywords[T100STRING(L"DIV")]          = T100KEYWORD_DIV;

    m_keywords[T100STRING(L"AND")]          = T100KEYWORD_AND;
    m_keywords[T100STRING(L"OR")]           = T100KEYWORD_OR;
    m_keywords[T100STRING(L"NOT")]          = T100KEYWORD_NOT;
    m_keywords[T100STRING(L"XOR")]          = T100KEYWORD_XOR;

    m_keywords[T100STRING(L"LOCK")]         = T100KEYWORD_LOCK;
    m_keywords[T100STRING(L"UNLOCK")]       = T100KEYWORD_UNLOCK;
    m_keywords[T100STRING(L"NOP")]          = T100KEYWORD_NOP;
    m_keywords[T100STRING(L"HALT")]         = T100KEYWORD_HALT;
    m_keywords[T100STRING(L"CMT")]          = T100KEYWORD_CMT;
    m_keywords[T100STRING(L"DBG")]          = T100KEYWORD_DEBUG;

    m_keywords[T100STRING(L"LGD")]          = T100KEYWORD_LGD;
    m_keywords[T100STRING(L"ENTER")]        = T100KEYWORD_ENTER;
    m_keywords[T100STRING(L"QUIT")]         = T100KEYWORD_QUIT;

    m_keywords[T100STRING(L"CALL")]         = T100KEYWORD_CALL;
    m_keywords[T100STRING(L"RET")]          = T100KEYWORD_RETURN;
    m_keywords[T100STRING(L"INT")]          = T100KEYWORD_INT;
    m_keywords[T100STRING(L"IRET")]         = T100KEYWORD_IRET;

    m_keywords[T100STRING(L"JUMP")]         = T100KEYWORD_JUMP;
    m_keywords[T100STRING(L"JZ")]           = T100KEYWORD_JZ;
    m_keywords[T100STRING(L"JNZ")]          = T100KEYWORD_JNZ;
    m_keywords[T100STRING(L"LOOP")]         = T100KEYWORD_LOOP;

    m_keywords[T100STRING(L"PUSH")]         = T100KEYWORD_PUSH;
    m_keywords[T100STRING(L"POP")]          = T100KEYWORD_POP;
    m_keywords[T100STRING(L"ALL")]          = T100KEYWORD_ALL;

    m_keywords[T100STRING(L"IN")]           = T100KEYWORD_IN;
    m_keywords[T100STRING(L"OUT")]          = T100KEYWORD_OUT;
    m_keywords[T100STRING(L"MOVE")]         = T100KEYWORD_MOVE;

    m_keywords[T100STRING(L"INTEGER")]      = T100KEYWORD_INTEGER;
    m_keywords[T100STRING(L"FLOAT")]        = T100KEYWORD_FLOAT;
    m_keywords[T100STRING(L"STRING")]       = T100KEYWORD_STRING;

    m_keywords[T100STRING(L"MODE")]         = T100KEYWORD_MODE;
    m_keywords[T100STRING(L"REAL")]         = T100KEYWORD_REAL;
    m_keywords[T100STRING(L"NORMAL")]       = T100KEYWORD_NORMAL;
    m_keywords[T100STRING(L"VIRTUAL")]      = T100KEYWORD_VIRTUAL;
    m_keywords[T100STRING(L"SHARE")]        = T100KEYWORD_SHARE;
    m_keywords[T100STRING(L"LOCATION")]     = T100KEYWORD_LOCATION;
    m_keywords[T100STRING(L"LENGTH")]       = T100KEYWORD_LENGTH;
    m_keywords[T100STRING(L"DEFAULT")]      = T100KEYWORD_DEFAULT;

    m_keywords[T100STRING(L"IMPORT")]       = T100KEYWORD_IMPORT;
    m_keywords[T100STRING(L"CODE")]         = T100KEYWORD_CODE;
    m_keywords[T100STRING(L"DATA")]         = T100KEYWORD_DATA;
    m_keywords[T100STRING(L"PROC")]         = T100KEYWORD_PROCEDURE;
    m_keywords[T100STRING(L"END")]          = T100KEYWORD_END;

    m_keywords[T100STRING(L"COR")]          = T100KEYWORD_COR;
    m_keywords[T100STRING(L"CBR")]          = T100KEYWORD_CBR;
    m_keywords[T100STRING(L"CCR")]          = T100KEYWORD_CCR;

    m_keywords[T100STRING(L"SSR")]          = T100KEYWORD_SSR;
    m_keywords[T100STRING(L"SPR")]          = T100KEYWORD_SPR;

    m_keywords[T100STRING(L"AAR")]          = T100KEYWORD_AAR;
    m_keywords[T100STRING(L"ABR")]          = T100KEYWORD_ABR;
    m_keywords[T100STRING(L"ACR")]          = T100KEYWORD_ACR;
    m_keywords[T100STRING(L"ADR")]          = T100KEYWORD_ADR;

    m_keywords[T100STRING(L"ACF")]          = T100KEYWORD_ACF;
    m_keywords[T100STRING(L"AMF")]          = T100KEYWORD_AMF;
    m_keywords[T100STRING(L"AOF")]          = T100KEYWORD_AOF;

    m_keywords[T100STRING(L"!")]            = T100CHAR_EXCLAMATION;
    m_keywords[T100STRING(L"\"")]           = T100CHAR_DOUBLE_QUOTES;
    m_keywords[T100STRING(L"#")]            = T100CHAR_POUND;
    m_keywords[T100STRING(L"/")]            = T100CHAR_SLASH;
    m_keywords[T100STRING(L":")]            = T100CHAR_COLON;
    m_keywords[T100STRING(L"@")]            = T100CHAR_EMAIL;
    m_keywords[T100STRING(L"[")]            = T100CHAR_OPEN_BRACKETS;
    m_keywords[T100STRING(L"]")]            = T100CHAR_CLOSED_BRACKETS;
    m_keywords[T100STRING(L"{")]            = T100CHAR_OPEN_BRACE;
    m_keywords[T100STRING(L"}")]            = T100CHAR_CLOSED_BRACE;
}

T100VOID T100KeywordTable::destroy()
{
    m_keywords.clear();
}

T100TOKEN_TYPE T100KeywordTable::find(T100STRING str)
{
    return m_keywords[str];
}

}
