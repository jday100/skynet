#include "T100PartDrawer.h"

#include "T100String.h"
#include "T100PartScannerTools.h"
#include "T100PartFile.h"


T100PartDrawer::T100PartDrawer()
{
    //ctor
}

T100PartDrawer::~T100PartDrawer()
{
    //dtor
}

T100BOOL T100PartDrawer::parse(T100String name)
{
    T100BOOL                    result          = T100TRUE;
    T100PartScanner*            scanner         = T100NULL;
    T100PartScannerTools        tools;
    T100PartToken               token;


    scanner = tools.create(name.to_wstring());

    if(!scanner){
        result = T100FALSE;
    }

    if(result){
        result = scanner->next(token);

    }

    return result;
}

T100BOOL T100PartDrawer::build(T100String name)
{
    T100BOOL                    result          = T100TRUE;

    return result;
}

T100BOOL T100PartDrawer::chdir(T100String path)
{

}

T100String T100PartDrawer::getCwd()
{

}
