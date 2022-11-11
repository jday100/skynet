#include "T100PartFileWriter.h"

namespace T100Assembly{

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
    return T100TRUE;
}

}
