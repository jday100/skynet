#ifndef T100D3D12_H
#define T100D3D12_H

#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>

#include <wrl.h>
#include <shellapi.h>

#include "T100Common.h"
#include "directxmath.h"

class T100D3D12
{
    public:
        T100D3D12(HWND hwnd);
        virtual ~T100D3D12();

        virtual T100BOOL            load();
        virtual T100BOOL            release();

        virtual T100BOOL            render();

    protected:
        HWND                        m_hwnd;

    private:
        T100VOID                    create();
        T100VOID                    destroy();

};

#endif // T100D3D12_H
