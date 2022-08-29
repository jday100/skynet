#ifndef T100SENTENCEMUL_H
#define T100SENTENCEMUL_H

#include "T100Sentence.h"


class T100SentenceMul : public T100Sentence
{
    public:
        T100SentenceMul(T100SentenceScanner*);
        virtual ~T100SentenceMul();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCEMUL_H
