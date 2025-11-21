#include "T100DebugTools.h"

#include <iostream>
#include "T100ProjectInvoking.h"

T100DebugTools::T100DebugTools()
{
    //ctor
}

T100DebugTools::~T100DebugTools()
{
    //dtor
}

T100VOID T100DebugTools::Console(const T100WSTRING& value)
{
    std::wcout << value << std::endl;
}

T100VOID T100DebugTools::Print(const T100WSTRING& value)
{
    T100ProjectInvoking::OnDebugPrint(value);
}

T100VOID T100DebugTools::Error(const T100WSTRING& value)
{
    T100ProjectInvoking::OnDebugError(value);
}
