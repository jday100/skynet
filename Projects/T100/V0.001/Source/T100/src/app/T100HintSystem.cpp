#include "T100HintSystem.h"

#include "T100StringTools.h"


T100HintSystem::T100HintSystem()
{
    //ctor
}

T100HintSystem::~T100HintSystem()
{
    //dtor
}

T100STDSTRING T100HintSystem::item_hint(T100VFS_ITEM item)
{
    T100STDSTRING   result;
    T100String      name;

    name = T100StringTools::to_string(item.NAME, 248);
    result =    "\t";
    result +=   name.to_std_string();
    result +=   "\t";
    result +=   std::to_string(item.LOCATION);
    result +=   "\t";
    result +=   std::to_string(item.LENGTH);
    result +=   "\t";
    //result +=   std::to_string(part.BOOT);

    return result;
}
