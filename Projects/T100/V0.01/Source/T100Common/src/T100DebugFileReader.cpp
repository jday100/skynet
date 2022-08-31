#include "T100DebugFileReader.h"
#include "T100String.h"


T100DebugFileReader::T100DebugFileReader(T100String file)
    :T100FileReader(file.to_wstring())
{
    //ctor
}

T100DebugFileReader::~T100DebugFileReader()
{
    //dtor
}
