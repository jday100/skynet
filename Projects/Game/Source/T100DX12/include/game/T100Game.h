#ifndef T100GAME_H
#define T100GAME_H

#include <string>
#include <windows.h>
#include "d3d12.h"
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"
#include <wrl.h>
#include <shellapi.h>
#include "T100Common.h"

class T100Game
{
    public:
        T100Game(UINT width, UINT height, std::wstring name);
        virtual ~T100Game();

        virtual T100VOID            OnInit() = 0;
        virtual T100VOID            OnUpdate() = 0;
        virtual T100VOID            OnRender() = 0;
        virtual T100VOID            OnDestroy() = 0;

        virtual T100VOID            OnKeyDown(UINT);
        virtual T100VOID            OnKeyUp(UINT);

        UINT                        GetWidth() const;
        UINT                        GetHeight() const;

        const WCHAR*                GetTitle() const;
        T100VOID                    ParseCommandLineArgs(_In_reads_(argc)WCHAR* argv[], int argc);


    protected:
        std::wstring                GetAssetFullPath(LPCWSTR assetName);

        T100VOID                    GetHardwareAdapter(
                                                       _In_ IDXGIFactory1*  pFactory,
                                                       _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
                                                       T100BOOL requestHighPerformanceAdapter = T100FALSE);

        T100VOID                    SetCustomWindowText(LPCWSTR text);

        UINT                        m_width;
        UINT                        m_height;
        float                       m_aspectRatio;

        T100BOOL                    m_useWarpDevice;

    private:
        std::wstring                m_assetsPath;
        std::wstring                m_title;
};

#endif // T100GAME_H
