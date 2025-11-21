#include "T100Builder.h"

#include "compiler/file/T100NTFile.h"

namespace T100LIBRARY{

T100Builder::T100Builder() :
    T100Class()
{
    //ctor
}

T100Builder::~T100Builder()
{
    //dtor
}

T100BOOL T100Builder::Build(const T100BackInfo& info)
{
    T100NTFile          ntFile(info.GetFileName());

    ntFile.Save();
}

}
