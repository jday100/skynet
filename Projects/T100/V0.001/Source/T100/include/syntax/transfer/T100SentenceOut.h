#ifndef T100SENTENCEOUT_H
#define T100SENTENCEOUT_H

#include "T100Sentence.h"


class T100SentenceOut : public T100Sentence
{
    public:
        T100SentenceOut(T100SentenceScan*);
        virtual ~T100SentenceOut();

        T100OPERATOR                target;
        T100OPERATOR_COMPLEXUS      source;

        T100BOOL                    parse();
        T100BOOL                    build(T100FileData*);

    protected:

    private:
};

#endif // T100SENTENCEOUT_H
