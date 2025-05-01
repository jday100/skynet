#ifndef T100THREADFRAME_H
#define T100THREADFRAME_H

#include "gui/T100Frame.h"

class T100ThreadFrame : public T100Frame
{
    public:
        T100ThreadFrame();
        virtual ~T100ThreadFrame();

        T100VOID            Create(T100WSTRING, T100UINT, T100UINT);

    protected:
        T100UINT            T100MENU_ID_RUN         = T100MENU_ID_USER + 1;

        T100VOID            OnMenuRun(T100CommandEvent&);
        T100VOID            OnMenuQuit(T100CommandEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100THREADFRAME_H
