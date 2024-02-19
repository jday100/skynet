#include "T100MSvhd.h"

#include "windows.h"
#include "winnt.h"
#include "virtdisk.h"
#include "initguid.h"


T100MSvhd::T100MSvhd()
{
    //ctor
}

T100MSvhd::~T100MSvhd()
{
    //dtor
}

T100BOOL T100MSvhd::create()
{
    T100INT64       result          = 0;

    VIRTUAL_STORAGE_TYPE                    type;
    PCWSTR                                  path;
    CREATE_VIRTUAL_DISK_PARAMETERS          parameters;
    PHANDLE                                 handle;

    GUID    guid;

    if(RPC_S_OK != UuidCreate((UUID*)&guid)){
        return T100FALSE;
    }

    path    = L"test.vhd";
    handle  = 0;

    type.DeviceId                           = VIRTUAL_STORAGE_TYPE_DEVICE_UNKNOWN;
    type.VendorId                           = VIRTUAL_STORAGE_TYPE_VENDOR_UNKNOWN;

    memset(&parameters, 0, sizeof(parameters));

    parameters.Version                      = CREATE_VIRTUAL_DISK_VERSION_1;
    parameters.Version1.BlockSizeInBytes    = 0;
    parameters.Version1.MaximumSize         = 1024 * 1024 * 1024;
    parameters.Version1.SectorSizeInBytes   = 512;
    parameters.Version1.UniqueId            = guid;

    result = CreateVirtualDisk(&type, path, VIRTUAL_DISK_ACCESS_NONE, NULL,
                               CREATE_VIRTUAL_DISK_FLAG_NONE, 0, &parameters, 0, handle);


    return T100FALSE;
}

T100BOOL T100MSvhd::create3()
{
    T100INT64       result          = 0;

    VIRTUAL_STORAGE_TYPE                    VirtualStorageType;
    PCWSTR                                  Path;
    VIRTUAL_DISK_ACCESS_MASK                VirtualDiskAccessMask;
    PSECURITY_DESCRIPTOR                    SecurityDescriptor;
    CREATE_VIRTUAL_DISK_FLAG                Flags;
    ULONG                                   ProviderSpecificFlags;
    CREATE_VIRTUAL_DISK_PARAMETERS          Parameters;
    LPOVERLAPPED                            Overlapped;
    PHANDLE                                 Handle;

    GUID    id;

    if(RPC_S_OK != UuidCreate((UUID*)&id)){
        return T100FALSE;
    }

    Path    = L"test.vhd";
    Flags   = CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION;
    Flags   = CREATE_VIRTUAL_DISK_FLAG_NONE;
    Handle  = 0;

    VirtualStorageType.DeviceId             = VIRTUAL_STORAGE_TYPE_DEVICE_VHD;
    VirtualStorageType.VendorId             = VIRTUAL_STORAGE_TYPE_VENDOR_UNKNOWN;

    memset(&Parameters, 0, sizeof(Parameters));

    Parameters.Version                      = CREATE_VIRTUAL_DISK_VERSION_1;
    Parameters.Version1.UniqueId            = id;
    Parameters.Version1.MaximumSize         = 1024 * 1024 * 1024;
    Parameters.Version1.BlockSizeInBytes    = 0;
    Parameters.Version1.SectorSizeInBytes   = 512;
    Parameters.Version1.SourcePath          = 0;
    Parameters.Version1.ParentPath          = 0;

    result  = CreateVirtualDisk(&VirtualStorageType, Path, VIRTUAL_DISK_ACCESS_NONE,
                                NULL, Flags, 0, &Parameters, NULL, Handle);



    if(ERROR_SUCCESS == result){

    }else{

    }
    return T100FALSE;
}

T100BOOL T100MSvhd::create2()
{
    T100INT64       result          = 0;

    VIRTUAL_STORAGE_TYPE                    VirtualStorageType;
    PCWSTR                                  Path;
    VIRTUAL_DISK_ACCESS_MASK                VirtualDiskAccessMask;
    PSECURITY_DESCRIPTOR                    SecurityDescriptor;
    CREATE_VIRTUAL_DISK_FLAG                Flags;
    ULONG                                   ProviderSpecificFlags;
    CREATE_VIRTUAL_DISK_PARAMETERS          Parameters;
    LPOVERLAPPED                            Overlapped;
    PHANDLE                                 Handle;

    GUID    id;

    if(RPC_S_OK != UuidCreate((UUID*)&id)){
        return T100FALSE;
    }

    Path    = L"test.vhd";
    Flags   = CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION;
    Flags   = CREATE_VIRTUAL_DISK_FLAG_NONE;

    VirtualStorageType.DeviceId             = VIRTUAL_STORAGE_TYPE_DEVICE_UNKNOWN;
    VirtualStorageType.VendorId             = VIRTUAL_STORAGE_TYPE_VENDOR_UNKNOWN;

    memset(&Parameters, 0, sizeof(Parameters));

    Parameters.Version                      = CREATE_VIRTUAL_DISK_VERSION_1;
    Parameters.Version1.UniqueId            = id;
    Parameters.Version1.MaximumSize         = 1024 * 1024 * 1024;
    Parameters.Version1.BlockSizeInBytes    = 0x80000;
    Parameters.Version1.SectorSizeInBytes   = 512;
    Parameters.Version1.SourcePath          = 0;
    Parameters.Version1.ParentPath          = 0;

    result  = CreateVirtualDisk(&VirtualStorageType, Path, VIRTUAL_DISK_ACCESS_NONE,
                                NULL, Flags, 0, &Parameters, NULL, Handle);



    if(ERROR_SUCCESS == result){

    }else{

    }
}


T100BOOL T100MSvhd::create1()
{
    T100INT64       result          = 0;

    VIRTUAL_STORAGE_TYPE                    VirtualStorageType;
    PCWSTR                                  Path;
    VIRTUAL_DISK_ACCESS_MASK                VirtualDiskAccessMask;
    PSECURITY_DESCRIPTOR                    SecurityDescriptor;
    CREATE_VIRTUAL_DISK_FLAG                Flags;
    ULONG                                   ProviderSpecificFlags;
    CREATE_VIRTUAL_DISK_PARAMETERS          Parameters;
    LPOVERLAPPED                            Overlapped;
    PHANDLE                                 Handle;

    VirtualStorageType.DeviceId             = VIRTUAL_STORAGE_TYPE_DEVICE_VHD;
    VirtualStorageType.VendorId             = VIRTUAL_STORAGE_TYPE_VENDOR_MICROSOFT;

    Path        = L"test.vhd";

    VirtualDiskAccessMask                   = VIRTUAL_DISK_ACCESS_CREATE;

    SecurityDescriptor                      = NULL;

    Flags   = CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION;

    ProviderSpecificFlags                   = 0;

    Parameters.Version                      = CREATE_VIRTUAL_DISK_VERSION_1;
    Parameters.Version1.MaximumSize         = 1024 * 1024 * 1024;
    Parameters.Version1.ParentPath          = 0;
    Parameters.Version1.SourcePath          = 0;
    Parameters.Version1.BlockSizeInBytes    = 0x80000;
    Parameters.Version1.SectorSizeInBytes   = 512;

    Overlapped                              = 0;
    Handle                                  = 0;

    result  = CreateVirtualDisk(&VirtualStorageType, Path, VirtualDiskAccessMask,
                               &SecurityDescriptor, Flags, ProviderSpecificFlags,
                               &Parameters, Overlapped, Handle);
}

