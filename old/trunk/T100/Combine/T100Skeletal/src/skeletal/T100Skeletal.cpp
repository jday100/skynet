#include "T100Skeletal.h"

#include "library\process\T100Process.h"

T100Skeletal::T100Skeletal()
{
    //ctor
}

T100Skeletal::~T100Skeletal()
{
    //dtor
}

T100BOOL T100Skeletal::Run()
{
    T100Process::Run("..\\core\\T100Store.exe");
    T100Process::Run("..\\core\\T100Serve.exe");
    T100Process::Run("..\\core\\T100View.exe");
}
