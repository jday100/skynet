#ifndef T100DX12DYNAMIC2_H
#define T100DX12DYNAMIC2_H

#include "dx12/T100DX12Header.h"
#include "renderer/utils/T100DX12Timer.h"
#include "renderer/data/T100DX12Camera.h"
#include "renderer/T100DX12FrameResource.h"

#include "renderer/data/T100DX12Model.h"

class T100DX12Studio;

class T100DX12Dynamic2
{
    public:
        T100DX12Dynamic2(T100DX12Studio*);
        virtual ~T100DX12Dynamic2();

        T100VOID                Create(HWND, UINT, UINT);
        T100VOID                Destroy();
        T100VOID                Start();

        T100VOID                Update();
        T100VOID                Render();

        DX12TextureResource Textures[1] =
        {
            { 1024, 1024, 1, DXGI_FORMAT_BC1_UNORM, { { 0, 524288, 2048 }, } }, // city.dds
        };

        DX12DrawParameters Draws[1] =
        {
            { 0, -1, -1, 0, 18642, 0 },
        };

    protected:
        T100DX12Studio*             m_studioPtr         = T100NULL;
        T100DX12Model*              m_modelPtr          = T100NULL;

        static const UINT           CityRowCount = 15;
        static const UINT           CityColumnCount = 8;
        static const UINT           CityMaterialCount = CityRowCount * CityColumnCount;
        static const UINT           CityMaterialTextureWidth = 64;
        static const UINT           CityMaterialTextureHeight = 64;
        static const UINT           CityMaterialTextureChannelCount = 4;
        static const bool           UseBundles = true;
        static const float          CitySpacingInterval;

        struct Vertex
        {
            XMFLOAT3 position;
            XMFLOAT4 color;
        };


        // Frame resources.
        std::vector<T100DX12FrameResource*>         m_frameResources;
        T100DX12FrameResource*                      m_pCurrentFrameResource;
        UINT                                        m_currentFrameResourceIndex;

        void PopulateCommandList(T100DX12FrameResource* pFrameResource);

    private:
        std::wstring    m_assetsPath;
        std::wstring    GetAssetFullPath(LPCWSTR assetName);

        void            loadAssets();
        void            dx12Update();
        void            dx12Render();

        void            CreateFrameResources();
};

#endif // T100DX12DYNAMIC2_H
