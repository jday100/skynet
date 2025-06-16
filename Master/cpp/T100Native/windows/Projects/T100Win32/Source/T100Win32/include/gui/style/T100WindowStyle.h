#ifndef T100WINDOWSTYLE_H
#define T100WINDOWSTYLE_H

#include <windows.h>
#include "base/T100Class.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100WindowStyle : public T100Class
{
    public:
        T100WindowStyle();
        virtual ~T100WindowStyle();

        T100UINT            ClassStyle;
        WNDPROC             Procedure;
        T100WSTRING         ClassType;

        HICON               Icon;
        HICON               IconSmall;
        HCURSOR             Cursor;
        HBRUSH              Background;

    public:
        T100UINT64          WindowStyle;
        T100WSTRING         WindowLabel;
        T100UINT64          ExStyle;

        T100INT             X;
        T100INT             Y;
        T100INT             Width;
        T100INT             Height;

        HMENU               Menu;

    protected:

    private:
};

}

#endif // T100WINDOWSTYLE_H
