#ifndef T100SENTENCEIN_H
#define T100SENTENCEIN_H

#include "T100Sentence.h"


class T100SentenceIn : public T100Sentence
{
    public:
        T100SentenceIn(T100SentenceScanner*);
        virtual ~T100SentenceIn();

        T100OPERATOR_COMPLEXUS      target;
        T100OPERATOR                source;

        T100BOOL                    parse();

        T100BOOL                    build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCEIN_H
