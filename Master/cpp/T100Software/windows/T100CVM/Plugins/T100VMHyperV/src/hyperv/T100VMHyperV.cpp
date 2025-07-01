#include "T100VMHyperV.h"

#include <iostream>
#include <stdio.h>
#include <winerror.h>
#include <windows.h>
#include "T100Win32Tools.h"

#include <computecore.h>
#include <computedefs.h>
#include <computenetwork.h>
#include <computestorage.h>

#pragma comment(lib, "computecore.lib")

/*
0x8037011b  access denied
0x80070020  windows update error
*/

T100VMHyperV::T100VMHyperV() :
    T100VMBase()
{
    //ctor
}

T100VMHyperV::~T100VMHyperV()
{
    //dtor
}

T100VOID T100VMHyperV::Start()
{

    wchar_t config[] = LR"(
        {
            "SchemaVersion":{
                "Major":2,
                "Minor":1
            },
            "Owner":"Sample",
            "ShouldTerminateOnLastHandleClosed" :true,
            "VirtualMachine":{
                "Chipset":{
                    "Uefi":{
                        "BootThis":{
                            "DevicePath":"Primary disk",
                            "DiskNumber" : 0,
                            "DeviceType": "ScsiDrive"
                        }
                    }
                },
                "ComputeTopology":{
                    "Memory":{
                        "Backing":"Virtual",
                        "SizeInMB":2048
                    },
                    "Processor":{
                        "Count":2
                    }
                },
                "Devices":{
                    "Scsi":{
                        "Primary disk":{
                            "Attachments":{
                                "0":{
                                    "Type":"VirtualDisk",
                                    "Path":"c:\\vm\\vm.vhdx"
                                }
                            }
                        }
                    }
                }
            }
        }
        )";

    HCS_OPERATION   operation     = ::HcsCreateOperation(NULL, NULL);
    HCS_SYSTEM      system;

    HRESULT         result;
    ThrowIfFailed(::HcsCreateComputeSystem(
        L"Sample",
        config,
        operation,
        NULL,
        &system
        ));

    wchar_t     *resultDoc;
    ThrowIfFailed(::HcsWaitForOperationResult(operation, INFINITE, &resultDoc));

    wprintf(L"%s", resultDoc);

    ThrowIfFailed(::HcsStartComputeSystem(system, operation, NULL));

    ThrowIfFailed(::HcsWaitForOperationResult(operation, INFINITE, &resultDoc));

    wprintf(L"%s", resultDoc);

    wchar_t vmQuery[] = LR"(
        {
            "PropertyTypes":[
                "Memory"
            ]
        }
        )";

    ThrowIfFailed(::HcsGetComputeSystemProperties(system, operation, vmQuery));
    ThrowIfFailed(::HcsWaitForOperationResult(operation, INFINITE, &resultDoc));

    std::wstring  msg  = resultDoc;

    std::wcout << msg;

    //wprintf(L"%s", msg.c_str());
}

T100VOID T100VMHyperV::Stop()
{

}
