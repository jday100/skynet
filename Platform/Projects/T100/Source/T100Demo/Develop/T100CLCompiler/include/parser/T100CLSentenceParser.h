#ifndef T100CLSENTENCEPARSER_H
#define T100CLSENTENCEPARSER_H

#include "develop/compiler/parser/T100SentenceParser.h"
#include "T100CLKeywordParser.h"

class T100CLSentenceParser : public T100SentenceParser
{
    public:
        T100CLSentenceParser();
        virtual ~T100CLSentenceParser();

        virtual T100VOID            setSource(T100ParserBase*);
        virtual T100ParserBase*     getSource();

        virtual T100BOOL            next();

    protected:

    private:
        T100CLKeywordParser*        m_parser            = T100NULL;
};

#endif // T100CLSENTENCEPARSER_H
