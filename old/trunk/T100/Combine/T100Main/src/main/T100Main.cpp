#include "T100Main.h"

#include "library\process\T100Process.h"

T100Main::T100Main()
{
    //ctor
}

T100Main::~T100Main()
{
    //dtor
}

T100INT T100Main::Run()
{
    T100Process::Run("..\\core\\T100Skeletal.exe");
    return 0;
}
