#include "T100FullTest.h"

#include <thread>

#include "T100App.h"
#include "T100Main.h"

#include "T100ThisAppSetup.h"
#include "T100FullTestHint.h"
#include "T100FontApp.h"
#include "T100FontBuilder.h"
#include "T100FontView.h"
#include "T100FontFrame.h"
#include "T100FontPanel.h"

#include "T100FileTools.h"
#include "T100TestTools.h"

#include "T100ConsoleTerminal.h"
#include "T100VDiskCmdLineParser.h"

#include "T100Assembly.h"

#include "T100QU32Setup.h"


namespace T100{

T100WSTRING         T100FullTest::m_name                        = L"full";

T100FullTest::T100FullTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name),
    test_virtual(this)
{
    //ctor
}

T100FullTest::~T100FullTest()
{
    //dtor
}

T100BOOL T100FullTest::init()
{
    T100BOOL        result;

    result = init_font();
    if(!result){
        return T100FALSE;
    }

    result = init_vdisk();

    return result;
}

T100BOOL T100FullTest::uninit()
{
    return T100TRUE;
}

T100BOOL T100FullTest::init_font()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_FULL_TEST_FONT_INIT_START);

    wxThreadEvent   event(wxEVT_THREAD, T100Frame::ID_THREAD_FONT);

    wxQueueEvent(wxGetApp().getManager()->getFrame(), event.Clone());

    wxFrame*    frame       = wxGetApp().getManager()->getFrame();
    T100Frame*  item        = (T100Frame*)frame;

    item->wait();

    T100STRING      file;

    file    = T100ThisAppSetup::getTestStores(L"test_font.fnt");

    value = T100Library::T100TestTools::Exists(file.to_wstring());
    if(!value){
        result = T100FALSE;
    }

    T100Library::T100Log::info(T100TEST_HINT_FULL_TEST_FONT_INIT_STOP);
    return result;
}

T100BOOL T100FullTest::init_vdisk()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_FULL_TEST_VDISK_INIT_START);

    T100STRING          cmd;
    T100STRING          file;
    T100STRING          boot;
    T100VDisk::T100VDiskCmdLineParser       parser;
    T100Library::T100ConsoleTerminal        console(&parser);

    file    = T100ThisAppSetup::getTestStores(L"test_vdisk.vdk");
    cmd     = L"create vdisk " + file + L" " + L"1024";

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

    if(result){
        cmd     = L"quit";
        value   = console.exec(cmd.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = T100Library::T100TestTools::Exists(file.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    T100Library::T100Log::info(T100TEST_HINT_FULL_TEST_VDISK_INIT_STOP);
    return result;
}

T100BOOL T100FullTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = do_init();
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = test_full();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test_real_basic();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test_real_stack();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = do_uninit();
        if(!value){
            result = T100FALSE;
        }
    }
    return result;
}

T100BOOL T100FullTest::test_full()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_FULL_TEST_START);

    T100STRING          source;
    T100STRING          target;
    T100STRING          confirm;
    T100Assembly::T100Assembly        assembly;

    source  = T100ThisAppSetup::getTestResources(L"full\\test_full.txt");
    target  = T100ThisAppSetup::getTestBuild(L"test_full.bin");
    confirm = T100ThisAppSetup::getTestResources(L"full\\test_full.bin");

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

    if(result){
        value = T100Library::T100FileTools::compare(target.to_wstring(), confirm.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        T100QU32::T100PRELOAD_ITEM* item    = T100NEW T100QU32::T100PRELOAD_ITEM();

        item->FILE      = target;
        item->OFFSET    = T100MEMORY_RAM_BASE + 2048;
        item->ISRUN     = T100TRUE;

        T100QU32::T100QU32Setup::clear();
        T100QU32::T100QU32Setup::getPreloadFiles().push_back(item);
        T100QU32::T100QU32Setup::NEED_LOAD_ROM = T100FALSE;

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

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    show_result(result, T100TEST_HINT_FULL_TEST_STOP);
    return result;
}

T100BOOL T100FullTest::test_real_basic()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_FULL_REAL_BASIC_TEST_START);

    T100STRING          source;
    T100STRING          target;
    T100STRING          confirm;
    T100Assembly::T100Assembly        assembly;

    source  = T100ThisAppSetup::getTestResources(L"full\\test_real_basic.txt");
    target  = T100ThisAppSetup::getTestBuild(L"test_real_basic.bin");
    confirm = T100ThisAppSetup::getTestResources(L"full\\test_real_basic.bin");

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

    if(result){
        value = T100Library::T100FileTools::compare(target.to_wstring(), confirm.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        T100QU32::T100PRELOAD_ITEM* item    = T100NEW T100QU32::T100PRELOAD_ITEM();

        item->FILE      = target;
        item->OFFSET    = T100MEMORY_RAM_BASE + 2048;
        item->ISRUN     = T100TRUE;

        T100QU32::T100QU32Setup::clear();
        T100QU32::T100QU32Setup::getPreloadFiles().push_back(item);
        T100QU32::T100QU32Setup::NEED_LOAD_ROM = T100FALSE;

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

    show_result(result, T100TEST_HINT_FULL_REAL_BASIC_TEST_STOP);
    return result;
}

T100BOOL T100FullTest::test_real_stack()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_FULL_REAL_STACK_TEST_START);

    T100STRING          source;
    T100STRING          target;
    T100STRING          confirm;
    T100Assembly::T100Assembly        assembly;

    source  = T100ThisAppSetup::getTestResources(L"full\\test_real_stack.txt");
    target  = T100ThisAppSetup::getTestBuild(L"test_real_stack.bin");
    confirm = T100ThisAppSetup::getTestResources(L"full\\test_real_stack.bin");

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

    if(result){
        value = T100Library::T100FileTools::compare(target.to_wstring(), confirm.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        T100QU32::T100PRELOAD_ITEM* item    = T100NEW T100QU32::T100PRELOAD_ITEM();

        item->FILE      = target;
        item->OFFSET    = T100MEMORY_RAM_BASE + 2048;
        item->ISRUN     = T100TRUE;

        T100QU32::T100QU32Setup::clear();
        T100QU32::T100QU32Setup::getPreloadFiles().push_back(item);
        T100QU32::T100QU32Setup::NEED_LOAD_ROM = T100FALSE;

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

    show_result(result, T100TEST_HINT_FULL_REAL_STACK_TEST_STOP);
    return result;
}


}
