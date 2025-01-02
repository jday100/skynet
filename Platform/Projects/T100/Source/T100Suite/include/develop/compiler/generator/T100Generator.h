#ifndef T100GENERATOR_H
#define T100GENERATOR_H

#include "T100Common.h"
#include "develop/compiler/data/T100AnalyzerInfo.h"
#include "develop/compiler/data/T100GeneratorInfo.h"

class T100Generator
{
    public:
        T100Generator();
        virtual ~T100Generator();

        T100BOOL            generate(T100AnalyzerInfo&, T100GeneratorInfo&, T100WString);

    protected:

    private:
};

#endif // T100GENERATOR_H
