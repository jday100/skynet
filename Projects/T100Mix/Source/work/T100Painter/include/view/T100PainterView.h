#ifndef T100PAINTERVIEW_H
#define T100PAINTERVIEW_H

#include "T100Common.h"
#include "T100PainterMain.h"

class T100PainterView
{
    public:
        T100PainterView();
        virtual ~T100PainterView();

        T100VOID                show();
        wxFrame*                getFrame();

    public:
        T100BOOL                Open();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100PainterFrame*       m_frame         = T100NULL;
};

#endif // T100PAINTERVIEW_H
