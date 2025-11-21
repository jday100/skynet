#include "entity/T100Triangle.h"

#include "link/T100Instance.h"

T100WSTRING         T100Triangle::Name          = L"Triangle";
T100UINT            T100Triangle::Type          = T100ENTITY_TRIANGLE;

T100Triangle::T100Triangle() :
    T100Entity()
{
    //ctor
    init();
}

T100Triangle::~T100Triangle()
{
    //dtor
    uninit();
}

T100VOID T100Triangle::init()
{
    T100Entity::Name        = L"Triangle";
    T100Entity::Type        = T100ENTITY_TRIANGLE;

    VertexShaderFile.FILE   = L"entity/triangle.hlsl";
    VertexShaderFile.ENTRY  = L"VSMain";
    VertexShaderFile.TARGET = L"vs_5_0";

    PixelShaderFile.FILE    = L"entity/triangle.hlsl";
    PixelShaderFile.ENTRY   = L"PSMain";
    PixelShaderFile.TARGET  = L"ps_5_0";
}

T100VOID T100Triangle::uninit()
{

}

T100VOID T100Triangle::Load()
{
    VertexDescription       = T100NEW T100D3D12_INPUT_ELEMENT_DESC[2];

    VertexDescription[0]    = { "POSITION", 0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
    VertexDescription[1]    = { "COLOR",   0, T100DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

    VertexDescriptionLength = 2;

    Vertex* vertex          = T100NEW Vertex[3];

    vertex[0]   = {{0.0f, 0.5f, 0.0f},   {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[1]   = {{0.5f, -0.5f, 0.0f},  {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    vertex[2]   = {{-0.5f, -0.5f, 0.0f}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};

    VertexData.DATA_PTR     = (T100BYTE*)vertex;
    VertexData.LENGTH       = sizeof(Vertex) * 3;
    VertexData.STRIDE       = sizeof(Vertex);

    m_amount                = 3;

    if(m_editable){
        T100Triangle*   triangle    = T100NEW T100Triangle();
        m_selectionPtr  = triangle;

        triangle->SetColour(1, 0, 0, 0);
    }
}

T100VOID T100Triangle::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T100Triangle::SetRotation(T100Vector3f& value)
{
    m_rotation  = value;
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T100Triangle::ToJSON(JSON& json)
{

}

T100VOID T100Triangle::FromJSON(JSON& json)
{

}
