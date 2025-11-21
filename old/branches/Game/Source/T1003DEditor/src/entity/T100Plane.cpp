#include "T100Plane.h"

#include "T100Unicode.h"
#include "T100DX12Studio.h"
#include "T100DX12Model.h"

T100ENTITY_TYPE         T100Plane::Type         = T100ENTITY_PLANE;
T100WSTRING             T100Plane::Name         = L"Plane";

T100Plane::T100Plane() :
    T100Editable()
{
    //ctor
    init();
}

T100Plane::~T100Plane()
{
    //dtor
    uninit();
}

T100VOID T100Plane::init()
{
    T100Entity::Name    = L"Plane";
    T100Entity::Type    = T100ENTITY_PLANE;
}

T100VOID T100Plane::uninit()
{

}

T100VOID T100Plane::Load(T100DX12Scene* scene)
{
    vertex      = T100NEW Vertex[4];

    vertex[0]   = {{-1.0f, 1.0f, 0.0f},{m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[1]   = {{1.0f, 1.0f, 0.0f},{m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[2]   = {{-1.0f, -1.0f, 0.0f},{m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[3]   = {{1.0f, -1.0f, 0.0f},{m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    Length      = sizeof(Vertex) * 4;

    if(m_editable){
        m_selection = T100NEW T100Plane();
        m_selection->SetColour(255, 0, 0, 0);
        m_selection->Load(scene);
    }
}

T100DX12Model* T100Plane::Convert(T100DX12Studio* studio)
{
    T100DX12Model*      model   = T100NEW T100DX12Model();

    model->Type         = T100DX12_MODEL_PLANE;

    model->SetPosition(m_position);
    model->SetRotation(m_rotation);
    model->SetScaling(m_scaling);

    model->m_visible    = m_visible;

    model->vertex       = vertex;
    model->Length       = Length;

    studio->m_scene_manager.GetScene()->CompileShaderFile(file, vertexName, vertexID, model->vertexShader);
    studio->m_scene_manager.GetScene()->CompileShaderFile(file, pixelName, pixelID, model->pixelShader);

    //model->VertexDescriptions           = const_cast<D3D12_INPUT_ELEMENT_DESC*>((D3D12_INPUT_ELEMENT_DESC*)StandardVertexDescription);


    model->VertexDescriptions           = T100NEW D3D12_INPUT_ELEMENT_DESC[2];

    T100WSTRING             name1       = StandardVertexDescription[0].SemanticName;
    model->VertexDescriptions[0]        = {
        T100Unicode::to_string8(name1).c_str(),
        0,
        model->ConvertFormat(StandardVertexDescription[0].Format),
        0,
        0,
        model->ConvertInputSlotClass(StandardVertexDescription[0].InputSlotClass),
        0
    };

    T100WSTRING             name2       = StandardVertexDescription[1].SemanticName;
    model->VertexDescriptions[1]        = {
        T100Unicode::to_string8(name2).c_str(),
        0,
        model->ConvertFormat(StandardVertexDescription[1].Format),
        0,
        12,
        model->ConvertInputSlotClass(StandardVertexDescription[1].InputSlotClass),
        0
    };

    model->VertexDescriptions       = T100NEW D3D12_INPUT_ELEMENT_DESC[2];

    model->VertexDescriptions[0]       = {
        "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
    };
    model->VertexDescriptions[1]       = {
        "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
    };

    model->VertexDescriptionsLength     = StandardVertexDescriptionNumElements;
    model->m_numIndices = 4;

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

T100VOID T100Plane::ToJSON(JSON& json)
{
    EntityToJSON(json);
}

T100VOID T100Plane::FromJSON(JSON& json)
{
    EntityFromJSON(json);
}
