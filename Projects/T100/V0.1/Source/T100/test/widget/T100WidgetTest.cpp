#include "T100WidgetTest.h"

#include "T100WidgetTestHint.h"

namespace T100WxWidgets{

T100WSTRING         T100WidgetTest::m_name                      = L"widget";

T100WidgetTest::T100WidgetTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_paint(this)
{
    //ctor
}

T100WidgetTest::~T100WidgetTest()
{
    //dtor
}

}
