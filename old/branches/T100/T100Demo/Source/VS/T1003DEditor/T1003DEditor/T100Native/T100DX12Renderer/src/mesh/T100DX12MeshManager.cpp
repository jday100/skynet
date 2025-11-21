#include "mesh/T100DX12MeshManager.h"

#include "dx12/T100DX12Tools.h"
#include "core/T100DX12Studio.h"
#include "entity/T100City.h"

T100DX12MeshManager::T100DX12MeshManager(T100DX12Studio* studio) :
    T100DX12MeshManagerBase(),
    m_studioPtr(studio),
    m_meshes()
{
    //ctor
}

T100DX12MeshManager::~T100DX12MeshManager()
{
    //dtor
}

T100VOID T100DX12MeshManager::Start()
{
    UploadMeshes();
}

T100VOID T100DX12MeshManager::Stop()
{

}

T100VOID T100DX12MeshManager::Update()
{
    UploadMeshes();
}

T100VOID T100DX12MeshManager::Append(T1003DMesh* mesh)
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    T100DX12Mesh*   result      = T100NULL;

    if(mesh->Type == T100ENTITY_CITY){
        result  = ConvertCity(mesh);
        LoadMesh(result);
    }else{
        result  = ConvertMesh(mesh, m_studioPtr->GetWidth(), m_studioPtr->GetHeight());
        LoadMesh(result);
    }

    m_appendMeshes.push_back(result);
}

T100VOID T100DX12MeshManager::Remove(T1003DMesh* mesh)
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    //m_studio->getFrameManage().Remove(mesh);
}

T100VOID T100DX12MeshManager::LoadMesh(T100DX12Mesh* meshPtr)
{
    meshPtr->Load();
}

T100VOID T100DX12MeshManager::UploadMeshes()
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    for(T100DX12Mesh* mesh : m_appendMeshes){
        UploadMesh(m_studioPtr, mesh);
        m_studioPtr->GetFrameManager().Append(mesh);
    }
    m_appendMeshes.clear();
}

T100VOID T100DX12MeshManager::SetBundle(T1003DMesh* meshPtr)
{

}

T100DX12Mesh* T100DX12MeshManager::ConvertCity(T1003DMesh* meshPtr)
{
    T100DX12Mesh*   resultPtr       = T100NULL;
    T100City*       cityPtr         = T100NULL;

    cityPtr = dynamic_cast<T100City*>(meshPtr);

    if(!cityPtr)return T100NULL;

    resultPtr   = T100NEW T100DX12Mesh();

    MemoryCopy(&resultPtr->Bundle, meshPtr->GetBundlePtr(), sizeof(T100BUNDLE));

    resultPtr->Type                     = meshPtr->Type;
    resultPtr->RenderType               = meshPtr->GetRenderType();
    resultPtr->MotionType               = meshPtr->GetMotionType();

    resultPtr->VertexData.DATA_PTR      = meshPtr->VertexData.DATA_PTR;
    resultPtr->VertexData.LENGTH        = meshPtr->VertexData.LENGTH;

    resultPtr->VertexDescriptions       = (D3D12_INPUT_ELEMENT_DESC*)meshPtr->VertexDescription;
    resultPtr->VertexDescriptionsLength = meshPtr->VertexDescriptionLength;

    resultPtr->SetPosition(meshPtr->GetPosition());
    resultPtr->SetRotation(meshPtr->GetRotation());
    resultPtr->SetScaling(meshPtr->GetScaling());
    resultPtr->SetVisible(meshPtr->IsVisible());

    resultPtr->SetAmount(meshPtr->GetAmount());

    LoadDataFile(meshPtr->VertexShaderFile.REALPATH, &resultPtr->VertexData.DATA_PTR, &resultPtr->VertexData.LENGTH);
    LoadDataFile(meshPtr->PixelShaderFile1.REALPATH, &resultPtr->PixelData1.DATA_PTR, &resultPtr->PixelData1.LENGTH);
    LoadDataFile(meshPtr->PixelShaderFile2.REALPATH, &resultPtr->PixelData2.DATA_PTR, &resultPtr->PixelData2.LENGTH);
    LoadDataFile(meshPtr->MeshDataFile.REALPATH, &resultPtr->MeshData.DATA_PTR, &resultPtr->MeshData.LENGTH);

    resultPtr->Stride               = cityPtr->StandardVertexStride;

    resultPtr->VertexDataOffset     = cityPtr->VertexDataOffset;
    resultPtr->VertexDataLength     = cityPtr->VertexDataLength;
    resultPtr->IndexDataOffset      = cityPtr->IndexDataOffset;
    resultPtr->IndexDataLength      = cityPtr->IndexDataLength;

    resultPtr->IndexFormat          = ConvertFormat(cityPtr->StandardIndexFormat);

    resultPtr->Textures             = (DX12TextureResource*)cityPtr->Textures;
    resultPtr->Draws                = (DX12DrawParameters*)cityPtr->Draws;

    meshPtr->SetInstancePtr(resultPtr);

    return resultPtr;
}

T100VOID T100DX12MeshManager::UploadMesh(T100DX12Studio* studioPtr, T100DX12Mesh* meshPtr)
{
    if(meshPtr->Type == T100ENTITY_CITY){
        UploadCity(studioPtr, meshPtr);
    }else{
        T100DX12MeshManagerBase::UploadMesh(studioPtr, meshPtr);
    }
}

T100VOID T100DX12MeshManager::UploadCity(T100DX12Studio* studioPtr, T100DX12Mesh* meshPtr)
{
    ComPtr<ID3D12Resource>              vertexBufferUploadHeap;
    ComPtr<ID3D12Resource>              indexBufferUploadHeap;
    ComPtr<ID3D12Resource>              textureUploadHeap;

    T100DX12Mesh& mesh = *meshPtr;

    CreateRootSignatureCity(studioPtr, meshPtr);
    CreatePipelineStateCity(studioPtr, meshPtr);
    CreateCommandList(studioPtr, meshPtr);

    CreateVertexBufferCity(studioPtr, meshPtr, vertexBufferUploadHeap);
    CreateIndexBufferCity(studioPtr, meshPtr, indexBufferUploadHeap);
    CreateTextureBufferCity(studioPtr, meshPtr, textureUploadHeap);

    CloseCommandList(meshPtr);
    ExecuteCommandList(studioPtr, meshPtr);

    //studioPtr->Waiting();
}
