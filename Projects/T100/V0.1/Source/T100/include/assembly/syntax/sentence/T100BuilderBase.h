#ifndef T100BUILDERBASE_H
#define T100BUILDERBASE_H

#include "T100Common.h"

namespace T100SentenceBase{
class T100SentenceBase;

class T100BuilderBase
{
    public:
        T100BuilderBase(T100SentenceBase*);
        virtual ~T100BuilderBase();

        T100SentenceBase*       getParent();

    protected:

    private:
        T100SentenceBase*       m_parent            = T100NULL;

};

}

#endif // T100BUILDERBASE_H
