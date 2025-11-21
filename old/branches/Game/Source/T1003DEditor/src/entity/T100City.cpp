#include "T100City.h"

#include "T100DX12Model.h"
#include "T100DX12Scene.h"
#include "T100DX12Studio.h"

T100WSTRING         T100City::Name          = L"City";
T100ENTITY_TYPE     T100City::Type          = T100ENTITY_CITY;

T100City::T100City() :
    T100Editable()
{
    //ctor
    init();
}

T100City::~T100City()
{
    //dtor
    uninit();
}

T100VOID T100City::init()
{
    T100Entity::Name    = L"City";
    T100Entity::Type    = T100ENTITY_CITY;


    Shader.INHERIT                  = T100FALSE;

    VertexShaderFile.TYPE           = T100SHADER_FILE_SOURCE;
    VertexShaderFile.FILE           = L"shader_mesh_simple_vert.hlsl";
    VertexShaderFile.ENTRY          = L"VSMain";
    VertexShaderFile.TARGET         = L"vs_5_1";

    PixelShaderFile.TYPE            = T100SHADER_FILE_SOURCE;
    PixelShaderFile.FILE            = L"shader_mesh_dynamic_indexing_pixel.hlsl";
    PixelShaderFile.ENTRY           = L"PSMain";
    PixelShaderFile.TARGET          = L"ps_5_1";

    MeshDataFile                    = L"occcity.bin";

    m_bundle.USED                   = T100TRUE;
    m_bundle.AMOUNT.X               = CityColumnCount;
    m_bundle.AMOUNT.Z               = CityRowCount;
    m_bundle.SPACING.X              = 16;
    m_bundle.SPACING.Y              = 16;
    m_bundle.SPACING.Z              = 16;
}

T100VOID T100City::uninit()
{

}

T100VOID T100City::Load(T100DX12Scene* scene)
{
    if(m_editable){
        m_selection = T100NEW T100City();
        m_selection->SetColour(255, 0, 0, 0);
        m_selection->Load(scene);
    }
}

T100DX12Model* T100City::Convert(T100DX12Studio* studio)
{
    T100DX12Model*      model           = T100NEW T100DX12Model();

    model->Type                         = T100DX12_MODEL_CITY;

    model->SetPosition(m_position);
    model->SetRotation(m_rotation);
    model->SetScaling(m_scaling);

    model->m_visible                    = m_visible;

    model->RenderType   = model->ConvertRenderType(m_renderType);
    model->MotionType   = model->ConvertMotionType(m_motionType);

    memcpy(&model->Bundle, &m_bundle, sizeof(T100BUNDLE));

    studio->GetScene()->CompileShaderFile(VertexShaderFile.FILE, VertexShaderFile.ENTRY, VertexShaderFile.TARGET, model->vertexShader);
    studio->GetScene()->CompileShaderFile1(PixelShaderFile.FILE, PixelShaderFile.ENTRY, PixelShaderFile.TARGET, model->pixelShader);

    studio->GetScene()->LoadMeshFile(MeshDataFile, &model->pMeshData, &model->MeshDataLength);

    m_model     = model;

    if(m_editable){
        m_model->m_selection    = m_selection->Convert(studio);
        m_model->m_editable     = T100TRUE;
    }

    return model;
}

T100VOID T100City::ToJSON(JSON& json)
{
    EntityToJSON(json);
}

T100VOID T100City::FromJSON(JSON& json)
{
    EntityFromJSON(json);
}
