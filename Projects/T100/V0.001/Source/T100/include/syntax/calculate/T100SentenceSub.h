#ifndef T100SENTENCESUB_H
#define T100SENTENCESUB_H

#include "T100Sentence.h"


class T100SentenceSub : public T100Sentence
{
    public:
        T100SentenceSub(T100SentenceScan*);
        virtual ~T100SentenceSub();

        T100OPERATOR            target;
        T100OPERATOR            source;

        T100BOOL                parse();
        T100BOOL                build(T100FileData*);

    protected:

    private:
};

#endif // T100SENTENCESUB_H
