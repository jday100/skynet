#include "T100ThreadCommon.h"

#include "T100Log.h"


T100ThreadCommon::T100ThreadCommon()
{
    //ctor
}

T100ThreadCommon::~T100ThreadCommon()
{
    //dtor
}

T100BOOL T100ThreadCommon::run()
{
    T100Log::info("T100ThreadCommon running...");

    result = T100TRUE;

    return T100TRUE;
}

T100BOOL T100ThreadCommon::ok()
{
    return result;
}
