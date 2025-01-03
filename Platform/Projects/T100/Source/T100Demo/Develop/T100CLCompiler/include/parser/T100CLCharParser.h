#ifndef T100CLCHARPARSER_H
#define T100CLCHARPARSER_H

#include <atomic>
#include "develop/compiler/parser/T100CharParser.h"
#include "T100CLCharToken.h"
#include "T100CLByteToken.h"
#include "T100CLByteParser.h"

class T100CLCharParser : public T100CharParser
{
    public:
        T100CLCharParser();
        virtual ~T100CLCharParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        T100BOOL                    isLoaded();
        T100BOOL                    read();

        virtual T100BOOL            next(T100State&, T100Token&);

    protected:
        std::atomic_bool            m_loaded;
        T100CLByteToken             m_item;
        T100State*                  m_state             = T100NULL;
        T100CLCharToken*            m_token             = T100NULL;

    private:
        T100VOID                    create();
        T100VOID                    destroy();

        T100CLByteParser*           m_parser            = T100NULL;
};

#endif // T100CLCHARPARSER_H
