#include "T100DebugFileWriter.h"
#include "T100String.h"


T100DebugFileWriter::T100DebugFileWriter(T100String file)
    :T100FileWriter(file.to_wstring())
{
    //ctor
}

T100DebugFileWriter::~T100DebugFileWriter()
{
    //dtor
}
