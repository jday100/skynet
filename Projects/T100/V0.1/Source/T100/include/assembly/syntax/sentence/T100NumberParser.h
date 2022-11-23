#ifndef T100NUMBERPARSER_H
#define T100NUMBERPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100NumberParser : public T100ParserBase
{
    public:
        T100NumberParser(T100SentenceBase*);
        virtual ~T100NumberParser();

    protected:

    private:
};

}

#endif // T100NUMBERPARSER_H
