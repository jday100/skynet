#ifndef T100BRACKETSPARSER_H
#define T100BRACKETSPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100BracketsParser : public T100ParserBase
{
    public:
        T100BracketsParser(T100SentenceBase*);
        virtual ~T100BracketsParser();

        T100BOOL            parse(T100OPERATOR&);

    protected:

    private:
};

}

#endif // T100BRACKETSPARSER_H
