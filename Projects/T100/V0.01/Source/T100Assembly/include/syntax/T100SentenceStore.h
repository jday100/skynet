#ifndef T100SENTENCESTORE_H
#define T100SENTENCESTORE_H

#include "T100Sentence.h"


class T100SentenceStore : public T100Sentence
{
    public:
        T100SentenceStore(T100SentenceScanner*);
        virtual ~T100SentenceStore();

    protected:

    private:
};

#endif // T100SENTENCESTORE_H
