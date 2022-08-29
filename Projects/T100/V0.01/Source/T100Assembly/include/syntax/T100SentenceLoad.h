#ifndef T100SENTENCELOAD_H
#define T100SENTENCELOAD_H

#include "T100Sentence.h"


class T100SentenceLoad : public T100Sentence
{
    public:
        T100SentenceLoad(T100SentenceScanner*);
        virtual ~T100SentenceLoad();

    protected:

    private:
};

#endif // T100SENTENCELOAD_H
