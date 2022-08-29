#include "T100OSTestKernel.h"

#include "T100HintTest.h"
#include "T100VPCSetup.h"
#include "T100VDisk.h"
#include "T100AssemblyNew.h"
#include "T100VPCApp.h"


T100STDSTRING       T100OSTestKernel::m_unit        = "os.kernel";


T100OSTestKernel::T100OSTestKernel(T100App* app)
    :T100Test(m_unit), m_app(app)
{
    //ctor
}

T100OSTestKernel::~T100OSTestKernel()
{
    //dtor
}

T100BOOL T100OSTestKernel::init()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100VDisk       vdisk("test\\temp\\test.vdk");

    T100Log::info(T100TEST_OS_KERNEL_TEST_INIT_START);

    if(vdisk.exists()){
        value = vdisk.remove();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.exists();
        if(value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.create(1024);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(!vdisk.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        if(1024 * 1024 * 16 != vdisk.length()){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.part_create("first", 1, 512, T100TRUE);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        T100Assembly        assembly;
        T100STDSTRING       source;
        T100STDSTRING       target;

        source  = "boot\\boot.txt";
        target  = T100VPCSetup::getTestOSBuild("test_boot.bin");

        assembly.add("os");
        value = assembly.run(source, target);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.fs_format("first", "test\\build\\test_boot.bin");
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.fs_mkdir("first", ":system");
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        T100Assembly        assembly;
        T100STDSTRING       source;
        T100STDSTRING       target;

        source  = "kernel\\init.txt";
        target  = T100VPCSetup::getTestOSBuild("test_init.bin");

        assembly.add("os");
        value = assembly.run(source, target);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.fs_copy("test\\build\\test_init.bin", "first", ":system:init.bin");
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        T100Assembly        assembly;
        T100STDSTRING       source;
        T100STDSTRING       target;

        source  = "kernel\\kernel.txt";
        target  = T100VPCSetup::getTestOSBuild("test_kernel.bin");

        assembly.add("os");
        value = assembly.run(source, target);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = vdisk.fs_copy("test\\build\\test_kernel.bin", "first", ":system:kernel.bin");
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        T100Assembly        assembly;
        T100STDSTRING       source;
        T100STDSTRING       target;

        source  = "rom\\rom.txt";
        target  = "build\\rom.bin";

        assembly.add("os");
        value = assembly.run(source, target);
        if(!value){
            result = T100FALSE;
        }
    }

    T100Log::info(T100TEST_OS_KERNEL_TEST_INIT_STOP);

    return result;
}

T100BOOL T100OSTestKernel::test_all()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    if(!init()){
        result = T100FALSE;
    }

    if(result && (!test_kernel())){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100OSTestKernel::test_kernel()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100VPCSetup::setVDiskFile("test\\temp\\test.vdk");

    T100VPCApp      vpc;
    T100STDSTRING   target;

    T100Log::info(T100TEST_OS_KERNEL_TEST_START);

    if(result){
        value = vpc.run(m_app, target);
        if(!value){
            result = T100FALSE;
        }

        if(0 == vpc.getReturn()){
            result = T100FALSE;
        }

        vpc.quit();
    }

    T100Log::info(T100TEST_OS_KERNEL_TEST_STOP);

    return result;
}
