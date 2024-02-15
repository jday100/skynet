#include "T100File.h"

T100File::T100File(T100STRING file)
    :m_filename(file)
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

T100BOOL T100File::create(T100INT64 length)
{
    T100INT64           file_lenght;
    std::ofstream       ofs(m_filename, std::ios::out | std::ios::binary);

    file_lenght = length + 512;

    if(ofs.is_open()){
        ofs.seekp(file_lenght - 1);
        char    data    = 0;
        ofs.write(&data, 1);
        ofs.close();
        return T100TRUE;
    }
    return T100FALSE;
}
