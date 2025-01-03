#ifndef T100CLKEYWORDPARSER_H
#define T100CLKEYWORDPARSER_H

#include <atomic>
#include "develop/compiler/parser/T100KeywordParser.h"
#include "T100CLKeywordToken.h"
#include "T100CLStringToken.h"
#include "T100CLStringParser.h"

class T100CLKeywordParser : public T100KeywordParser
{
    public:
        T100CLKeywordParser();
        virtual ~T100CLKeywordParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next(T100State&, T100Token&);

        T100BOOL                    isLoaded();
        T100BOOL                    read();

    protected:
        std::atomic_bool            m_loaded;
        T100CLStringToken           m_item;
        T100State*                  m_state             = T100NULL;
        T100CLKeywordToken*         m_token             = T100NULL;

    private:
        T100VOID                    create();
        T100VOID                    destroy();

        T100CLStringParser*         m_parser            = T100NULL;
};

#endif // T100CLKEYWORDPARSER_H
