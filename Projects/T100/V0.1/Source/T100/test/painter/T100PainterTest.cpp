#include "T100PainterTest.h"

#include <thread>

#include "T100App.h"
#include "T100Main.h"

#include "T100PainterTestHint.h"

namespace T100Painter{

T100WSTRING         T100PainterTest::m_name                     = L"painter";

T100PainterTest::T100PainterTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100PainterTest::~T100PainterTest()
{
    //dtor
}

T100BOOL T100PainterTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_painter();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100PainterTest::test_painter()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_PAINTER_TEST_START);

    wxThreadEvent   event(wxEVT_THREAD, T100Frame::ID_THREAD_PAINT);
    wxQueueEvent(wxGetApp().getManager()->getFrame(), event.Clone());

    wxFrame*    frame       = wxGetApp().getManager()->getFrame();
    T100Frame*  item        = (T100Frame*)frame;

    item->wait();

    show_result(result, T100TEST_HINT_PAINTER_TEST_STOP);
    return result;
}

}
