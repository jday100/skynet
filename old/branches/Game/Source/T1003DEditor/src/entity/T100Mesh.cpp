#include "T100Mesh.h"

#include "Model/CompiledShaders/ModelViewerVS.h"
#include "Model/CompiledShaders/ModelViewerPS.h"
#include "renderer/data/T100DX12Model.h"

T100ENTITY_TYPE         T100Mesh::Type          = T100ENTITY_MESH;
T100WSTRING             T100Mesh::Name          = L"Mesh";


T100Mesh::T100Mesh() :
    T100Entity()
{
    //ctor
    init();
}

T100Mesh::~T100Mesh()
{
    //dtor
    uninit();
}

T100VOID T100Mesh::init()
{
    T100Entity::Name    = L"Mesh";
    T100Entity::Type    = T100ENTITY_MESH;
}

T100VOID T100Mesh::uninit()
{

}

T100VOID T100Mesh::Load(T100DX12Scene* scene)
{

}

T100DX12Model* T100Mesh::Convert(T100DX12Studio* studio)
{
    T100DX12Model*      model       = T100NEW T100DX12Model();

    model->Type                     = T100DX12_MODEL_MESH;

    model->VertexDataPtr            = VertexDataPtr;
    model->VertexDataLength         = VertexDataLength;
    model->IndexDataPtr             = IndexDataPtr;
    model->IndexDataLength          = IndexDataLength;

    model->pVertexShaderData        = (UINT8*)g_pModelViewerVS;
    model->pPixelShaderData         = (UINT8*)g_pModelViewerPS;
    model->VertexShaderDataLength   = sizeof(g_pModelViewerVS);
    model->PixelShaderDataLength    = sizeof(g_pModelViewerPS);

    memcpy(&model->Bundle, &m_bundle, sizeof(T100BUNDLE));

    m_model     = model;

    return model;
}

T100VOID T100Mesh::ToJSON(JSON&)
{

}

T100VOID T100Mesh::FromJSON(JSON&)
{

}

