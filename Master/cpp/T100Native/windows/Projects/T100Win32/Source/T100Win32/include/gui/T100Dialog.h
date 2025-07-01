#ifndef T100DIALOG_H
#define T100DIALOG_H

#include "gui/window/T100SelfLoopWindow.h"

#ifdef CreateDialog
#undef CreateDialog
#endif // CreateDialog

namespace T100WINDOWS{

BOOL CALLBACK DefaultDialogProcedure (HWND, UINT, WPARAM, LPARAM);

class T100Dialog : public T100SelfLoopWindow
{
    public:
        T100Dialog();
        T100Dialog(T100Window*);
        virtual ~T100Dialog();

        virtual T100VOID            Create(T100Window*);
        virtual T100VOID            Destroy();

    protected:
        T100VOID                    CreateDialog(HINSTANCE, HWND);

    private:
        T100VOID                    init(T100Window*);
        T100VOID                    uninit();
};

}

#endif // T100DIALOG_H
