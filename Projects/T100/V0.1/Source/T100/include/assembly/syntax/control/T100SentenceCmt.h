#ifndef T100SENTENCECMT_H
#define T100SENTENCECMT_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceCmt : public T100Sentence
{
    public:
        T100SentenceCmt(T100SentenceScanner*);
        virtual ~T100SentenceCmt();

        static T100VOID     init();

        T100WORD            id;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:
        T100BOOL            parseValue();

    private:
};

}

#endif // T100SENTENCECMT_H
