#ifndef T100KEYWORDTOKEN_H
#define T100KEYWORDTOKEN_H

#include "compiler/base/T100LeafToken.h"

namespace T100LIBRARY{

class T100KeywordToken : public T100LeafToken
{
    public:
        T100KeywordToken();
        virtual ~T100KeywordToken();

    protected:

    private:
};

}

#endif // T100KEYWORDTOKEN_H
