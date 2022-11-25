#include "T100VDiskTest.h"

#include "T100ThisAppSetup.h"
#include "T100VDiskTestHint.h"
#include "T100ConsoleTerminal.h"
#include "T100VDiskCmdLineParser.h"


namespace T100VDisk{

T100WSTRING     T100VDiskTest::m_name                       = L"vdisk";

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
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_console();
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100VDiskTest::test_console()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_VDISK_CONSOLE_TEST_START);

    T100VDisk::T100VDiskCmdLineParser           parser;
    T100Library::T100ConsoleTerminal            console(&parser);
    T100STRING                                  cmd;
    T100STRING                                  file;
    T100STRING                                  boot;

    file    = T100ThisAppSetup::getTestStores(L"test_vdisk.vdk");
    cmd     = L"create vdisk " + file + L" " + L"1024";

    value = console.exec(cmd.to_wstring());
    if(!value){
        result = T100FALSE;
    }

    if(result){
        cmd     = L"create part first boot 1 1023";
        value   = console.exec(cmd.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        cmd     = L"format first " + boot;
        value   = console.exec(cmd.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        cmd     = L"quit";
        value   = console.exec(cmd.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_VDISK_CONSOLE_TEST_STOP);
    return result;
}


}
