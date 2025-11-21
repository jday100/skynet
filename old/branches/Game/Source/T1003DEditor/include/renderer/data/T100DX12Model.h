#ifndef T100DX12MODEL_H
#define T100DX12MODEL_H

#include <vector>
#include "math/T100Vector3.h"
#include "common/T100DX12Common.h"
#include "dx12/T100DX12Header.h"
#include "renderer/data/T100DX12Context.h"

#include "common/T100EntityCommon.h"

#define     T100DX12_MODEL_VECTOR           std::vector<T100DX12Model*>

class T100DX12Studio;
class T100DX12Frame;

struct DX12TextureResource
{
    UINT Width;
    UINT Height;
    UINT16 MipLevels;
    DXGI_FORMAT Format;
    struct DataProperties
    {
        UINT Offset;
        UINT Size;
        UINT Pitch;
    } Data[D3D12_REQ_MIP_LEVELS];
};

struct DX12DrawParameters
{
    INT DiffuseTextureIndex;
    INT NormalTextureIndex;
    INT SpecularTextureIndex;
    UINT IndexStart;
    UINT IndexCount;
    UINT VertexBase;
};

class T100DX12Model
{
    friend class T100DX12Discrete;
    friend class T100Dot;
    friend class T100City;
    friend class T100Plane;
    friend class T100Triangle;
    friend class T100Sphere;
    friend class T100Rectangle;

    friend class T100DX12Dynamic2;

    friend class T100DX12Studio;
    friend class T100DX12Context;
    friend class T100DX12ModelManager;
    friend class T100DX12FrameManager;
    friend class T100DX12ContextManager;
    friend class T100DX12ContextManagerBase;
    friend class T100DX12ModelManagerBase;
    friend class T100DX12PipelineStateFactory;
    friend class T100DX12RootSignatureFactory;
    public:
        T100DX12Model();
        virtual ~T100DX12Model();

        T100DX12Model*                          m_selection         = T100NULL;
        T100BOOL                                m_editable          = T100FALSE;

        T100BYTE*                               VertexDataPtr       = T100NULL;
        T100BYTE*                               IndexDataPtr        = T100NULL;

        T100DX12_BUNDLE                         Bundle;
        T100DX12_MODEL_TYPE                     Type;
        T100DX12_RENDER_TYPE                    RenderType;
        T100DX12_MOTION_TYPE                    MotionType;

        Vertex*                                 vertex;
        T100UINT                                Length;

        ComPtr<ID3DBlob>                        vertexShader;
        ComPtr<ID3DBlob>                        pixelShader;

        UINT                                    m_numIndices;

        T100VertexDescriptions*                 VertexDescriptionsPtr;
        T100ShaderParameters*                   ShaderParametersPtr;

    public:
        virtual T100VOID                        Load(T100DX12Studio*);
        virtual T100VOID                        Upload(T100DX12Studio*);

        virtual T100VOID                        Clear();

        virtual T100VOID                        Update();
        virtual T100VOID                        Render(T100DX12Studio*, T100DX12Frame*);

        void XM_CALLCONV UpdateConstantBuffers(FXMMATRIX view, CXMMATRIX projection);

    public:
        UINT8*                                  pVertexShaderData;
        UINT                                    VertexShaderDataLength;

        UINT8*                                  pPixelShaderData;
        UINT                                    PixelShaderDataLength;

        UINT8*                                  pPixelShaderData1;
        UINT                                    PixelShaderDataLength1;

        UINT8*                                  pPixelShaderData2;
        UINT                                    PixelShaderDataLength2;

        UINT8*                                  pMeshData;
        UINT                                    MeshDataLength;

        D3D12_INPUT_ELEMENT_DESC*               VertexDescriptions;
        UINT                                    VertexDescriptionsLength;

        UINT                                    VertexStride;
        DXGI_FORMAT                             IndexFormat;

        UINT                                    VertexDataOffset        = 524288;
        UINT                                    VertexDataLength        = 820248;
        UINT                                    IndexDataOffset         = 1344536;
        UINT                                    IndexDataLength         = 74568;

        DX12TextureResource*                    Textures;
        DX12DrawParameters*                     Draws;

        static const UINT                       CityRowCount = 15;
        static const UINT                       CityColumnCount = 8;
        static const UINT                       CityMaterialCount = CityRowCount * CityColumnCount;
        static const UINT                       CityMaterialTextureWidth = 64;
        static const UINT                       CityMaterialTextureHeight = 64;
        static const UINT                       CityMaterialTextureChannelCount = 4;

        ComPtr<ID3D12Resource>                  m_cityDiffuseTexture;
        ComPtr<ID3D12Resource>                  m_cityMaterialTextures[CityMaterialCount];

    protected:
        ComPtr<ID3D12Resource>                  m_lightBuffer;
        D3D12_STREAM_OUTPUT_BUFFER_VIEW         m_lightBufferView;


        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        ComPtr<ID3D12Resource>                  m_indexBuffer;
        ComPtr<ID3D12Resource>                  m_texture;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                 m_indexBufferView;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12CommandAllocator>          m_bundleAllocator;
        ComPtr<ID3D12GraphicsCommandList>       m_bundle;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;

        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;

        UINT64                                  m_fenceValue;
        std::vector<XMFLOAT4X4>                 m_modelMatrices;

        UINT                                    m_samplerHeapIndex;
        UINT                                    m_textureHeapIndex;

    public:
        T100VOID                                SetPosition(T100Vector3);
        T100VOID                                SetRotation(T100Vector3);
        T100VOID                                SetScaling(T100Vector3);
        T100VOID                                SetVisible(T100BOOL);

        T100DX12_RENDER_TYPE                    ConvertRenderType(T100_RENDER_TYPE);
        T100DX12_MOTION_TYPE                    ConvertMotionType(T100_MOTION_TYPE);
        DXGI_FORMAT                             ConvertFormat(T100DXGI_FORMAT);
        D3D12_INPUT_CLASSIFICATION              ConvertInputSlotClass(T100D3D12_INPUT_CLASSIFICATION);

    protected:
        XMFLOAT3                                m_position;
        XMFLOAT3                                m_rotation;
        XMFLOAT3                                m_scaling;
        T100BOOL                                m_visible;

    private:
        T100DX12Studio*                         m_studio            = T100NULL;
        T100DX12_CONTEXT_VECTOR                 m_contexts;
};

#endif // T100DX12MODEL_H
