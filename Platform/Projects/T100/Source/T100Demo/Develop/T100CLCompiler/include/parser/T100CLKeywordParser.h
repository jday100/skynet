#ifndef T100CLKEYWORDPARSER_H
#define T100CLKEYWORDPARSER_H

#include "develop/compiler/parser/T100KeywordParser.h"
#include "T100CLStringParser.h"

class T100CLKeywordParser : public T100KeywordParser
{
    public:
        T100CLKeywordParser();
        virtual ~T100CLKeywordParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next();

    protected:

    private:
        T100CLStringParser*         m_parser            = T100NULL;
};

#endif // T100CLKEYWORDPARSER_H
