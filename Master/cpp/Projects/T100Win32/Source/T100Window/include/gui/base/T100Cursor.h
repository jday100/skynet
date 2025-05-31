#ifndef T100CURSOR_H
#define T100CURSOR_H

#include <windows.h>
#include "base/T100Class.h"

class T100Cursor : public T100Class
{
    public:
        T100Cursor();
        virtual ~T100Cursor();

        HCURSOR             GetHCURSOR();

    protected:
        HCURSOR             m_cursor;

    private:
};

#endif // T100CURSOR_H
