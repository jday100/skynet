#include "T100FolderLogic.h"

#include <io.h>

T100FolderLogic::T100FolderLogic()
{
    //ctor
}

T100FolderLogic::~T100FolderLogic()
{
    //dtor
}

T100BOOL T100FolderLogic::IsExists(const T100WSTRING& path)
{
    T100INT     result;

    result = ::_waccess(path.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}
