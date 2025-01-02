#ifndef T100CLSOURCEPARSER_H
#define T100CLSOURCEPARSER_H

#include "develop/compiler/parser/T100SourceParser.h"

class T100CLSourceParser : public T100SourceParser
{
    public:
        T100CLSourceParser();
        virtual ~T100CLSourceParser();

        virtual T100BOOL            next();

    protected:

    private:
};

#endif // T100CLSOURCEPARSER_H
