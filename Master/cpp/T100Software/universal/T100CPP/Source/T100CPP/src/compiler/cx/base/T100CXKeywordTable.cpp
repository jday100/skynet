#include "T100CXKeywordTable.h"

T100COMPILER_KEYWORD_HASH       T100CXKeywordTable::m_cxKeywords    = {
    {
        L"int",         L"int"
    },
    {
        L"main",        L"main"
    },
    {
        L"return",      L"return"
    },
    {
        L"include",     L"include"
    }
};

T100CXKeywordTable::T100CXKeywordTable() :
    T100KeywordTable()
{
    //ctor
    init();
}

T100CXKeywordTable::~T100CXKeywordTable()
{
    //dtor
    uninit();
}

T100VOID T100CXKeywordTable::init()
{
    m_keywords      = m_cxKeywords;
}

T100VOID T100CXKeywordTable::uninit()
{

}
