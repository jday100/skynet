#include "T100PartFileWriter.h"

T100PartFileWriter::T100PartFileWriter(T100STRING file)
    :T100FileWriter(file.to_wstring())
{
    //ctor
}

T100PartFileWriter::~T100PartFileWriter()
{
    //dtor
}

T100BOOL T100PartFileWriter::save(T100PartInfo* info)
{
    T100BOOL            result          = T100TRUE;

    return result;
}
