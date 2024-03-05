#include "T100File.h"

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

    m_wfs   = T100NEW std::wfstream(m_file, std::wfstream::in | std::wfstream::binary);

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

    lenth   = m_wfs->read(buffer.data(), buffer.length()).gcount();

    if(0 == length){
        return T100FALSE;
    }else if(length < buffer.length()){
        buffer.setLength(length);
        return T100TRUE;
    }else if(length == buffer.length()){
        buffer.setLength(length);
        return T100TRUE;
    }
    return T100FALSE;
}
