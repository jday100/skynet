#ifndef T100PAINTCTRLTEST_H
#define T100PAINTCTRLTEST_H

#include "T100Test.h"

namespace T100WxWidgets{

class T100PaintCtrlTest : public T100Library::T100Test
{
    public:
        T100PaintCtrlTest(T100Test*);
        virtual ~T100PaintCtrlTest();

    protected:
        T100BOOL            do_test();

        T100BOOL            test_paint();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100PAINTCTRLTEST_H
