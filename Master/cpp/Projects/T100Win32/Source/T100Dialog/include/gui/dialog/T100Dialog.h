#ifndef T100DIALOG_H
#define T100DIALOG_H

#include "gui/window/T100Window.h"

BOOL CALLBACK DefaultDialogProcedure (HWND, UINT, WPARAM, LPARAM);

class T100Dialog : public T100Window
{
    public:
        T100Dialog();
        virtual ~T100Dialog();

        virtual T100VOID            Create(T100Window*);

        virtual T100VOID            Show();

    protected:

    private:
};

#endif // T100DIALOG_H
