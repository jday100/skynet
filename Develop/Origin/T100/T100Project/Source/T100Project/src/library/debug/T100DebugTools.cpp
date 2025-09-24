#include "T100DebugTools.h"

#include <iostream>

T100DebugTools::T100DebugTools()
{
    //ctor
}

T100DebugTools::~T100DebugTools()
{
    //dtor
}

T100VOID T100DebugTools::Print(const T100WSTRING& value)
{
    std::wcout << value << std::endl;
}
