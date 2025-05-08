#ifndef T100FRAME_H
#define T100FRAME_H

#include "T100FrameBase.h"
#include "gui/menu/T100MenuBar.h"
#include "gui/event/T100CommandEvent.h"

LRESULT CALLBACK T100DefaultFrameProcedure (HWND, UINT, WPARAM, LPARAM);

class T100Frame : public T100FrameBase
{
    public:
        T100Frame();
        virtual ~T100Frame();

        T100VOID            Create(T100WSTRING, T100UINT, T100UINT);
        T100VOID            Destroy();

        T100VOID            Show();
        T100VOID            Hide();

        T100VOID            SetMenuBarPtr(T100MenuBar*);
        T100MenuBar*        GetMenuBarPtr();

        T100INT             Run();

    protected:
        T100MenuBar*        m_menuBarPtr            = T100NULL;

        T100VOID            OnMenuQuit(T100CommandEvent&);
        T100VOID            OnButtonClick(T100CommandEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100FRAME_H
