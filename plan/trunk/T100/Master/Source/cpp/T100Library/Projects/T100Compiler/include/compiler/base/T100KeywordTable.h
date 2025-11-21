#ifndef T100KEYWORDTABLE_H
#define T100KEYWORDTABLE_H

#include <unordered_map>
#include "base/T100Class.h"

namespace T100LIBRARY{

#define     T100COMPILER_KEYWORD_HASH           std::unordered_map<T100WSTRING, T100WSTRING>

class T100KeywordTable : public T100Class
{
    public:
        T100KeywordTable();
        virtual ~T100KeywordTable();

    protected:
        T100COMPILER_KEYWORD_HASH           m_keywords;

    private:
};

}

#endif // T100KEYWORDTABLE_H
