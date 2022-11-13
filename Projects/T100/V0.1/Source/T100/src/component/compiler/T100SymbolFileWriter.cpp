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

}
