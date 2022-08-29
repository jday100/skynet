#ifndef T100SENTENCECALL_H
#define T100SENTENCECALL_H

#include "T100Sentence.h"


class T100SentenceCall : public T100Sentence
{
    public:
        T100SentenceCall(T100SentenceScan*);
        virtual ~T100SentenceCall();

        T100String              name;

        T100BOOL                parse();
        T100BOOL                build(T100FileData*);

    protected:
        T100BOOL                parseProcedure();

    private:
};

#endif // T100SENTENCECALL_H
