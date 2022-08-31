#include "T100DebugFile.h"
#include "T100String.h"
#include "T100DebugFileReader.h"
#include "T100DebugFileWriter.h"


T100DebugFile::T100DebugFile(T100String file)
    :T100File(file.to_wstring())
{
    //ctor
}

T100DebugFile::~T100DebugFile()
{
    //dtor
}

T100DebugFileReader* T100DebugFile::getReader()
{
    return T100NEW T100DebugFileReader(getName());
}

T100DebugFileWriter* T100DebugFile::getWriter()
{
    return T100NEW T100DebugFileWriter(getName());
}
