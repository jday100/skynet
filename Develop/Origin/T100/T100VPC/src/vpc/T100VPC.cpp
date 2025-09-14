#include "T100VPC.h"

#include <wx/utils.h>

T100VPC::T100VPC()
{
    //ctor
}

T100VPC::~T100VPC()
{
    //dtor
}

T100VOID T100VPC::Start()
{
    T100WSTRING         cmd;

    cmd = L"PowerShell New-VM -Name \"WinVM\" -MemoryStartupBytes 1GB -NewVHDPath \"C:\\vm\WinVM.vhdx\" -NewVHDSizeBytes 2GB";

    wxExecute(cmd);
}

T100VOID T100VPC::Stop()
{

}
