#ifndef T100EVENTFRAME_H
#define T100EVENTFRAME_H

#include "gui/T100Frame.h"
#include "gui/T100AllEvents.h"
#include "gui/T100Panel.h"

class T100EventFrame : public T100Frame
{
    public:
        T100EventFrame();
        virtual ~T100EventFrame();

        T100VOID            Create(T100Win32Application*, T100FrameStyle* = T100NULL);

        T100VOID            CreateMenu();
        T100VOID            CreatePanel();

    protected:
        T100VOID            OnFrameResize(T100WindowEvent&);

        T100VOID            OnMenuNew(T100MenuEvent&);
        T100VOID            OnMenuOpen(T100MenuEvent&);
        T100VOID            OnMenuQuit(T100MenuEvent&);

        T100VOID            OnButtonClick(T100WindowEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100EVENTFRAME_H
