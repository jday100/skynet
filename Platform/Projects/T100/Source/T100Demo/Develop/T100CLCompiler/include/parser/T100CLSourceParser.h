#ifndef T100CLSOURCEPARSER_H
#define T100CLSOURCEPARSER_H

#include <atomic>
#include "develop/compiler/parser/T100SourceParser.h"
#include "T100CLSourceToken.h"
#include "T100CLSegmentToken.h"
#include "T100CLSegmentParser.h"

class T100CLSourceParser : public T100SourceParser
{
    public:
        T100CLSourceParser();
        virtual ~T100CLSourceParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next(T100State&, T100Token&);

        T100BOOL                    isLoaded();
        T100BOOL                    read();

    protected:
        std::atomic_bool            m_loaded;
        T100CLSegmentToken          m_item;
        T100State*                  m_state             = T100NULL;
        T100CLSourceToken*          m_token             = T100NULL;

    private:
        T100VOID                    create();
        T100VOID                    destroy();

        T100CLSegmentParser*        m_parser            = T100NULL;
};

#endif // T100CLSOURCEPARSER_H
