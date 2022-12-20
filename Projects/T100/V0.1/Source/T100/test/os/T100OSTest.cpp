#include "T100OSTest.h"

#include "T100App.h"
#include "T100Main.h"

#include "T100ThisAppSetup.h"
#include "T100OSTestHint.h"
#include "T100TestTools.h"

#include "T100ConsoleTerminal.h"
#include "T100VDiskCmdLineParser.h"


namespace T100OS{

T100WSTRING         T100OSTest::m_name                      = L"os";

T100OSTest::T100OSTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_rom(this)
{
    //ctor
}

T100OSTest::~T100OSTest()
{
    //dtor
}

T100BOOL T100OSTest::init()
{
    T100BOOL        result;

    result = init_font();
    if(!result){
        return T100FALSE;
    }

    result = init_vdisk();

    return result;
}

T100BOOL T100OSTest::uninit()
{
    return T100TRUE;
}

T100BOOL T100OSTest::init_font()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_TEST_FONT_INIT_START);

    T100STRING      file;

    file    = T100ThisAppSetup::getResources(L"font.fnt");

    value = T100Library::T100TestTools::Exists(file.to_wstring());
    if(!value){
        wxThreadEvent   event(wxEVT_THREAD, T100Frame::ID_THREAD_FONT);

        event.SetString(file.to_wstring());
        wxQueueEvent(wxGetApp().getManager()->getFrame(), event.Clone());

        wxFrame*    frame       = wxGetApp().getManager()->getFrame();
        T100Frame*  item        = (T100Frame*)frame;

        item->wait();

        value = T100Library::T100TestTools::Exists(file.to_wstring());
        if(!value){
            result = T100FALSE;
        }
    }

    T100Library::T100Log::info(T100TEST_HINT_OS_TEST_FONT_INIT_STOP);
    return result;
}

T100BOOL T100OSTest::init_vdisk()
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

}
