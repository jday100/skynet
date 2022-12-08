#include "T100OSRomTest.h"

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

T100WSTRING     T100OSRomTest::m_name                       = L"os.rom";

T100OSRomTest::T100OSRomTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100OSRomTest::~T100OSRomTest()
{
    //dtor
}

T100BOOL T100OSRomTest::init()
{
    T100BOOL        result;

    result = init_vdisk();

    return result;
}

T100BOOL T100OSRomTest::uninit()
{
    return T100TRUE;
}

T100BOOL T100OSRomTest::init_vdisk()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_TEST_VDISK_INIT_START);

    T100STRING          cmd;
    T100STRING          file;
    T100STRING          boot;
    T100VDisk::T100VDiskCmdLineParser       parser;
    T100Library::T100ConsoleTerminal        console(&parser);

    file    = T100ThisAppSetup::getStores(L"vdisk.vdk");
    cmd     = L"create vdisk " + file + L" " + L"1024";

    value = T100Library::T100TestTools::Exists(file.to_wstring());
    if(!value){
        value   = console.exec(cmd.to_wstring());
        if(!value){
            result = T100FALSE;
        }

        if(result){
            cmd     = L"create part first 1 1023";
            value   = console.exec(cmd.to_wstring());
            if(!value){
                result = T100FALSE;
            }
        }

        if(result){
            cmd     = L"format first";
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

    T100Library::T100Log::info(T100TEST_HINT_OS_TEST_VDISK_INIT_STOP);
    return result;
}

T100BOOL T100OSRomTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    if(result){
        value = test_rom();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100OSRomTest::test_rom()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_ROM_TEST_START);

    T100STRING          target;

    target  = T100ThisAppSetup::getBuild(L"rom.bin");

    value   = do_rom();
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = do_boot();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = do_vdisk();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        T100QU32::T100QU32Setup::clear();
        T100QU32::T100QU32Setup::NEED_LOAD_ROM = T100TRUE;
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

    show_result(result, T100TEST_HINT_OS_ROM_TEST_STOP);
    return result;
}

T100BOOL T100OSRomTest::do_rom()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_ROM_TEST_START);

    T100STRING      source;
    T100STRING      target;
    T100Assembly::T100Assembly      assembly;

    source  = T100ThisAppSetup::getWork(L"AOS\\rom\\rom.txt");
    target  = T100ThisAppSetup::getBuild(L"rom.bin");

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

    show_result(result, T100TEST_HINT_OS_ROM_TEST_STOP);
    return result;
}

T100BOOL T100OSRomTest::do_boot()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_ROM_TEST_START);

    T100STRING      source;
    T100STRING      target;
    T100Assembly::T100Assembly      assembly;

    source  = T100ThisAppSetup::getTestResources(L"os\\test_boot.txt");
    target  = T100ThisAppSetup::getTestBuild(L"test_boot.bin");

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

    show_result(result, T100TEST_HINT_OS_ROM_TEST_STOP);
    return result;
}

T100BOOL T100OSRomTest::do_vdisk()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_ROM_TEST_START);

    T100STRING          cmd;
    T100STRING          file;
    T100STRING          boot;
    T100VDisk::T100VDiskCmdLineParser       parser;
    T100Library::T100ConsoleTerminal        console(&parser);

    file    = T100ThisAppSetup::getStores(L"vdisk.vdk");
    cmd     = L"create vdisk " + file + L" " + L"1024";

    value = T100Library::T100TestTools::Remove(file.to_wstring());
    if(!value){
        result = T100FALSE;
    }

    if(result){
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
            boot    = T100ThisAppSetup::getTestBuild(L"test_boot.bin");
            cmd     = L"format first " + boot;
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

    T100Library::T100Log::info(T100TEST_HINT_OS_ROM_TEST_STOP);
    return result;
}

}
