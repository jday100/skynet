#ifndef T100CLSTRINGPARSER_H
#define T100CLSTRINGPARSER_H

#include "develop/compiler/parser/T100StringParser.h"
#include "T100CLCharParser.h"

class T100CLStringParser : public T100StringParser
{
    public:
        T100CLStringParser();
        virtual ~T100CLStringParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next();

    protected:

    private:
        T100CLCharParser*           m_parser            = T100NULL;
};

#endif // T100CLSTRINGPARSER_H
