#ifndef T100SENTENCEPOP_H
#define T100SENTENCEPOP_H

#include "T100SentenceBase.h"

namespace T100Assembly{

class T100SentencePop : public T100SentenceBase::T100SentenceBase
{
    public:
        T100SentencePop(T100SentenceScanner*);
        virtual ~T100SentencePop();

        static T100VOID         init();

        ::T100SentenceBase::T100OPERATOR         target;

        T100BOOL                parse();

        T100BOOL                build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEPOP_H
