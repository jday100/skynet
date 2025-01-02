#ifndef T100CLPARSERTOOLS_H
#define T100CLPARSERTOOLS_H

#include "T100Common.h"
#include "T100CLCharParser.h"
#include "T100CLSourceParser.h"


class T100CLParserTools
{
    public:
        T100CLParserTools();
        virtual ~T100CLParserTools();

        static T100BOOL         create(T100CLSourceParser*&, T100CLCharParser*&);

    protected:

    private:
};

#endif // T100CLPARSERTOOLS_H
