#ifndef T100PARSERBASE_H
#define T100PARSERBASE_H

#include "T100Common.h"

namespace T100SentenceBase{
class T100SentenceBase;

class T100ParserBase
{
    public:
        T100ParserBase(T100SentenceBase*);
        virtual ~T100ParserBase();

        T100SentenceBase*       getParent();

    protected:

    private:
        T100SentenceBase*       m_parent            = T100NULL;

};

}

#endif // T100PARSERBASE_H
