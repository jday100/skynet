#ifndef T100EVENTFRAME_H
#define T100EVENTFRAME_H

#include "gui/T100Frame.h"
#include "gui/T100AllEvents.h"

class T100EventFrame : public T100Frame
{
    public:
        T100EventFrame(T100Win32Application*);
        virtual ~T100EventFrame();

        T100VOID            Create(T100WSTRING);

    protected:
        T100UINT            T100MENU_ID_RUN         = T100MENU_ID_USER + 1;

        T100VOID            OnMenuRun(T100CommandEvent&);
        T100VOID            OnMenuQuit(T100CommandEvent&);

        T100VOID            OnFrameCreate(T100WindowEvent&);
        T100VOID            OnFrameDestroy(T100WindowEvent&);
        T100VOID            OnFrameClose(T100WindowEvent&);
        T100VOID            OnFrameResize(T100WindowEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100EVENTFRAME_H
