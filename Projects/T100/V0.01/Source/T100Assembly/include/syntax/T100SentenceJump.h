#ifndef T100SENTENCEJUMP_H
#define T100SENTENCEJUMP_H

#include "T100Sentence.h"


class T100SentenceJump : public T100Sentence
{
    public:
        T100SentenceJump(T100SentenceScanner*);
        virtual ~T100SentenceJump();

        T100OPERATOR_COMPLEXUS      target;

        T100BOOL                    parse();

        T100BOOL                    build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCEJUMP_H
