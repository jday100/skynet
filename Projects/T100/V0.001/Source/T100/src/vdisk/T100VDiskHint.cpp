#include "T100VDiskHint.h"

#include "T100StringTools.h"


T100VDiskHint::T100VDiskHint()
{
    //ctor
}

T100VDiskHint::~T100VDiskHint()
{
    //dtor
}

T100STDSTRING T100VDiskHint::part_hint()
{
    T100STDSTRING result;

    result = T100VDISK_HINT_VFS_PART_EMPTY;

    return result;
}

T100STDSTRING T100VDiskHint::part_hint(T100VFS_PART part)
{
    T100STDSTRING result;

    T100String name;

    name = T100StringTools::to_string(part.LABEL, 16);

    result = "\t";
    result += name.to_std_string();
    result += "\t";
    result += std::to_string(part.LOCATION);
    result += "\t";
    result += std::to_string(part.LENGTH);
    result += "\t";
    result += std::to_string(part.BOOT);

    return result;
}

T100STDSTRING T100VDiskHint::item_hint(T100VFS_ITEM item)
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
