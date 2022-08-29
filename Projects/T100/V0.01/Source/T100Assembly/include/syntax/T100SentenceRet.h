#ifndef T100SENTENCERET_H
#define T100SENTENCERET_H

#include "T100Sentence.h"


class T100SentenceRet : public T100Sentence
{
    public:
        T100SentenceRet(T100SentenceScanner*);
        virtual ~T100SentenceRet();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCERET_H
