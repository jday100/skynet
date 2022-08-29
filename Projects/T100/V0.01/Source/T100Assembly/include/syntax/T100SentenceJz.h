#ifndef T100SENTENCEJZ_H
#define T100SENTENCEJZ_H

#include "T100Sentence.h"


class T100SentenceJz : public T100Sentence
{
    public:
        T100SentenceJz(T100SentenceScanner*);
        virtual ~T100SentenceJz();

        T100OPERATOR_COMPLEXUS      target;

        T100BOOL                    parse();

        T100BOOL                    build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCEJZ_H
