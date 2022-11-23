#ifndef T100SENTENCEPUSH_H
#define T100SENTENCEPUSH_H

#include "T100SentenceBase.h"

namespace T100Assembly{

class T100SentencePush : public T100SentenceBase::T100SentenceBase
{
    public:
        T100SentencePush(T100SentenceScanner*);
        virtual ~T100SentencePush();

        static T100VOID         init();

        ::T100SentenceBase::T100OPERATOR      target;

        T100BOOL                parse();

        T100BOOL                build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEPUSH_H
