#ifndef T100PARSER_H
#define T100PARSER_H

#include "T100Common.h"
#include "develop/compiler/data/T100ParserInfo.h"

class T100Parser
{
    public:
        T100Parser();
        virtual ~T100Parser();

        T100BOOL            parse(T100WString, T100ParserInfo&);

    protected:

    private:
};

#endif // T100PARSER_H
