#ifndef T100KEYWORDTABLE_H
#define T100KEYWORDTABLE_H

#include "T100StringHash.h"
#include "T100StringEqual.h"
#include "T100String.h"
#include "T100TokenTypes.h"


#define     T100KEYWORD_HASH    std::unordered_map<T100String, T100TOKEN_TYPE, T100StringHash, T100StringEqual>


class T100KeywordTable
{
    public:
        T100KeywordTable();
        virtual ~T100KeywordTable();

        T100TOKEN_TYPE          find(T100String);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100KEYWORD_HASH        m_keywords;

};

#endif // T100KEYWORDTABLE_H
