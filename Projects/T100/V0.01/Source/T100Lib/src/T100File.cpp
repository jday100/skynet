#include "T100File.h"

#include <sys/stat.h>
#include <io.h>

#include "T100Unicode.h"
#include "T100FileReader.h"
#include "T100FileWriter.h"


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

T100DWORD T100File::length()
{
    T100STDSTRING       name;
    T100WSTRING         source;

    source = getName();
    name = T100Unicode::to_string8(source);

    struct _stat64i32 state;
    int i = ::_stat(name.c_str(), &state);
    if(-1 == i){

    }else{
        m_length = state.st_size / 4;
    }

    return m_length;
}

T100FileReader* T100File::getReader()
{
    return T100NEW T100FileReader(getName());
}

T100FileWriter* T100File::getWriter()
{
    return T100NEW T100FileWriter(getName());
}
