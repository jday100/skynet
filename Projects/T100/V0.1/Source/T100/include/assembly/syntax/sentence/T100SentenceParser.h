#ifndef T100SENTENCEPARSER_H
#define T100SENTENCEPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100SentenceParser : public T100ParserBase
{
    public:
        T100SentenceParser(T100SentenceBase*);
        virtual ~T100SentenceParser();

    protected:

    private:
};

}

#endif // T100SENTENCEPARSER_H
