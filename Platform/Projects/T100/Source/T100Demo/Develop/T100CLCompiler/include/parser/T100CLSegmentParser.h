#ifndef T100CLSEGMENTPARSER_H
#define T100CLSEGMENTPARSER_H

#include <atomic>
#include "develop/compiler/parser/T100SegmentParser.h"
#include "T100CLSegmentToken.h"
#include "T100CLSentenceToken.h"
#include "T100CLSentenceParser.h"

class T100CLSegmentParser : public T100SegmentParser
{
    public:
        T100CLSegmentParser();
        virtual ~T100CLSegmentParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next(T100State&, T100Token&);

        T100BOOL                    isLoaded();
        T100BOOL                    read();

    protected:
        std::atomic_bool            m_loaded;
        T100CLSentenceToken         m_item;
        T100State*                  m_state             = T100NULL;
        T100CLSegmentToken*         m_token             = T100NULL;

    private:
        T100VOID                    create();
        T100VOID                    destroy();

        T100CLSentenceParser*       m_parser            = T100NULL;
};

#endif // T100CLSEGMENTPARSER_H
