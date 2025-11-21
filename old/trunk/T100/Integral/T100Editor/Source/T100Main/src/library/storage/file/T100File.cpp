#include "library\storage\file\T100File.h"

#include <io.h>

T100File::T100File(T100WSTRING path) :
    m_path(path)
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

T100BOOL T100File::IsExists()
{
    T100INT         result;

    result  = ::_waccess(m_path.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }
    return T100FALSE;
}
