#include "T100PaintCtrlTest.h"

#include <thread>

#include "T100App.h"
#include "T100Main.h"

#include "T100WidgetTestHint.h"

namespace T100WxWidgets{

T100WSTRING         T100PaintCtrlTest::m_name                      = L"widget.paint";

T100PaintCtrlTest::T100PaintCtrlTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100PaintCtrlTest::~T100PaintCtrlTest()
{
    //dtor
}

T100BOOL T100PaintCtrlTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_paint();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100PaintCtrlTest::test_paint()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_WIDGET_PAINT_CTRL_TEST_START);

    wxThreadEvent   event(wxEVT_THREAD, T100Frame::ID_THREAD_PAINT);
    wxQueueEvent(wxGetApp().getManager()->getFrame(), event.Clone());

    wxFrame*    frame       = wxGetApp().getManager()->getFrame();
    T100Frame*  item        = (T100Frame*)frame;

    item->wait();

    show_result(result, T100TEST_HINT_WIDGET_PAINT_CTRL_TEST_STOP);
    return result;
}

}
