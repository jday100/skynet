#ifndef T100CLFILEPARSER_H
#define T100CLFILEPARSER_H

#include "develop/compiler/parser/T100ParserBase.h"

class T100CLFileParser : public T100ParserBase
{
    public:
        T100CLFileParser();
        virtual ~T100CLFileParser();

        T100VOID                setSource(T100ParserBase*);
        T100ParserBase*         getSource();

        T100BOOL                open();
        T100BOOL                close();

    protected:

    private:
        T100ParserBase*         m_parser            = T100NULL;

};

#endif // T100CLFILEPARSER_H
