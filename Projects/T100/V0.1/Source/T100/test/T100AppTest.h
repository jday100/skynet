#ifndef T100APPTEST_H
#define T100APPTEST_H

#include "T100WxApp.h"


class T100AppTest : public T100WxWidgets::T100WxApp
{
    public:
        T100AppTest(T100WxWidgets::T100WxAppManager*);
        virtual ~T100AppTest();

        T100BOOL            run();

        T100BOOL            list();

        T100BOOL            unit(T100WSTRING);

    protected:

    private:
};

#endif // T100APPTEST_H
