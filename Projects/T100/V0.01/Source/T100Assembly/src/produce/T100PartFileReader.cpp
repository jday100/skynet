#include "T100PartFileReader.h"

T100PartFileReader::T100PartFileReader(T100STRING file)
    :T100FileReader(file.to_wstring())
{
    //ctor
}

T100PartFileReader::~T100PartFileReader()
{
    //dtor
}

T100BOOL T100PartFileReader::load(T100PartInfo& info)
{
    return T100TRUE;
}
