#ifndef T100VM64HOST_H
#define T100VM64HOST_H

#include "T100VM64Serve.h"
#include "T100VM64View.h"


class T100VM64Host
{
    public:
        T100VM64Host();
        virtual ~T100VM64Host();

        T100BOOL            start();
        T100BOOL            stop();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100VM64Serve*      m_serve         = T100NULL;
        T100VM64View*       m_view          = T100NULL;
};

#endif // T100VM64HOST_H
