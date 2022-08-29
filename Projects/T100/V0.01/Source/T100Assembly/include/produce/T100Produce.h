#ifndef T100PRODUCE_H
#define T100PRODUCE_H

#include "T100AssemblyCommon.h"
#include "T100ParseInfo.h"
#include "T100ProduceInfo.h"
class T100ProduceBuilder;

/*

ProduceInfo
    PartInfo
        Parse
            ParseInfo
                PartToken
        Build
            BuildInfo

*/

class T100Produce
{
    public:
        T100Produce();
        virtual ~T100Produce();

        T100BOOL                    run(T100STRING&, T100STRING&);

    protected:
        T100ProduceBuilder*         create_builder(T100ProduceInfo&);

    private:
};

#endif // T100PRODUCE_H
