#ifndef T100COMPLEXUSPARSER_H
#define T100COMPLEXUSPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100ComplexusParser : public T100ParserBase
{
    public:
        T100ComplexusParser(T100SentenceBase*);
        virtual ~T100ComplexusParser();

        T100BOOL            parse(T100OPERATOR_COMPLEXUS&);

    protected:

    private:
};

}

#endif // T100COMPLEXUSPARSER_H
