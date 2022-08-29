#ifndef T100SENTENCEMOVE_H
#define T100SENTENCEMOVE_H

#include "T100Sentence.h"


class T100SentenceMove : public T100Sentence
{
    public:
        T100SentenceMove(T100SentenceScanner*);
        virtual ~T100SentenceMove();

        T100OPERATOR_BINOCULAR      ops;

        T100BOOL                    parse();

        T100BOOL                    build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCEMOVE_H
