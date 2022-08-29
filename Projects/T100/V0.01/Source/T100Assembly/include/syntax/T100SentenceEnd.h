#ifndef T100SENTENCEEND_H
#define T100SENTENCEEND_H

#include "T100Sentence.h"


class T100SentenceEnd : public T100Sentence
{
    public:
        T100SentenceEnd(T100SentenceScanner*);
        virtual ~T100SentenceEnd();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCEEND_H
