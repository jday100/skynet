#ifndef T100EXPRESSIONPARSER_H
#define T100EXPRESSIONPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100ExpressionParser : public T100ParserBase
{
    public:
        T100ExpressionParser(T100SentenceBase*);
        virtual ~T100ExpressionParser();

        T100BOOL            parse(T100OPERATOR&);

    protected:

    private:
};

}

#endif // T100EXPRESSIONPARSER_H
