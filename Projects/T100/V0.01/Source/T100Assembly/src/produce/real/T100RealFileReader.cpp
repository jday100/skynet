#include "T100RealFileReader.h"

T100RealFileReader::T100RealFileReader(T100STRING file)
    :T100FileReader(file.to_wstring())
{
    //ctor
}

T100RealFileReader::~T100RealFileReader()
{
    //dtor
}

T100BOOL T100RealFileReader::load(T100RealInfo& info)
{
    return T100TRUE;
}

T100BOOL T100RealFileReader::read_head()
{
    return T100TRUE;
}

T100BOOL T100RealFileReader::read_data()
{
    return T100TRUE;
}

T100BOOL T100RealFileReader::read_code()
{
    return T100TRUE;
}
