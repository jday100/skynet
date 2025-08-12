#include "T100FileLogic.h"

#include <io.h>
#include "T100File.h"

T100FileLogic::T100FileLogic()
{
    //ctor
}

T100FileLogic::~T100FileLogic()
{
    //dtor
}

T100BOOL T100FileLogic::IsExists(const T100WSTRING& filename)
{
    T100INT     result;

    result = ::_waccess(filename.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100VOID T100FileLogic::Create(T100FileInfo*)
{

}

T100VOID T100FileLogic::Remove(T100FileInfo*)
{

}

T100VOID T100FileLogic::Rename(T100FileInfo*)
{

}

T100BOOL T100FileLogic::Open(const T100WSTRING& path, T100FileInfo* info)
{
    T100File        file(path);

    if(!file.IsExists()){
        return T100FALSE;
    }

    info->SetPath(path);

    return T100TRUE;
}

T100VOID T100FileLogic::Close(T100FileInfo*)
{

}
