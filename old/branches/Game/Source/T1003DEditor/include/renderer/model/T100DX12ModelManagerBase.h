#ifndef T100DX12MODELMANAGERBASE_H
#define T100DX12MODELMANAGERBASE_H

#include "dx12/T100DX12Header.h"
#include "renderer/data/T100DX12Model.h"
#include "common/T100EntityCommon.h"

class T100DX12Studio;

class T100DX12ModelManagerBase
{
    public:
        T100DX12ModelManagerBase();
        virtual ~T100DX12ModelManagerBase();

        DXGI_FORMAT                 ConvertFormat(T100DXGI_FORMAT);

    protected:
        T100VOID                    Upload(T100DX12Studio*, T100DX12Model*);

        T100VOID                    CreateEmptyRootSignature(T100DX12Studio*, T100DX12Model*);
        T100VOID                    CreateRootSignature(T100DX12Studio*, T100DX12Model*);
        T100VOID                    CreateCommandList(T100DX12Studio*, T100DX12Model*);
        T100VOID                    CloseCommandList(T100DX12Model*);
        T100VOID                    ExecuteCommandList(T100DX12Studio*, T100DX12Model*);

        T100VOID                    CreatePipelineState(T100DX12Studio*, T100DX12Model*);
        T100VOID                    CreatePipelineState1And2(T100DX12Studio*, T100DX12Model*);
        T100VOID                    CreateVertexBuffer(T100DX12Studio*, T100DX12Model*, ComPtr<ID3D12Resource>&);
        T100VOID                    CreateIndexBuffer(T100DX12Studio*, T100DX12Model*, ComPtr<ID3D12Resource>&);
        T100VOID                    CreateTextureBuffer(T100DX12Studio*, T100DX12Model*, ComPtr<ID3D12Resource>&);

        T100VOID                    CreateVertexBuffer(T100DX12Studio*, T100DX12Model*);

        T100VOID                    CreateLightBuffer(T100DX12Studio*, T100DX12Model*);

        T100VOID                    CreateRootSignatureMesh(T100DX12Studio*, T100DX12Model*);
        T100VOID                    CreatePipelineStateMesh(T100DX12Studio*, T100DX12Model*);

    private:
        T100VOID                    UploadDot(T100DX12Studio*, T100DX12Model*);
        T100VOID                    UploadLine(T100DX12Studio*, T100DX12Model*);
        T100VOID                    UploadTriangle(T100DX12Studio*, T100DX12Model*);
        T100VOID                    UploadPlane(T100DX12Studio*, T100DX12Model*);
        T100VOID                    UploadCity(T100DX12Studio*, T100DX12Model*);
        T100VOID                    UploadMesh(T100DX12Studio*, T100DX12Model*);
        T100VOID                    UploadSphere(T100DX12Studio*, T100DX12Model*);

        T100VOID                    UploadRectangle(T100DX12Studio*, T100DX12Model*);
};

#endif // T100DX12MODELMANAGERBASE_H
