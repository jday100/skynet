#ifndef T100ANALYZER_H
#define T100ANALYZER_H

#include "T100Common.h"
#include "develop/compiler/data/T100ParserInfo.h"
#include "develop/compiler/data/T100AnalyzerInfo.h"

class T100Analyzer
{
    public:
        T100Analyzer();
        virtual ~T100Analyzer();

        T100BOOL            analyse(T100ParserInfo&, T100AnalyzerInfo&);

    protected:

    private:
};

#endif // T100ANALYZER_H
