#ifndef T100SENTENCEQUIT_H
#define T100SENTENCEQUIT_H

#include "T100SentenceBase.h"

namespace T100Assembly{

class T100SentenceQuit : public T100SentenceBase::T100SentenceBase
{
    public:
        T100SentenceQuit(T100SentenceScanner*);
        virtual ~T100SentenceQuit();

        static T100VOID         init();

        T100BOOL                parse();

        T100BOOL                build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEQUIT_H
