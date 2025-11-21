#include "T100Console.h"

#include <iostream>

T100Console::T100Console()
{
    //ctor
}

T100Console::~T100Console()
{
    //dtor
}

T100VOID T100Console::Out(T100STRING value)
{
    std::cout << value;
}
