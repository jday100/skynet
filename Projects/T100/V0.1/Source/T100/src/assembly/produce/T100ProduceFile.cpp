#include "T100ProduceFile.h"

namespace T100Assembly{

T100ProduceFile::T100ProduceFile(T100STRING name)
    :T100File(name.to_wstring())
{
    //ctor
}

T100ProduceFile::~T100ProduceFile()
{
    //dtor
}

}
