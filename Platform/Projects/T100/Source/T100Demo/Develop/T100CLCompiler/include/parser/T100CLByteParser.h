#ifndef T100CLBYTEPARSER_H
#define T100CLBYTEPARSER_H

#include "develop/compiler/parser/T100ParserBase.h"
#include "T100CLFileToken.h"
#include "T100CLByteToken.h"
#include "T100CLFileParser.h"

class T100CLByteParser : public T100ParserBase
{
    public:
        T100CLByteParser();
        virtual ~T100CLByteParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next(T100State&, T100Token&);

        T100BOOL                    isLoaded();
        T100BOOL                    read();

    protected:
        T100INT                     m_current           = -1;
        T100CLFileToken             m_item;

        T100State*                  m_state             = T100NULL;
        T100CLByteToken*            m_token             = T100NULL;

    private:
        T100CLFileParser*           m_parser            = T100NULL;
};

#endif // T100CLBYTEPARSER_H
