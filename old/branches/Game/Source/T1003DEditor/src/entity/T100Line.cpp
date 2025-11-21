#include "T100Line.h"

#include "T100DX12Studio.h"
#include "T100DX12Model.h"
#include "T100VectorTools.h"

T100WSTRING         T100Line::Name          = L"Line";
T100ENTITY_TYPE     T100Line::Type          = T100ENTITY_LINE;

T100Line::T100Line() :
    T100Editable()
{
    //ctor
    init();
}

T100Line::~T100Line()
{
    //dtor
    uninit();
}

T100VOID T100Line::init()
{
    T100Entity::Name    = L"Line";
    T100Entity::Type    = T100ENTITY_LINE;

    m_renderType        = T100_RENDER_3D;
    m_motionType        = T100_MOTION_MOVE;

    Shader.INHERIT                  = T100FALSE;

    VertexShaderFile.TYPE           = T100SHADER_FILE_SOURCE;
    VertexShaderFile.FILE           = L"entity/line.hlsl";
    VertexShaderFile.ENTRY          = L"VSMain";
    VertexShaderFile.TARGET         = L"vs_5_0";

    PixelShaderFile.TYPE            = T100SHADER_FILE_SOURCE;
    PixelShaderFile.FILE            = L"entity/line.hlsl";
    PixelShaderFile.ENTRY           = L"PSMain";
    PixelShaderFile.TARGET          = L"ps_5_0";
}

T100VOID T100Line::uninit()
{

}

T100VOID T100Line::Load(T100DX12Scene* scene)
{
    vertex = T100NEW Vertex[2];

    T100Vector3     head;
    T100Vector3     tail;

    if(m_renderType == T100_RENDER_2D){
        T100FLOAT   x;

        scene->Convert(m_terminus.X, x);

        if(m_motionType == T100_MOTION_STILL){
            T100Vector3     value(x, 0, 0);
            Transition2D(value, tail);
        }else{
            tail.X      = x;
            tail.Y      = 0;
            tail.Z      = 0;
        }

        if(m_length == -1){
            tail.X      = scene->GetWidth();
            tail.Y      = 0;
            tail.Z      = 0;
        }
    }else{
        head    = m_origin;
        tail    = m_terminus;

        if(m_length > 0){
            tail.X  = m_length;
            tail.Y  = 0;
            tail.Z  = 0;

            m_terminus  = tail;
        }
    }

    vertex[0]   = {{head.X, head.Y, head.Z}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[1]   = {{tail.X, tail.Y, tail.Z}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};

    Length      = sizeof(Vertex) * 2;

    if(m_editable){
        m_selection = T100NEW T100Line();
        m_selection->SetColour(255, 0, 0, 0);
        m_selection->Load(scene);
    }
}

T100DX12Model* T100Line::Convert(T100DX12Studio* studio)
{
    T100DX12Model*      model           = T100NEW T100DX12Model();

    model->Type                         = T100DX12_MODEL_LINE;

    model->SetPosition(m_position);
    model->SetRotation(m_rotation);
    model->SetScaling(m_scaling);
    model->SetVisible(m_visible);

    model->vertex                       = vertex;
    model->Length                       = Length;

    studio->GetScene()->CompileShaderFile(VertexShaderFile.FILE, VertexShaderFile.ENTRY, VertexShaderFile.TARGET, model->vertexShader);
    studio->GetScene()->CompileShaderFile(PixelShaderFile.FILE, PixelShaderFile.ENTRY, PixelShaderFile.TARGET, model->pixelShader);

    model->m_numIndices                 = 2;
    Convert(&model->VertexDescriptions, &model->VertexDescriptionsLength);

    model->RenderType                   = model->ConvertRenderType(m_renderType);
    model->MotionType                   = model->ConvertMotionType(m_motionType);

    memcpy(&model->Bundle, &m_bundle, sizeof(T100BUNDLE));

    m_model     = model;

    if(m_editable){
        m_model->m_selection    = m_selection->Convert(studio);
        m_model->m_editable     = T100TRUE;
    }

    return model;
}

T100VOID T100Line::SetTerminus(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_terminus  = {x, y, z};
}

T100VOID T100Line::SetTerminus(T100Vector3 value)
{
    m_terminus  = value;
}

T100Vector3 T100Line::GetTerminus()
{
    return m_terminus;
}

T100VOID T100Line::ToJSON(JSON& json)
{
    EntityToJSON(json);
    json["length"]      = m_length;
    json["terminus"]    = m_terminus.FLOAT3;
}

T100VOID T100Line::FromJSON(JSON& json)
{
    EntityFromJSON(json);
    m_length    = json["length"];
    json["terminus"].get_to(m_terminus.FLOAT3);
}

T100VOID T100Line::SetLength(T100FLOAT length)
{
    m_length    = length;
}

T100FLOAT T100Line::GetLength()
{
    return m_length;
}

T100VOID T100Line::Convert(D3D12_INPUT_ELEMENT_DESC** ppDesc, T100UINT* pLength)
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
