#ifndef T100SENTENCELGD_H
#define T100SENTENCELGD_H

#include "T100SentenceBase.h"

namespace T100Assembly{

class T100SentenceLgd : public T100SentenceBase::T100SentenceBase
{
    public:
        T100SentenceLgd(T100SentenceScanner*);
        virtual ~T100SentenceLgd();

        static T100VOID         init();

        ::T100SentenceBase::T100OPERATOR        target;

        T100BOOL                parse();

        T100BOOL                build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCELGD_H
