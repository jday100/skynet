#ifndef T100SENTENCELOOP_H
#define T100SENTENCELOOP_H

#include "T100Sentence.h"


class T100SentenceLoop : public T100Sentence
{
    public:
        T100SentenceLoop(T100SentenceScan*);
        virtual ~T100SentenceLoop();

        T100OPERATOR        target;

        T100BOOL            parse();
        T100BOOL            build(T100FileData*);

    protected:

    private:
};

#endif // T100SENTENCELOOP_H
