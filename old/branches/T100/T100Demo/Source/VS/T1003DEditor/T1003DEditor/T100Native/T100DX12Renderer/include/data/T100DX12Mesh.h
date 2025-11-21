#ifndef T100DX12MESH_H
#define T100DX12MESH_H

#include <vector>
#include "T100Common.h"
#include "T1003DCommon.h"
#include "T100DX12Common.h"
#include "link/T100MeshInstance.h"
#include "T100DX12Context.h"

#define     T100DX12_MESH_VECTOR            std::vector<T100DX12Mesh*>

class T100DX12Mesh : public T100MeshInstance
{
    friend class T100DX12ContextManager;
    friend class T100DX12MeshManagerBase;
    public:
        T100DX12Mesh();
        virtual ~T100DX12Mesh();

        T100UINT                                Type        = 0;

        T100VOID                                Load();
        T100VOID                                Clear();

        T100VOID                                Append(T100DX12Context*);
        T100VOID                                Remove(T100DX12Context*);

        T100BUNDLE                              Bundle;

        T1003D_RENDER_TYPE                      RenderType;
        T1003D_MOTION_TYPE                      MotionType;

        T100BYTE_DATA                           VertexData;
        T100UINT                                Stride;

        ComPtr<ID3DBlob>                        VertexShader;
        ComPtr<ID3DBlob>                        PixelShader;

        D3D12_INPUT_ELEMENT_DESC*               VertexDescriptions          = T100NULL;
        T100UINT                                VertexDescriptionsLength    = 0;

        T100VOID                                SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                                SetPosition(T100Vector3f&);

        T100VOID                                SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                                SetRotation(T100Vector3f&);

        T100VOID                                SetScaling(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                                SetScaling(T100Vector3f&);

        T100VOID                                SetVisible(T100BOOL);

        //
        T100BYTE_DATA                           PixelData1;
        T100BYTE_DATA                           PixelData2;

        T100BYTE_DATA                           IndexData;
        T100BYTE_DATA                           MeshData;

        T100UINT                                VertexDataOffset    = 0;
        T100UINT                                VertexDataLength    = 0;
        T100UINT                                IndexDataOffset     = 0;
        T100UINT                                IndexDataLength     = 0;
        DXGI_FORMAT                             IndexFormat;

        UINT                                    m_textureHeapIndex;

        DX12TextureResource*                    Textures            = T100NULL;

        DX12DrawParameters*                     Draws               = T100NULL;

    protected:
        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        ComPtr<ID3D12Resource>                  m_indexBuffer;
        ComPtr<ID3D12Resource>                  m_texture;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                 m_indexBufferView;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;

        //
        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;

    private:
        T100DX12_CONTEXT_VECTOR                 m_contexts;
};

#endif // T100DX12MESH_H
