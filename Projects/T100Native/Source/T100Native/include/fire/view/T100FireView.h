#ifndef T100FIREVIEW_H
#define T100FIREVIEW_H

#include "T100Common.h"
#include "T100NativeMain.h"
#include "T100FireRender.h"

class T100FireView
{
    public:
        T100FireView();
        virtual ~T100FireView();

        T100VOID                Show();
        T100NativeFrame*        GetFrame();
        T100FireRender*         GetRender();

    protected:
        T100NativeFrame*        m_frame         = T100NULL;
        T100FireRender*         m_render        = T100NULL;

    private:
        T100VOID                TurnOn();
        T100VOID                TurnOff();
};

#endif // T100FIREVIEW_H
