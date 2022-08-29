#include "T100File.h"

#include <sys/stat.h>
#include <io.h>

T100File::T100File(T100WSTRING name)
    :T100DirectoryEntry(name)
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

T100BOOL T100File::create()
{
    T100INT     result;

    /*
    //test
    T100WSTRING     name;

    name = getName();
    */

    result = ::_wcreat(getName().c_str(), _S_IRWXU);

    if(-1 == result){

    }else{
        result = ::_close(result);

        if(-1 == result){

        }else{
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100File::remove()
{
    T100INT     result;

    result = ::_wremove(getName().c_str());

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}
