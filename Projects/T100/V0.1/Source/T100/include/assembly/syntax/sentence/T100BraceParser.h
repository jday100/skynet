#ifndef T100BRACEPARSER_H
#define T100BRACEPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100BraceParser : public T100ParserBase
{
    public:
        T100BraceParser(T100SentenceBase*);
        virtual ~T100BraceParser();

        T100BOOL            parse(::T100SentenceBase::T100OPERATOR_COMPLEXUS&);

    protected:

    private:
};

}

#endif // T100BRACEPARSER_H
