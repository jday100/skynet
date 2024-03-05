#include "T100Log.h"

#include <iostream>


T100Log::T100Log()
{
    //ctor
}

T100Log::~T100Log()
{
    //dtor
}


T100VOID T100Log::log(T100STRING msg)
{
    std::wcout << msg;
    std::wcout << std::endl;
}
