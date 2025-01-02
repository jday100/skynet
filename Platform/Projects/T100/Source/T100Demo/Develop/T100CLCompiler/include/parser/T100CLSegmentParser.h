#ifndef T100CLSEGMENTPARSER_H
#define T100CLSEGMENTPARSER_H

#include "develop/compiler/parser/T100SegmentParser.h"
#include "T100CLSentenceParser.h"

class T100CLSegmentParser : public T100SegmentParser
{
    public:
        T100CLSegmentParser();
        virtual ~T100CLSegmentParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next(T100State&, T100Token&);

    protected:

    private:
        T100CLSentenceParser*       m_parser        = T100NULL;
};

#endif // T100CLSEGMENTPARSER_H
