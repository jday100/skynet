#ifndef T100ASM64KEYWORDTABLE_H
#define T100ASM64KEYWORDTABLE_H

#include <unordered_map>
#include "T100Asm64Common.h"

#define     T100ASM64_KEYWORD_HASH          std::unordered_map<T100STRING, T100ASM64_TOKEN_TYPE>


class T100Asm64KeywordTable
{
    public:
        T100Asm64KeywordTable();
        virtual ~T100Asm64KeywordTable();

        T100ASM64_TOKEN_TYPE            find(T100STRING);

    protected:
        T100VOID                        create();
        T100VOID                        destroy();

    private:
        T100ASM64_KEYWORD_HASH          m_keywords;
};

#endif // T100ASM64KEYWORDTABLE_H
