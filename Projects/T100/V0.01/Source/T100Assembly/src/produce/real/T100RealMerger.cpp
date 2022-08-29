#include "T100RealMerger.h"
#include "T100AssemblyCommon.h"
#include "T100PartDrawer.h"


T100RealMerger::T100RealMerger()
{
    //ctor
}

T100RealMerger::~T100RealMerger()
{
    //dtor
}

T100BOOL T100RealMerger::run(T100ProduceInfo& source, T100RealInfo& target)
{
    T100BOOL            result          = T100TRUE;

    T100PART_INFO_VECTOR&       parts   = source.getPartDrawer().getPartInfos();

    for(T100PartInfo* item : parts){
        if(item){
            result = merge(target, item);
            if(!result){
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100RealMerger::merge(T100RealInfo& info, T100PartInfo* part)
{
    return T100TRUE;
}
