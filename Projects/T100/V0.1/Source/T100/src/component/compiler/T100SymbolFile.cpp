#include "T100SymbolFile.h"

namespace T100Component{

T100SymbolFile::T100SymbolFile(T100STRING name)
    :T100Library::T100File(name.to_wstring())
{
    //ctor
}

T100SymbolFile::~T100SymbolFile()
{
    //dtor
}

T100SymbolFileReader* T100SymbolFile::getReader()
{
    T100SymbolFileReader*       result          = T100NULL;

    result = T100NEW T100SymbolFileReader(getName());

    return result;
}

T100SymbolFileWriter* T100SymbolFile::getWriter()
{
    T100SymbolFileWriter*       result          = T100NULL;

    result = T100NEW T100SymbolFileWriter(getName());

    return result;
}

}
