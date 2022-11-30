#ifndef T100SENTENCEENTER_H
#define T100SENTENCEENTER_H

#include "T100SentenceBase.h"

namespace T100Assembly{

class T100SentenceEnter : public T100SentenceBase::T100SentenceBase
{
    public:
        T100SentenceEnter(T100SentenceScanner*);
        virtual ~T100SentenceEnter();

        static T100VOID         init();

        T100BOOL                parse();

        T100BOOL                build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEENTER_H
