#include "T100RealFileReader.h"

namespace T100Assembly{

T100RealFileReader::T100RealFileReader(T100STRING file)
    :T100Library::T100FileReader(file.to_wstring())
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

}
