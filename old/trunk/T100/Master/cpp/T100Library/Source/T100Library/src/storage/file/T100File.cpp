#include "storage/file/T100File.h"

#include <sys/stat.h>

namespace T100LIBRARY{

T100File::T100File(const T100WSTRING& name) :
    T100FileSystemEntry(name)
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

T100UINT64 T100File::GetLength()
{
    T100INT             result;
    struct _stat64      state;

    result  = _wstat64(m_entryName.c_str(), &state);

    if(result == -1){
        return 0;
    }
    return state.st_size;
}

}
