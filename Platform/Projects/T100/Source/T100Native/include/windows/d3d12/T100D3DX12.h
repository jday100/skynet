#ifndef T100D3DX12_H
#define T100D3DX12_H

#include <windows.h>

#include "T100Common.h"

class T100D3DX12
{
    public:
        T100D3DX12();
        virtual ~T100D3DX12();

        T100BOOL                    Create(HWND);
        T100BOOL                    Destroy();

        T100BOOL                    Render();

    protected:
        HWND                        m_hwnd;

    private:
        T100VOID                    Init();
        T100VOID                    Uninit();

};

#endif // T100D3DX12_H
