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

T100BOOL T100DebugFileWriter::write_head()
{
    T100BOOL            result          = T100FALSE;




}

T100BOOL T100DebugFileWriter::write_variables()
{

}

T100BOOL T100DebugFileWriter::write_labels()
{

}

T100BOOL T100DebugFileWriter::write_procedures()
{

}
