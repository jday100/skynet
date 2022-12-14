#ifndef T100SENTENCEJNZ_H
#define T100SENTENCEJNZ_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceJnz : public T100Sentence
{
    public:
        T100SentenceJnz(T100SentenceScanner*);
        virtual ~T100SentenceJnz();

        static T100VOID                 init();

        T100Component::T100OPERATOR_COMPLEXUS          target;

        T100BOOL                        parse();

        T100BOOL                        build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEJNZ_H
