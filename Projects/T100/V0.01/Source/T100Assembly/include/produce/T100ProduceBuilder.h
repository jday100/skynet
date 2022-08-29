#ifndef T100PRODUCEBUILDER_H
#define T100PRODUCEBUILDER_H

#include "T100AssemblyCommon.h"
#include "T100ProduceInfo.h"


class T100ProduceBuilder
{
    public:
        T100ProduceBuilder();
        virtual ~T100ProduceBuilder();

        virtual T100BOOL            run(T100STRING&, T100ProduceInfo&) = 0;

    protected:

    private:
};

#endif // T100PRODUCEBUILDER_H
