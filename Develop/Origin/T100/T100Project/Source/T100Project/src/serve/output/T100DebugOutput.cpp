#include "T100DebugOutput.h"

#include "T100ProjectInvoking.h"

T100DebugOutput::T100DebugOutput() :
    T100Output()
{
    //ctor
}

T100DebugOutput::~T100DebugOutput()
{
    //dtor
}

T100VOID T100DebugOutput::Debug(const T100WSTRING& value)
{
    T100ProjectInvoking::OnDebugPrint(value);
}

T100VOID T100DebugOutput::Print(const T100WSTRING& value)
{
    T100ProjectInvoking::OnDebugPrint(value);
}

T100VOID T100DebugOutput::Error(const T100WSTRING& value)
{
    T100ProjectInvoking::OnDebugPrint(value);
}
