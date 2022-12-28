#include "T100DeployBTest.h"

#include "T100App.h"
#include "T100Main.h"

#include "T100TestTools.h"
#include "T100ThisAppSetup.h"
#include "T100DeployTestHint.h"

#include "T100QU32Setup.h"
#include "T100Assembly.h"

#include "T100ConsoleTerminal.h"
#include "T100VDiskCmdLineParser.h"


namespace T100{

T100WSTRING         T100DeployBTest::m_name                      = L"deploy.b";

T100DeployBTest::T100DeployBTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name)
{
    //ctor
}

T100DeployBTest::~T100DeployBTest()
{
    //dtor
}

T100BOOL T100DeployBTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = deploy_font();
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = deploy_rom();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = deploy_boot();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = deploy_init();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = deploy_kernel();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = deploy_vdisk();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = deploy_run();
        if(!value){
            result = T100FALSE;
        }
    }
    return result;
}

T100BOOL T100DeployBTest::deploy_font()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_DEPLOY_B_FONT_START);

    T100STRING      file;

    file    = T100ThisAppSetup::getResources(L"font.fnt");
    value   = T100Library::T100TestTools::Exists(file.to_wstring());
    if(!value){
        wxThreadEvent   event(wxEVT_THREAD, T100Frame::ID_THREAD_FONT);

        event.SetString(file.to_wstring());
        wxQueueEvent(wxGetApp().getManager()->getFrame(), event.Clone());

        wxFrame*    frame       = wxGetApp().getManager()->getFrame();
        T100Frame*  item        = (T100Frame*)frame;

        item->wait();

        value   = T100Library::T100TestTools::Exists(file.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    show_result(result, T100TEST_HINT_OS_DEPLOY_B_FONT_STOP);
    return result;
}

T100BOOL T100DeployBTest::deploy_rom()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_DEPLOY_B_ROM_START);

    T100STRING      source;
    T100STRING      target;
    T100STRING      path;
    T100Assembly::T100Assembly      assembly;

    source  = T100ThisAppSetup::getWork(L"BOS\\rom\\rom.txt");
    target  = T100ThisAppSetup::getBuild(L"rom.bin");
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

    show_result(result, T100TEST_HINT_OS_DEPLOY_B_ROM_STOP);
    return result;
}

T100BOOL T100DeployBTest::deploy_boot()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_DEPLOY_B_BOOT_START);

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

    show_result(result, T100TEST_HINT_OS_DEPLOY_B_BOOT_STOP);
    return result;
}

T100BOOL T100DeployBTest::deploy_init()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_DEPLOY_B_INIT_START);

    T100STRING      source;
    T100STRING      target;
    T100STRING      path;
    T100Assembly::T100Assembly      assembly;

    source  = T100ThisAppSetup::getWork(L"BOS\\init\\init.txt");
    target  = T100ThisAppSetup::getBuild(L"init.bin");
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

    show_result(result, T100TEST_HINT_OS_DEPLOY_B_INIT_STOP);
    return result;
}

T100BOOL T100DeployBTest::deploy_kernel()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_DEPLOY_B_KERNEL_START);

    T100STRING      source;
    T100STRING      target;
    T100STRING      path;
    T100Assembly::T100Assembly      assembly;

    source  = T100ThisAppSetup::getWork(L"BOS\\kernel\\kernel.txt");
    target  = T100ThisAppSetup::getBuild(L"kernel.knl");
    path    = T100ThisAppSetup::getWork(L"BOS\\kernel");

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

    show_result(result, T100TEST_HINT_OS_DEPLOY_B_KERNEL_STOP);
    return result;
}

T100BOOL T100DeployBTest::deploy_vdisk()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_DEPLOY_B_VDISK_START);

    T100STRING      cmd;
    T100STRING      file;
    T100STRING      path;
    T100STRING      boot;
    T100STRING      init;
    T100STRING      kernel;
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
            init    = T100ThisAppSetup::getBuild(L"init.bin");
            cmd     = L"copy " + init + L" first :system:init.bin";
            value   = console.exec(cmd.to_wstring());
            if(!value){
                result = T100FALSE;
            }
        }

        if(result){
            kernel  = T100ThisAppSetup::getBuild(L"kernel.knl");
            cmd     = L"copy " + kernel + L" first :system:kernel.knl";
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

    T100Library::T100Log::info(T100TEST_HINT_OS_DEPLOY_B_VDISK_STOP);
    return result;
}

T100BOOL T100DeployBTest::deploy_run()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_DEPLOY_B_RUN_START);

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

    show_result(result, T100TEST_HINT_OS_DEPLOY_B_RUN_STOP);
    return result;
}

}
