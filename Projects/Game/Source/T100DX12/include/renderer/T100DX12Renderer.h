#ifndef T100DX12RENDERER_H
#define T100DX12RENDERER_H

#include <vector>
#include <memory>
#include "T100Common.h"
#include "T100DeviceResources.h"
#include "T100ShaderStructures.h"
#include "T100Timer.h"

using namespace Microsoft::WRL;

class T100DX12Renderer
{
    public:
        T100DX12Renderer(const std::shared_ptr<T100DeviceResources>& deviceResources);
        virtual ~T100DX12Renderer();

        void                        CreateDeviceDependentResources();
        void                        CreateWindowSizeDependentResources();
        void                        Update(T100Timer const & timer);
        bool                        Render();
        void                        SaveState();

        void                        StartTracking();
        void                        TrackingUpdate(float positionX);
        void                        StopTracking();
        bool                        IsTracking();

    protected:

    private:
        void                        LoadState();
        void                        Rotate(float radians);

    private:
        static const UINT   c_alignedConstantBufferSize     = (sizeof(ModelViewProjectionConstantBuffer) + 255) & ~255;

        std::shared_ptr<T100DeviceResources>            m_deviceResources;

        ComPtr<ID3D12GraphicsCommandList>               m_commandList;
        ComPtr<ID3D12RootSignature>                     m_rootSignature;
        ComPtr<ID3D12PipelineState>                     m_pipelineState;
        ComPtr<ID3D12DescriptorHeap>                    m_cbvHeap;
        ComPtr<ID3D12Resource>                          m_vertexBuffer;
        ComPtr<ID3D12Resource>                          m_indexBuffer;
        ComPtr<ID3D12Resource>                          m_constantBuffer;
        ModelViewProjectionConstantBuffer               m_constantBufferData;
        UINT8*                                          m_mappedConstantBuffer;
        UINT                                            m_cbvDescriptorSize;
        D3D12_RECT                                      m_scissorRect;
        std::vector<byte>                               m_vertexShader;
        std::vector<byte>                               m_pixelShader;
        D3D12_VERTEX_BUFFER_VIEW                        m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                         m_indexBufferView;

        bool                m_loadingComplete;
        float               m_radiansPerSecond;
        float               m_angle;
        bool                m_tracking;
};

#endif // T100DX12RENDERER_H
