#ifndef T100CLSENTENCEPARSER_H
#define T100CLSENTENCEPARSER_H

#include <atomic>
#include "develop/compiler/parser/T100SentenceParser.h"
#include "T100CLSentenceToken.h"
#include "T100CLKeywordToken.h"
#include "T100CLKeywordParser.h"

class T100CLSentenceParser : public T100SentenceParser
{
    public:
        T100CLSentenceParser();
        virtual ~T100CLSentenceParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next(T100State&, T100Token&);

        T100BOOL                    isLoaded();
        T100BOOL                    read();

    protected:
        std::atomic_bool            m_loaded;
        T100CLKeywordToken          m_item;
        T100State*                  m_state             = T100NULL;
        T100CLSentenceToken*        m_token             = T100NULL;

    private:
        T100VOID                    create();
        T100VOID                    destroy();

        T100CLKeywordParser*        m_parser            = T100NULL;
};

#endif // T100CLSENTENCEPARSER_H
