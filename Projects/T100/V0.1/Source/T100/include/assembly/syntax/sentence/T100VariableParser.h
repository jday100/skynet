#ifndef T100VARIABLEPARSER_H
#define T100VARIABLEPARSER_H

#include "T100SentenceCommon.h"
#include "T100ParserBase.h"

namespace T100SentenceBase{

class T100VariableParser : public T100ParserBase
{
    public:
        T100VariableParser(T100SentenceBase*);
        virtual ~T100VariableParser();

        T100BOOL            parse(T100OPERATOR&);

    protected:

    private:
};

}

#endif // T100VARIABLEPARSER_H
