#ifndef T100DX12_H
#define T100DX12_H

#include <windows.h>

#include "T100Common.h"

class T100DX12
{
    public:
        T100DX12();
        virtual ~T100DX12();

        virtual T100VOID            Create(HWND, UINT, UINT);
        virtual T100VOID            SetSize(UINT, UINT);

        virtual T100VOID            Render();


    protected:

    private:
};

#endif // T100DX12_H
