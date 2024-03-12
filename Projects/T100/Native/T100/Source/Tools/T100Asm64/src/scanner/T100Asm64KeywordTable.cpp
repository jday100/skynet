#include "T100Asm64KeywordTable.h"

T100Asm64KeywordTable::T100Asm64KeywordTable()
{
    //ctor
    create();
}

T100Asm64KeywordTable::~T100Asm64KeywordTable()
{
    //dtor
    destroy();
}

T100VOID T100Asm64KeywordTable::create()
{
    m_keywords[L"ADD"]          = T100KEYWORD_ADD;
}

T100VOID T100Asm64KeywordTable::destroy()
{

}

T100ASM64_TOKEN_TYPE T100Asm64KeywordTable::find(T100STRING key)
{

}
