#include "T100VHD.h"

#include "T100File.h"


T100VHD::T100VHD(T100STRING file, T100INT64 length)
    :m_filename(file), m_length(length)
{
    //ctor
}

T100VHD::~T100VHD()
{
    //dtor
}

T100BOOL T100VHD::create()
{
    T100BOOL        result;
    T100File        file(m_filename);

    result      = file.create(m_length);


    return T100FALSE;
}
