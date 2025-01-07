#ifndef T100DXSAMPLE_H
#define T100DXSAMPLE_H

#include "T100DXSampleHelper.h"
#include "T100Window.h"

class T100DXSample
{
    public:
        T100DXSample(T100Window*, UINT width, UINT height, std::wstring name);
        virtual ~T100DXSample();

        virtual void            OnInit() = 0;
        virtual void            OnUpdate() = 0;
        virtual void            OnRender() = 0;
        virtual void            OnDestroy() = 0;

        virtual void            OnKeyDown(UINT8 key) {}
        virtual void            OnKeyUp(UINT8 key) {}

        UINT                    GetWidth() const {return m_width;}
        UINT                    GetHeight() const {return m_height;}
        const WCHAR*            GetTitle() const {return m_title.c_str();}

        void                    ParseCommandLineArgs(_In_reads_(argc)WCHAR* argv[], int argc);

    protected:
        std::wstring            GetAssetFullPath(LPCWSTR assetName);

        void                    GetHardwareAdapter(
                                                   _In_ IDXGIFactory1*  pFactory,
                                                   _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
                                                   bool requestHighPerformanceAdapter = false
                                                   );

        void                    SetCustomWindowText(LPCWSTR text);

        UINT                    m_width;
        UINT                    m_height;
        float                   m_aspectRatio;

        bool                    m_useWarpDevice;

        T100Window*             m_window            = T100NULL;

    private:
        std::wstring            m_assetsPath;

        std::wstring            m_title;

};

#endif // T100DXSAMPLE_H
