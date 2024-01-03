#include "T100Disk.h"

#include <iostream>
#include <stdio.h>
#include "windows.h"
#include "conio.h"
#include "winioctl.h"


T100Disk::T100Disk()
{
    //ctor
}

T100Disk::~T100Disk()
{
    //dtor
}


void T100Disk::list() {


    LPCSTR file = "////.//Physicaldrive4";

    //HANDLE disk = CreateFile(file, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, 0);
    HANDLE disk = CreateFile(file, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, 0);

    if(INVALID_HANDLE_VALUE == disk){
        std::cout << "null";
    }else{
        DISK_GEOMETRY   info;
        DWORD           bytes = 0;

        if(DeviceIoControl(disk, IOCTL_DISK_GET_DRIVE_GEOMETRY, NULL, 0, &info, sizeof(DISK_GEOMETRY), &bytes, NULL)){
            DWORD size = info.BytesPerSector;
            PVOID buffer = new BYTE[size];

            std::cout << size;

            if(buffer){
                PARTITION_INFORMATION part;

                if(DeviceIoControl(disk, IOCTL_DISK_GET_PARTITION_INFO, NULL, 0, &part, sizeof(PARTITION_INFORMATION), &bytes, NULL)){
                    //std::cout << part.StartingOffset;
                }
            }
        }else{
            std::cout << "error";
        }
    }

}
