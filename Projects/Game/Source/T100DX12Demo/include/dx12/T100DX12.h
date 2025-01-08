#ifndef T100DX12_H
#define T100DX12_H

#include "stdafx.h"
#include "DXSampleHelper.h"
#include "Win32Application.h"

class T100DX12
{
    public:
        T100DX12(UINT width, UINT height, std::wstring name);
        virtual ~T100DX12();

        virtual void OnInit() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnRender() = 0;
        virtual void OnDestroy() = 0;

        // Samples override the event handlers to handle specific messages.
        virtual void OnKeyDown(UINT8 /*key*/)   {}
        virtual void OnKeyUp(UINT8 /*key*/)     {}

        // Accessors.
        UINT GetWidth() const           { return m_width; }
        UINT GetHeight() const          { return m_height; }
        const WCHAR* GetTitle() const   { return m_title.c_str(); }

        void ParseCommandLineArgs(_In_reads_(argc) WCHAR* argv[], int argc);

    protected:
        std::wstring GetAssetFullPath(LPCWSTR assetName);

        void GetHardwareAdapter(
            _In_ IDXGIFactory1* pFactory,
            _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
            bool requestHighPerformanceAdapter = false);

        void SetCustomWindowText(LPCWSTR text);

        // Viewport dimensions.
        UINT m_width;
        UINT m_height;
        float m_aspectRatio;

        // Adapter info.
        bool m_useWarpDevice;

    private:
        // Root assets path.
        std::wstring m_assetsPath;

        // Window title.
        std::wstring m_title;
};

#endif // T100DX12_H
