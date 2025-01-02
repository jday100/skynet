#ifndef T100CLSOURCEPARSER_H
#define T100CLSOURCEPARSER_H

#include "develop/compiler/parser/T100SourceParser.h"
#include "T100CLSegmentParser.h"

class T100CLSourceParser : public T100SourceParser
{
    public:
        T100CLSourceParser();
        virtual ~T100CLSourceParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next();

    protected:

    private:
        T100CLSegmentParser*        m_parser            = T100NULL;
};

#endif // T100CLSOURCEPARSER_H
