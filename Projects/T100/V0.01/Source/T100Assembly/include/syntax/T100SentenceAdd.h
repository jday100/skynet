#ifndef T100SENTENCEADD_H
#define T100SENTENCEADD_H

#include "T100Sentence.h"

/*
ADD
ADD     WORD
ADD     DWORD
*/


class T100SentenceAdd : public T100Sentence
{
    public:
        T100SentenceAdd(T100SentenceScanner*);
        virtual ~T100SentenceAdd();

        T100OPERATOR            target;
        T100OPERATOR            source;

        T100BOOL                parse();
        T100BOOL                build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCEADD_H
