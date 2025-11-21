#include "T100Dot.h"

#include "T100Unicode.h"
#include "T100DX12Studio.h"
#include "T100DX12Model.h"

T100ENTITY_TYPE         T100Dot::Type           = T100ENTITY_DOT;
T100WSTRING             T100Dot::Name           = L"Dot";

T100Dot::T100Dot() :
    T100Editable()
{
    //ctor
    init();
}

T100Dot::~T100Dot()
{
    //dtor
    uninit();
}

T100VOID T100Dot::init()
{
    T100Entity::Name    = L"Dot";
    T100Entity::Type    = T100ENTITY_DOT;

    Shader.INHERIT                  = T100FALSE;

    VertexShaderFile.TYPE           = T100SHADER_FILE_SOURCE;
    VertexShaderFile.FILE           = L"entity/dot.hlsl";
    VertexShaderFile.ENTRY          = L"VSMain";
    VertexShaderFile.TARGET         = L"vs_5_0";

    PixelShaderFile.TYPE            = T100SHADER_FILE_SOURCE;
    PixelShaderFile.FILE            = L"entity/dot.hlsl";
    PixelShaderFile.ENTRY           = L"PSMain";
    PixelShaderFile.TARGET          = L"ps_5_0";
}

T100VOID T100Dot::uninit()
{

}

T100VOID T100Dot::Load(T100DX12Scene* scene)
{
    vertex  = {{0.0f, 0.0f, 0.0f},{m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    Length  = sizeof(Vertex);

    if(m_editable){
        m_selection = T100NEW T100Dot();
        m_selection->SetColour(255, 0, 0, 0);
        m_selection->Load(scene);
    }
}

T100DX12Model* T100Dot::Convert(T100DX12Studio* studio)
{
    T100DX12Model*      model   = T100NEW T100DX12Model();

    model->Type         = T100DX12_MODEL_DOT;

    model->SetPosition(m_position);
    model->SetRotation(m_rotation);
    model->SetScaling(m_scaling);

    model->m_visible    = m_visible;

    model->vertex       = &vertex;
    model->Length       = Length;

    studio->m_scene_manager.GetScene()->CompileShaderFile(VertexShaderFile.FILE, VertexShaderFile.ENTRY, VertexShaderFile.TARGET, model->vertexShader);
    studio->m_scene_manager.GetScene()->CompileShaderFile(PixelShaderFile.FILE, PixelShaderFile.ENTRY, PixelShaderFile.TARGET, model->pixelShader);

    model->m_numIndices = 1;
    Convert(&model->VertexDescriptions, &model->VertexDescriptionsLength);

    model->RenderType   = model->ConvertRenderType(m_renderType);
    model->MotionType   = model->ConvertMotionType(m_motionType);

    memcpy(&model->Bundle, &m_bundle, sizeof(T100BUNDLE));

    m_model     = model;

    if(m_editable){
        m_model->m_selection    = m_selection->Convert(studio);
        m_model->m_editable     = T100TRUE;
    }

    return model;
}

T100VOID T100Dot::ToJSON(JSON& json)
{
    EntityToJSON(json);
}

T100VOID T100Dot::FromJSON(JSON& json)
{
    EntityFromJSON(json);
}

T100VOID T100Dot::Convert(D3D12_INPUT_ELEMENT_DESC** ppDesc, T100UINT* pLength)
{
    *ppDesc         = T100NEW D3D12_INPUT_ELEMENT_DESC[2];
    *pLength        = 2;

    (*ppDesc)[0]    = {
        "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
    };
    (*ppDesc)[1]    = {
        "COLOR",   0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
    };
}
