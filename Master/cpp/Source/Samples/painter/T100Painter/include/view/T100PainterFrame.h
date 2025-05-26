#ifndef T100PAINTERFRAME_H
#define T100PAINTERFRAME_H

#include "gui/T100Frame.h"
#include "gui/T100ListView.h"
#include "gui/T100AllEvents.h"

class T100PainterFrame : public T100Frame
{
    public:
        T100PainterFrame();
        T100PainterFrame(T100Win32Application*);
        virtual ~T100PainterFrame();

        T100VOID            Create(T100Win32Application*);

    protected:
        T100VOID            OnMenuNew(T100CommandEvent&);
        T100VOID            OnMenuQuit(T100CommandEvent&);

        T100VOID            OnFrameResize(T100WindowEvent&);


        T100VOID            InitListView();

    private:
        T100ListView        m_listView;

        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100PAINTERFRAME_H
