#include "entity/T100Plane.h"

#include "link/T100Instance.h"

T100WSTRING         T100Plane::Name         = L"Plane";
T100UINT            T100Plane::Type         = T100ENTITY_PLANE;

T100Plane::T100Plane() :
    T100Entity()
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
    T100Entity::Name        = L"Plane";
    T100Entity::Type        = T100ENTITY_PLANE;

    VertexShaderFile.FILE   = L"entity/plane.hlsl";
    VertexShaderFile.ENTRY  = L"VSMain";
    VertexShaderFile.TARGET = L"vs_5_0";

    PixelShaderFile.FILE    = L"entity/plane.hlsl";
    PixelShaderFile.ENTRY   = L"PSMain";
    PixelShaderFile.TARGET  = L"ps_5_0";
}

T100VOID T100Plane::uninit()
{

}

T100VOID T100Plane::Load()
{
    VertexDescription       = T100NEW T100D3D12_INPUT_ELEMENT_DESC[2];

    VertexDescription[0]    = { "POSITION", 0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
    VertexDescription[1]    = { "COLOR",   0, T100DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

    VertexDescriptionLength = 2;

    Vertex* vertex          = T100NEW Vertex[4];

    vertex[0]   = {{-0.5f, 0.5f, 0.0f},  {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[1]   = {{0.5f,  0.5f, 0.0f},  {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[2]   = {{-0.5f, -0.5f, 0.0f}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[3]   = {{0.5f,  -0.5f, 0.0f}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};

    VertexData.DATA_PTR     = (T100BYTE*)vertex;
    VertexData.LENGTH       = sizeof(Vertex) * 4;
    VertexData.STRIDE       = sizeof(Vertex);

    m_amount                = 4;

    if(m_editable){
        T100Plane*  plane   = T100NEW T100Plane();
        m_selectionPtr      = plane;

        plane->SetColour(1, 0, 0, 0);
    }
}

T100VOID T100Plane::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T100Plane::SetRotation(T100Vector3f& value)
{
    m_rotation  = value;
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T100Plane::ToJSON(JSON& json)
{

}

T100VOID T100Plane::FromJSON(JSON& json)
{

}
