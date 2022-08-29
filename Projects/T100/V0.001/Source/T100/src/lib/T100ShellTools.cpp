#include "T100ShellTools.h"

#include "T100Log.h"


T100ShellTools::T100ShellTools()
{
    //ctor
}

T100ShellTools::~T100ShellTools()
{
    //dtor
}

T100INTEGER T100ShellTools::system(T100STDSTRING str)
{
    T100INTEGER     result          = 0;

    T100Log::info(str);
    result = ::system(str.c_str());

    return result;
}
