#include "T100ExecutableFileReader.h"
#include "T100String.h"


T100ExecutableFileReader::T100ExecutableFileReader(T100STRING file)
    :T100FileReader(file.to_wstring())
{
    //ctor
}

T100ExecutableFileReader::~T100ExecutableFileReader()
{
    //dtor
}

T100BOOL T100ExecutableFileReader::load(T100ExecutableInfo& info)
{
    return T100TRUE;
}
