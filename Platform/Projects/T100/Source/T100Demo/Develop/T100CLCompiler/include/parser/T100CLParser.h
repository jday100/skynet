#ifndef T100CLPARSER_H
#define T100CLPARSER_H

#include "develop/compiler/parser/T100Parser.h"
#include "T100CLCharParser.h"
#include "T100CLSourceParser.h"

class T100CLParser : public T100Parser
{
    public:
        T100CLParser();
        virtual ~T100CLParser();

        virtual T100BOOL            parse(T100WString, T100ParserInfo&);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100CLCharParser*           m_file              = T100NULL;
        T100CLSourceParser*         m_source            = T100NULL;
};

#endif // T100CLPARSER_H
