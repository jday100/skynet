#include "T100File.h"
#include "T100Unicode.h"

T100File::T100File(T100STRING& file)
    :m_file(file)
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

T100BOOL T100File::open()
{
    std::string     file    = T100Unicode::to_string(m_file);
    m_wfs   = T100NEW std::wfstream(file, std::wfstream::in | std::wfstream::binary);

    if(m_wfs->is_open()){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100File::close()
{
    if(m_wfs){
        T100DELETE m_wfs;
        m_wfs   = T100NULL;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100File::read(T100Buffer& buffer)
{
    INT32       length;

    length  = m_wfs->read(buffer.data(), buffer.size()).gcount();

    if(0 == length){
        return T100FALSE;
    }else if(length < buffer.size()){
        buffer.setLength(length);
        return T100TRUE;
    }else if(length == buffer.size()){
        buffer.setLength(length);
        return T100TRUE;
    }
    return T100FALSE;
}
