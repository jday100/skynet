#ifndef T100PAINTERAPP_H
#define T100PAINTERAPP_H

#include "T100WxApp.h"
class T100ThisAppManager;

namespace T100Painter{
class T100Painter;


class T100PainterApp : public T100WxWidgets::T100WxApp
{
    public:
        T100PainterApp(T100ThisAppManager*, T100BOOL = T100FALSE);
        virtual ~T100PainterApp();

        T100VOID            show();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100Painter*        m_painter           = T100NULL;

};

}

#endif // T100PAINTERAPP_H
