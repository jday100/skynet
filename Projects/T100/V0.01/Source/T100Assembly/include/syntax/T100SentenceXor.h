#ifndef T100SENTENCEXOR_H
#define T100SENTENCEXOR_H

#include "T100Sentence.h"


class T100SentenceXor : public T100Sentence
{
    public:
        T100SentenceXor(T100SentenceScanner*);
        virtual ~T100SentenceXor();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo* info);

    protected:

    private:
};

#endif // T100SENTENCEXOR_H
