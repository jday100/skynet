#ifndef T100SENTENCENOP_H
#define T100SENTENCENOP_H

#include "T100Sentence.h"


class T100SentenceNop : public T100Sentence
{
    public:
        T100SentenceNop(T100SentenceScan*);
        virtual ~T100SentenceNop();

        T100BOOL            parse();
        T100BOOL            build(T100FileData*);

    protected:

    private:
};

#endif // T100SENTENCENOP_H
