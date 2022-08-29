#ifndef T100SENTENCECOPY_H
#define T100SENTENCECOPY_H

#include "T100Sentence.h"


class T100SentenceCopy : public T100Sentence
{
    public:
        T100SentenceCopy(T100SentenceScanner*);
        virtual ~T100SentenceCopy();

    protected:

    private:
};

#endif // T100SENTENCECOPY_H
