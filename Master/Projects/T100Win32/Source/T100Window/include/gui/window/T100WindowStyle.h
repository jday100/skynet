#ifndef T100WINDOWSTYLE_H
#define T100WINDOWSTYLE_H

#include <windows.h>
#include "T100Common.h"

class T100WindowStyle
{
    public:
        T100WindowStyle();
        virtual ~T100WindowStyle();

        T100WORD            ClassStyle;
        WNDPROC             Procedure;
        T100WSTRING         ClassType;

        HICON               Icon;
        HICON               IconSmall;
        HCURSOR             Cursor;
        HBRUSH              Background;

    public:
        T100DWORD           WindowStyle;
        T100WSTRING         WindowLabel;
        T100DWORD           ExStyle;

        T100INT             X;
        T100INT             Y;
        T100INT             Width;
        T100INT             Height;

        HMENU               Menu;

    protected:

    private:
};

#endif // T100WINDOWSTYLE_H
