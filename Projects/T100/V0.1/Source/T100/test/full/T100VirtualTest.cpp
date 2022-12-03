#include "T100VirtualTest.h"

#include "T100App.h"
#include "T100Main.h"

#include "T100ThisAppSetup.h"
#include "T100FullTestHint.h"

#include "T100FileTools.h"
#include "T100TestTools.h"

#include "T100Assembly.h"

#include "T100QU32Setup.h"


namespace T100{

T100WSTRING         T100VirtualTest::m_name                         = L"T100.virtual";

T100VirtualTest::T100VirtualTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name)
{
    //ctor
}

T100VirtualTest::~T100VirtualTest()
{
    //dtor
}

T100BOOL T100VirtualTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_virtual();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VirtualTest::test_virtual()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_FULL_VIRTUAL_BASIC_TEST_START);

    T100STRING          source;
    T100STRING          target;
    T100STRING          confirm;
    T100Assembly::T100Assembly        assembly;

    source  = T100ThisAppSetup::getTestResources(L"full\\test_virtual_basic.txt");
    target  = T100ThisAppSetup::getTestBuild(L"test_virtual_basic.bin");
    confirm = T100ThisAppSetup::getTestResources(L"full\\test_virtual_basic.bin");

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
            //result = T100FALSE;
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

    show_result(result, T100TEST_HINT_FULL_VIRTUAL_BASIC_TEST_STOP);
    return result;
}

}
