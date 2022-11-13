#include "T100SymbolFileReader.h"

namespace T100Component{

T100SymbolFileReader::T100SymbolFileReader(T100STRING file)
    :T100Library::T100FileReader(file.to_wstring())
{
    //ctor
}

T100SymbolFileReader::~T100SymbolFileReader()
{
    //dtor
}

}
