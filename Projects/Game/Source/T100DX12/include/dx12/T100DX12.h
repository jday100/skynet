#ifndef T100DX12_H
#define T100DX12_H

#include <string>
#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include "d3dx12.h"
#include "T100DX12Helper.h"
#include "T100Application.h"


class T100DX12
{
    public:
        T100DX12(UINT width, UINT height, std::wstring name);
        virtual ~T100DX12();

        virtual void                    OnInit() = 0;
        virtual void                    OnUpdate() = 0;
        virtual void                    OnRender() = 0;
        virtual void                    OnDestroy() = 0;

        virtual void                    OnKeyDown(UINT8 /*key*/)   {}
        virtual void                    OnKeyUp(UINT8 /*key*/)     {}

        UINT                            GetWidth() const           { return m_width; }
        UINT                            GetHeight() const          { return m_height; }
        const WCHAR*                    GetTitle() const   { return m_title.c_str(); }

        void                            ParseCommandLineArgs(_In_reads_(argc) WCHAR* argv[], int argc);

    protected:
        std::wstring                    GetAssetFullPath(LPCWSTR assetName);

        void GetHardwareAdapter(
            _In_ IDXGIFactory1* pFactory,
            _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
            bool requestHighPerformanceAdapter = false);

        void                            SetCustomWindowText(LPCWSTR text);

        UINT                            m_width;
        UINT                            m_height;
        float                           m_aspectRatio;

        bool                            m_useWarpDevice;

    private:
        std::wstring                    m_assetsPath;

        std::wstring                    m_title;
};

#endif // T100DX12_H
