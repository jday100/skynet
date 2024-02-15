#ifndef T100VM64SERVE_H
#define T100VM64SERVE_H

#include "T100Common.h"
#include "T100QU64.h"


class T100VM64Serve
{
    public:
        T100VM64Serve();
        virtual ~T100VM64Serve();

        T100BOOL            start();
        T100BOOL            stop();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100QU64*           m_qu64          = T100NULL;
};

#endif // T100VM64SERVE_H
