#ifndef T100CXKEYWORDTABLE_H
#define T100CXKEYWORDTABLE_H

#include "compiler/base/T100KeywordTable.h"

using namespace T100LIBRARY;

class T100CXKeywordTable : public T100KeywordTable
{
    public:
        T100CXKeywordTable();
        virtual ~T100CXKeywordTable();

    protected:
        static T100COMPILER_KEYWORD_HASH        m_cxKeywords;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100CXKEYWORDTABLE_H
