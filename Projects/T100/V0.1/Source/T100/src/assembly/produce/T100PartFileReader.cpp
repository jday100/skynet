#include "T100PartFileReader.h"

namespace T100Assembly{

T100PartFileReader::T100PartFileReader(T100STRING file)
    :T100Library::T100FileReader(file.to_wstring())
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

}
