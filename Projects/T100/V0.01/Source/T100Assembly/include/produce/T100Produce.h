#ifndef T100PRODUCE_H
#define T100PRODUCE_H

#include "T100AssemblyCommon.h"
#include "T100ParseInfo.h"
#include "T100ProduceInfo.h"
#include "T100ClassPathDrawer.h"
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

        T100ClassPathDrawer&        getPathDrawer();

    protected:
        T100ProduceBuilder*         create_builder(T100ProduceInfo&);

    private:
        T100ClassPathDrawer         m_path_drawer;

};

#endif // T100PRODUCE_H
