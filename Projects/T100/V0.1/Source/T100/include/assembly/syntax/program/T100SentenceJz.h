#ifndef T100SENTENCEJZ_H
#define T100SENTENCEJZ_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceJz : public T100Sentence
{
    public:
        T100SentenceJz(T100SentenceScanner*);
        virtual ~T100SentenceJz();

        static T100VOID                 init();

        T100Component::T100OPERATOR_COMPLEXUS          target;

        T100BOOL                        parse();

        T100BOOL                        build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEJZ_H
