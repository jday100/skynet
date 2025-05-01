#ifndef T100PAINTERFRAME_H
#define T100PAINTERFRAME_H

#include "gui/T100Frame.h"
#include "gui/listctrl/T100ListCtrl.h"

class T100PainterFrame : public T100Frame
{
    public:
        T100PainterFrame();
        virtual ~T100PainterFrame();

        T100VOID            Create(T100WSTRING, T100UINT, T100UINT);

    protected:
        T100VOID            OnMenuNew(T100CommandEvent&);
        T100VOID            OnMenuQuit(T100CommandEvent&);

        T100VOID            OnFrameResize(T100WindowEvent&);


        T100VOID            InitListCtrl();

    private:
        T100ListCtrl        m_listCtrl;

        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100PAINTERFRAME_H
