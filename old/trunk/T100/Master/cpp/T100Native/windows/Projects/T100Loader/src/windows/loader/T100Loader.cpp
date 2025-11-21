#include "T100Loader.h"

#include "T100WindowsFile.h"

namespace T100WINDOWS{

T100Loader::T100Loader() :
    T100Class()
{
    //ctor
}

T100Loader::~T100Loader()
{
    //dtor
}

T100BOOL T100Loader::Load(const T100WSTRING& file)
{
    T100WindowsFile         winFile(file);

    winFile.Load();
}

}
