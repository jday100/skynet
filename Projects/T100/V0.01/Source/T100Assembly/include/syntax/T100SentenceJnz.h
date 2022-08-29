#ifndef T100SENTENCEJNZ_H
#define T100SENTENCEJNZ_H

#include "T100Sentence.h"


class T100SentenceJnz : public T100Sentence
{
    public:
        T100SentenceJnz(T100SentenceScanner*);
        virtual ~T100SentenceJnz();

        T100OPERATOR_COMPLEXUS      target;

        T100BOOL                    parse();

        T100BOOL                    build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCEJNZ_H
