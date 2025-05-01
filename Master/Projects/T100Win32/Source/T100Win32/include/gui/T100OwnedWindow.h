#ifndef T100OWNEDWINDOW_H
#define T100OWNEDWINDOW_H

#include "gui/T100Window.h"

class T100OwnedWindow : public T100Window
{
    public:
        T100OwnedWindow();
        virtual ~T100OwnedWindow();

        T100VOID            Create(T100Window*, T100WSTRING, T100UINT, T100UINT);

    protected:
        T100VOID            RegisterWindow(T100WSTRING);

    private:
};

#endif // T100OWNEDWINDOW_H
