#ifndef T100SENTENCENOT_H
#define T100SENTENCENOT_H

#include "T100Sentence.h"


class T100SentenceNot : public T100Sentence
{
    public:
        T100SentenceNot(T100SentenceScanner*);
        virtual ~T100SentenceNot();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCENOT_H
