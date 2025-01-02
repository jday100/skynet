#ifndef T100CLCHARPARSER_H
#define T100CLCHARPARSER_H

#include "develop/compiler/parser/T100CharParser.h"
#include "T100CLByteParser.h"

class T100CLCharParser : public T100CharParser
{
    public:
        T100CLCharParser();
        virtual ~T100CLCharParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next(T100State&, T100Token&);

    protected:

    private:
        T100CLByteParser*           m_parser            = T100NULL;
};

#endif // T100CLCHARPARSER_H
