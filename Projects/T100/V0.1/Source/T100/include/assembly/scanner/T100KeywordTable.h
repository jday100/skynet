#ifndef T100KEYWORDTABLE_H
#define T100KEYWORDTABLE_H

#include "T100AssemblyCommon.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"
#include "T100Token.h"

#define     T100KEYWORD_HASH            std::unordered_map<T100STRING, T100TOKEN_TYPE, T100Library::T100StringHash, T100Library::T100StringEqual>

namespace T100Assembly{

class T100KeywordTable
{
    public:
        T100KeywordTable();
        virtual ~T100KeywordTable();

        T100TOKEN_TYPE          find(T100STRING);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100KEYWORD_HASH        m_keywords;

};

}

#endif // T100KEYWORDTABLE_H
