#ifndef T100SENTENCEIN_H
#define T100SENTENCEIN_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceIn : public T100Sentence
{
    public:
        T100SentenceIn(T100SentenceScanner*);
        virtual ~T100SentenceIn();

        static T100VOID                 init();

        T100Component::T100OPERATOR_COMPLEXUS          target;
        T100Component::T100OPERATOR                    source;

        T100BOOL                        parse();

        T100BOOL                        build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEIN_H
