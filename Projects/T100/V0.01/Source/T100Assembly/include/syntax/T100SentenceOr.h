#ifndef T100SENTENCEOR_H
#define T100SENTENCEOR_H

#include "T100Sentence.h"


class T100SentenceOr : public T100Sentence
{
    public:
        T100SentenceOr(T100SentenceScanner*);
        virtual ~T100SentenceOr();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCEOR_H
