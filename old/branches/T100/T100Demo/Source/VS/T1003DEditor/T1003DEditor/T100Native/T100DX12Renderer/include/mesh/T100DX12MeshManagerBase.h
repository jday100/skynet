#ifndef T100DX12MESHMANAGERBASE_H
#define T100DX12MESHMANAGERBASE_H

#include "dx12/T100DX12Header.h"
#include "link/T1003DMesh.h"
#include "data/T100DX12Mesh.h"

class T100DX12Studio;

class T100DX12MeshManagerBase
{
    public:
        T100DX12MeshManagerBase();
        virtual ~T100DX12MeshManagerBase();

        DXGI_FORMAT         ConvertFormat(T100DXGI_FORMAT);

    protected:
        T100DX12Mesh*       ConvertMesh(T1003DMesh*, T100UINT, T100UINT);
        T100VOID            ConvertScreenMesh(T1003DMesh*, T100UINT, T100UINT, T100DX12Mesh*);
        T100VOID            ConvertSpaceMesh(T1003DMesh*, T100UINT, T100UINT, T100DX12Mesh*);

        T100VOID            UploadMesh(T100DX12Studio*, T100DX12Mesh*);

        T100VOID            LoadFile(T100SHADER_FILE&, ComPtr<ID3DBlob>&);
        T100VOID            LoadDataFile(T100WSTRING, UINT8**, UINT*);
        T100VOID            CompileFile(T100WSTRING, T100WSTRING, T100WSTRING, ComPtr<ID3DBlob>&);

        T100VOID            CreateRootSignature(T100DX12Studio*, T100DX12Mesh*);
        T100VOID            CreateRootSignatureSingle(T100DX12Studio*, T100DX12Mesh*);
        T100VOID            CreateEmptyRootSignature(T100DX12Studio*, T100DX12Mesh*);

        T100VOID            CreateRootSignatureCity(T100DX12Studio*, T100DX12Mesh*);
        T100VOID            CreatePipelineStateCity(T100DX12Studio*, T100DX12Mesh*);

        T100VOID            CreatePipelineState(T100DX12Studio*, T100DX12Mesh*);
        T100VOID            CreateCommandList(T100DX12Studio*, T100DX12Mesh*);
        T100VOID            CloseCommandList(T100DX12Mesh*);
        T100VOID            ExecuteCommandList(T100DX12Studio*, T100DX12Mesh*);

        T100VOID            CreateVertexBuffer(T100DX12Studio*, T100DX12Mesh*, ComPtr<ID3D12Resource>&);


        T100VOID            CreateVertexBufferCity(T100DX12Studio*, T100DX12Mesh*, ComPtr<ID3D12Resource>&);
        T100VOID            CreateIndexBufferCity(T100DX12Studio*, T100DX12Mesh*, ComPtr<ID3D12Resource>&);
        T100VOID            CreateTextureBufferCity(T100DX12Studio*, T100DX12Mesh*, ComPtr<ID3D12Resource>&);

    private:
};

#endif // T100DX12MESHMANAGERBASE_H
