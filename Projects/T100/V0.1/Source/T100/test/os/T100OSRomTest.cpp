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

T100BOOL T100OSRomTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_rom();
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100OSRomTest::test_rom()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_ROM_TEST_START);

    T100STRING          source;
    T100STRING          target;
    T100STRING          confirm;
    T100Assembly::T100Assembly      assembly;

    source  = T100ThisAppSetup::getTestResources(L"os\\test_rom.txt");
    target  = T100ThisAppSetup::getTestBuild(L"test_rom.bin");
    confirm = T100ThisAppSetup::getTestResources(L"os\\test_rom.bin");

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

}
