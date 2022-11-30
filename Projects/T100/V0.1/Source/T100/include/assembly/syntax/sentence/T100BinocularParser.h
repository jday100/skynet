#ifndef T100BINOCULARPARSER_H
#define T100BINOCULARPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100BinocularParser : public T100ParserBase
{
    public:
        T100BinocularParser(T100SentenceBase*);
        virtual ~T100BinocularParser();

        T100BOOL            parse(::T100SentenceBase::T100OPERATOR_BINOCULAR&);

    protected:

    private:
};

}

#endif // T100BINOCULARPARSER_H
