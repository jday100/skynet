#ifndef T100CLPARSERTOOLS_H
#define T100CLPARSERTOOLS_H

#include "T100Common.h"
#include "T100CLFileParser.h"
#include "T100CLByteParser.h"
#include "T100CLCharParser.h"
#include "T100CLStringParser.h"
#include "T100CLKeywordParser.h"
#include "T100CLSentenceParser.h"
#include "T100CLSegmentParser.h"
#include "T100CLSourceParser.h"


class T100CLParserTools
{
    public:
        T100CLParserTools();
        virtual ~T100CLParserTools();

        static T100BOOL         create(T100CLSourceParser*&, T100CLFileParser*&);

    protected:

    private:
};

#endif // T100CLPARSERTOOLS_H
