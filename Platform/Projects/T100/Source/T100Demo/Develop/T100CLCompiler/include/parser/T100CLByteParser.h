#ifndef T100CLBYTEPARSER_H
#define T100CLBYTEPARSER_H

#include "develop/compiler/parser/T100ParserBase.h"
#include "T100CLFileParser.h"

class T100CLByteParser : public T100ParserBase
{
    public:
        T100CLByteParser();
        virtual ~T100CLByteParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next();

    protected:

    private:
        T100CLFileParser*           m_parser            = T100NULL;
};

#endif // T100CLBYTEPARSER_H
