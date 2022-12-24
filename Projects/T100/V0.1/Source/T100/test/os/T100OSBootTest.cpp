#include "T100OSBootTest.h"

#include "T100App.h"
#include "T100Main.h"

#include "T100ThisAppSetup.h"
#include "T100OSTestHint.h"
#include "T100Assembly.h"
#include "T100FileTools.h"
#include "T100TestTools.h"
#include "T100QU32Setup.h"
#include "T100VPC.h"

#include "T100ConsoleTerminal.h"
#include "T100VDiskCmdLineParser.h"


namespace T100OS{

T100WSTRING     T100OSBootTest::m_name                      = L"os.boot";

T100OSBootTest::T100OSBootTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100OSBootTest::~T100OSBootTest()
{
    //dtor
}

T100BOOL T100OSBootTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_boot();
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = test_init();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test_vdisk();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test_run();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100OSBootTest::test_boot()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_BOOT_TEST_ASSEMBLY_START);

    T100STRING      source;
    T100STRING      target;
    T100STRING      path;
    T100Assembly::T100Assembly      assembly;

    source  = T100ThisAppSetup::getWork(L"BOS\\boot\\boot.txt");
    target  = T100ThisAppSetup::getBuild(L"boot.bin");
    path    = T100ThisAppSetup::getWork(L"BOS");

    assembly.getProduce().getClassPathDrawer().append(path);
    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = T100Library::T100TestTools::Exists(target.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_OS_BOOT_TEST_ASSEMBLY_STOP);
    return result;
}

T100BOOL T100OSBootTest::test_init()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_BOOT_TEST_INIT_START);

    T100STRING      source;
    T100STRING      target;
    T100STRING      path;
    T100Assembly::T100Assembly      assembly;

    source  = T100ThisAppSetup::getTestResources(L"os\\test_init.txt");
    target  = T100ThisAppSetup::getTestBuild(L"test_init.bin");
    path    = T100ThisAppSetup::getWork(L"BOS");

    assembly.getProduce().getClassPathDrawer().append(path);
    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = T100Library::T100TestTools::Exists(target.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_OS_BOOT_TEST_INIT_STOP);
    return result;
}

T100BOOL T100OSBootTest::test_vdisk()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_BOOT_TEST_VDISK_START);

    T100STRING      cmd;
    T100STRING      file;
    T100STRING      path;
    T100STRING      boot;
    T100STRING      init;
    T100STRING      kernel;
    T100VDisk::T100VDiskCmdLineParser       parser;
    T100Library::T100ConsoleTerminal        console(&parser);

    file    = T100ThisAppSetup::getStores(L"vdisk.vdk");

    value = T100Library::T100TestTools::Exists(file.to_wstring());
    if(value){
        value = T100Library::T100TestTools::Remove(file.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        cmd     = L"create vdisk " + file + L" " + L"1024";
        value   = console.exec(cmd.to_wstring());
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
            boot    = T100ThisAppSetup::getBuild(L"boot.bin");
            cmd     = L"format first " + boot;
            value   = console.exec(cmd.to_wstring());
            if(!value){
                result = T100FALSE;
            }
        }

        if(result){
            path    = L":system";
            cmd     = L"mkdir first " + path;
            value   = console.exec(cmd.to_wstring());
            if(!value){
                result = T100FALSE;
            }
        }

        if(result){
            init    = T100ThisAppSetup::getTestBuild(L"test_init.bin");
            cmd     = L"copy " + init + L" first :system:init.bin";
            value   = console.exec(cmd.to_wstring());
            if(!value){
                result = T100FALSE;
            }
        }

        cmd     = L"quit";
        value   = console.exec(cmd.to_wstring());
        if(!value){
            result = T100FALSE;
        }


        if(result){
            value = T100Library::T100TestTools::Exists(file.to_wstring());
            if(!value){
                result = T100FALSE;
            }
        }
    }

    show_result(result, T100TEST_HINT_OS_BOOT_TEST_VDISK_STOP);
    return result;
}

T100BOOL T100OSBootTest::test_run()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_BOOT_TEST_RUN_START);

    T100STRING      target;

    target  = T100ThisAppSetup::getBuild(L"rom.bin");

    if(result){
        T100QU32::T100QU32Setup::clear();
        T100QU32::T100QU32Setup::DEBUG          = T100TRUE;
        T100QU32::T100QU32Setup::NEED_LOAD_ROM  = T100TRUE;
        T100QU32::T100QU32Setup::setRomFile(target);

        wxThreadEvent   event(wxEVT_THREAD, T100Frame::ID_THREAD_VPC);
        wxQueueEvent(wxGetApp().getManager()->getFrame(), event.Clone());

        wxFrame*    frame       = wxGetApp().getManager()->getFrame();
        T100Frame*  temp        = (T100Frame*)frame;

        temp->wait();
    }

    if(result){
        wxFrame*    frame       = wxGetApp().getManager()->getFrame();
        T100Frame*  temp        = (T100Frame*)frame;

        if(1 != temp->getReturn()){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_OS_BOOT_TEST_RUN_STOP);
    return result;
}

}
