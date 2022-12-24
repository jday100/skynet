#include "T100OSLibTest.h"

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

T100WSTRING         T100OSLibTest::m_name                       = L"os.lib";

T100OSLibTest::T100OSLibTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100OSLibTest::~T100OSLibTest()
{
    //dtor
}

T100BOOL T100OSLibTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_string_split();
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = test_run();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100OSLibTest::test_string_split()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_LIB_TEST_STRING_SPLIT_START);

    T100STRING      source;
    T100STRING      target;
    T100STRING      path;
    T100Assembly::T100Assembly      assembly;

    source  = T100ThisAppSetup::getWork(L"BOS\\test\\lib\\test_string_split.txt");
    target  = T100ThisAppSetup::getBuild(L"test_string_split.bin");
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

    show_result(result, T100TEST_HINT_OS_LIB_TEST_STRING_SPLIT_STOP);
    return result;
}

T100BOOL T100OSLibTest::test_run()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_LIB_TEST_RUN_START);

    T100STRING      target;

    target  = T100ThisAppSetup::getBuild(L"test_string_split.bin");

    if(result){
        T100QU32::T100PRELOAD_ITEM* item    = T100NEW T100QU32::T100PRELOAD_ITEM();

        item->FILE      = target;
        item->OFFSET    = T100MEMORY_RAM_BASE + 2048;
        item->ISRUN     = T100TRUE;

        T100QU32::T100QU32Setup::clear();
        T100QU32::T100QU32Setup::DEBUG          = T100TRUE;
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

    show_result(result, T100TEST_HINT_OS_LIB_TEST_RUN_STOP);
    return result;
}

}
