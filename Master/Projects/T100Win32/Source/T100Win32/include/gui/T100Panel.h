#ifndef T100PANEL_H
#define T100PANEL_H

#include "T100Window.h"

class T100Panel : public T100Window
{
    public:
        T100Panel();
        virtual ~T100Panel();

        T100VOID            Create(T100Window*, T100WSTRING, T100UINT, T100UINT);

    protected:

    private:
};

#endif // T100PANEL_H
