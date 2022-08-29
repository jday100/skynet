#ifndef T100SENTENCEPROCEDURE_H
#define T100SENTENCEPROCEDURE_H

#include "T100Sentence.h"


class T100SentenceProcedure : public T100Sentence
{
    public:
        T100SentenceProcedure(T100SentenceScanner*);
        virtual ~T100SentenceProcedure();

        T100String              name;

        T100BOOL                parse();

        T100BOOL                build(T100BuildInfo*);

    protected:
        T100BOOL                parseConfig();

    private:
};

#endif // T100SENTENCEPROCEDURE_H
