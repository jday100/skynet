#include "T100SymbolFileWriter.h"

namespace T100Component{

T100SymbolFileWriter::T100SymbolFileWriter(T100STRING file)
    :T100Library::T100FileWriter(file.to_wstring())
{
    //ctor
}

T100SymbolFileWriter::~T100SymbolFileWriter()
{
    //dtor
}

T100BOOL T100SymbolFileWriter::write_head()
{
    return T100FALSE;
}

T100BOOL T100SymbolFileWriter::write_variables()
{
    return T100FALSE;
}

T100BOOL T100SymbolFileWriter::write_labels()
{
    return T100FALSE;
}

T100BOOL T100SymbolFileWriter::write_procedures()
{
    return T100FALSE;
}

}
