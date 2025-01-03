#ifndef T100DX12_H
#define T100DX12_H

#include "T100Common.h"

class T100DX12
{
    public:
        T100DX12();
        virtual ~T100DX12();

        T100BOOL            run();

    protected:

    private:
        T100VOID            create();
        T100VOID            destroy();
};

#endif // T100DX12_H
