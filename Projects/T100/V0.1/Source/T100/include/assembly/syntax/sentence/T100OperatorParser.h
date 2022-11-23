#ifndef T100OPERATORPARSER_H
#define T100OPERATORPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100OperatorParser : public T100ParserBase
{
    public:
        T100OperatorParser(T100SentenceBase*);
        virtual ~T100OperatorParser();

        T100BOOL                parse(T100OPERATOR& op);

    protected:

    private:

};

}

#endif // T100OPERATORPARSER_H
