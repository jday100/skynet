#ifndef T100SENTENCEJZ_H
#define T100SENTENCEJZ_H

#include "T100Sentence.h"


class T100SentenceJz : public T100Sentence
{
    public:
        T100SentenceJz(T100SentenceScan*);
        virtual ~T100SentenceJz();

        T100OPERATOR_COMPLEXUS      target;

        T100BOOL                    parse();
        T100BOOL                    build(T100FileData*);

    protected:

    private:
};

#endif // T100SENTENCEJZ_H
