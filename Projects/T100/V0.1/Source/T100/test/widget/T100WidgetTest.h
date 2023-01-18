#ifndef T100WIDGETTEST_H
#define T100WIDGETTEST_H

#include "T100Test.h"
#include "T100PaintCtrlTest.h"

namespace T100WxWidgets{

class T100WidgetTest : public T100Library::T100Test
{
    public:
        T100WidgetTest(T100Test*);
        virtual ~T100WidgetTest();

    protected:
        T100PaintCtrlTest           test_paint;

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100WIDGETTEST_H
