#ifndef T100REGISTERPARSER_H
#define T100REGISTERPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100RegisterParser : public T100ParserBase
{
    public:
        T100RegisterParser(T100SentenceBase*);
        virtual ~T100RegisterParser();

        T100BOOL            parse(T100OPERATOR&);

        T100BOOL            parseAll(T100OPERATOR&);

    protected:

    private:
};

}

#endif // T100REGISTERPARSER_H
