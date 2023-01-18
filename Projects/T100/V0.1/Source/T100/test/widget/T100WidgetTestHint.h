#ifndef T100WIDGETTESTHINT_H
#define T100WIDGETTESTHINT_H

#include "T100Hint.h"

namespace T100WxWidgets{

static T100WSTRING          T100TEST_HINT_WIDGET_PAINT_CTRL_TEST_START                          = L"WxWidgets paint ctrl test is starting ... ";
static T100WSTRING          T100TEST_HINT_WIDGET_PAINT_CTRL_TEST_STOP                           = L"WxWidgets paint ctrl test is stopped . ";


class T100WidgetTestHint : public T100Library::T100Hint
{
    public:
        T100WidgetTestHint();
        virtual ~T100WidgetTestHint();

    protected:

    private:
};

}

#endif // T100WIDGETTESTHINT_H
