#include "T100VDiskTest.h"

#include "T100AppSetup.h"
#include "T100TestTools.h"
#include "T100VDisk.h"


T100WSTRING         T100VDiskTest::m_name                       = L"common.vdisk";


T100VDiskTest::T100VDiskTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100VDiskTest::~T100VDiskTest()
{
    //dtor
}

T100BOOL T100VDiskTest::do_test()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = test_vdisk();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VDiskTest::test_vdisk()
{
    T100BOOL                result          = T100TRUE;
    T100BOOL                value;

    T100DWORD               length;
    T100STRING              name;

    name    = T100AppSetup::getTestStores(L"test_vdisk.vdk");
    length  = 1024;

    T100VDisk               disk(name);

    value = disk.exists();
    if(value){
        value = disk.remove();
        if(value){
            value = disk.exists();
            if(value){
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    value = disk.create(length);
    if(value){
        value = disk.exists();
        if(!value){
            return T100FALSE;
        }
    }else{
        return T100FALSE;
    }


    return result;
}
