#ifndef T100DIALOGFRAME_H
#define T100DIALOGFRAME_H

#include "gui/T100Frame.h"

class T100DialogFrame : public T100Frame
{
    public:
        T100DialogFrame();
        virtual ~T100DialogFrame();

        T100VOID            Create(T100Win32Application*);

    protected:
        T100WORD            T100MENU_ID_MSGBOX      = T100MENU_ID_USER + 1;
        T100WORD            T100MENU_ID_DIALOG      = T100MENU_ID_USER + 2;

        T100VOID            OnMenuMsgBox(T100CommandEvent&);
        T100VOID            OnMenuDialog(T100CommandEvent&);
        T100VOID            OnMenuQuit(T100CommandEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100DIALOGFRAME_H
