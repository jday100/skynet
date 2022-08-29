#ifndef T100SENTENCEDIV_H
#define T100SENTENCEDIV_H

#include "T100Sentence.h"


class T100SentenceDiv : public T100Sentence
{
    public:
        T100SentenceDiv(T100SentenceScanner*);
        virtual ~T100SentenceDiv();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo* info);

    protected:

    private:
};

#endif // T100SENTENCEDIV_H
