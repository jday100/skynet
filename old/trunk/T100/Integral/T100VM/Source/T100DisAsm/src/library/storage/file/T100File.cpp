#include "T100File.h"

#include <io.h>
#include <fstream>
#include <sys/stat.h>

T100File::T100File(const T100STRING& path) :
    m_path(path)
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

T100VOID T100File::SetPath(const T100STRING& path)
{
    m_path      = path;
}

const T100STRING& T100File::GetPath()
{
    return m_path;
}

T100BOOL T100File::IsExists()
{
    T100INT         result;

    result  = ::_access(m_path.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100File::Load(T100BYTE_VECTOR& file)
{
    T100DATA64      source;
    T100DATA64      target;
    struct _stat64  state;

    source  = file.size();

    if(_stat64(m_path.c_str(), &state) != 0){
        return T100FALSE;
    }

    if(source < state.st_size){
        return T100FALSE;
    }

    target  = state.st_size;

    std::ifstream   ifs(m_path, std::ios::in | std::ios::binary);

    if(!ifs.is_open()){
        return T100FALSE;
    }

    ifs.read((char*)file.data(), target);

    ifs.close();

    return T100TRUE;
}
