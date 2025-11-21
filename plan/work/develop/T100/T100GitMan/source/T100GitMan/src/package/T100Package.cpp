#include "T100Package.h"

#include <windows.h>
#include <shlobj.h>

T100Package::T100Package()
{
    //ctor
}

T100Package::~T100Package()
{
    //dtor
}

void T100Package::Install(char* value)
{
    PWSTR       path    = NULL;
    HRESULT     result  = SHGetKnownFolderPath(FOLDERID_Profile, 0, NULL, &path);
}
