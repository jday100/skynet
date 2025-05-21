#ifndef T100MENUFRAME_H
#define T100MENUFRAME_H

#include "gui/T100Frame.h"

class T100MenuFrame : public T100Frame
{
    public:
        T100MenuFrame(T100Win32Application*);
        virtual ~T100MenuFrame();

        T100VOID            Create(T100WSTRING);

    protected:
        T100UINT            T100MENU_ID_RUN         = T100MENU_ID_USER + 1;

        T100VOID            OnMenuRun(T100CommandEvent&);
        T100VOID            OnMenuQuit(T100CommandEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100MENUFRAME_H
