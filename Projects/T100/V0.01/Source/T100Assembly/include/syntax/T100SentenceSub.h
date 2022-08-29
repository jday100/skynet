#ifndef T100SENTENCESUB_H
#define T100SENTENCESUB_H

#include "T100Sentence.h"


class T100SentenceSub : public T100Sentence
{
    public:
        T100SentenceSub(T100SentenceScanner*);
        virtual ~T100SentenceSub();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCESUB_H
