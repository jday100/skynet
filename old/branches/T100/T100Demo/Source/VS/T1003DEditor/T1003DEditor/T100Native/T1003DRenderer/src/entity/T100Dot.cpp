#include "entity/T100Dot.h"

#include "link/T100Instance.h"

T100WSTRING         T100Dot::Name           = L"Dot";
T100UINT            T100Dot::Type           = T100ENTITY_DOT;

T100Dot::T100Dot() :
    T100Entity()
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
    T100Entity::Name        = L"Dot";
    T100Entity::Type        = T100ENTITY_DOT;

    VertexShaderFile.FILE   = L"entity/dot.hlsl";
    VertexShaderFile.ENTRY  = L"VSMain";
    VertexShaderFile.TARGET = L"vs_5_0";

    PixelShaderFile.FILE    = L"entity/dot.hlsl";
    PixelShaderFile.ENTRY   = L"PSMain";
    PixelShaderFile.TARGET  = L"ps_5_0";
}

T100VOID T100Dot::uninit()
{

}

T100VOID T100Dot::Load()
{
    VertexDescription       = T100NEW T100D3D12_INPUT_ELEMENT_DESC[2];

    VertexDescription[0]    = { "POSITION", 0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
    VertexDescription[1]    = { "COLOR",   0, T100DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

    VertexDescriptionLength = 2;

    Vertex* vertex          = T100NEW Vertex[1];

    vertex[0]   = {{0.0f, 0.0f, 0.0f}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};

    VertexData.DATA_PTR     = (T100BYTE*)vertex;
    VertexData.LENGTH       = sizeof(Vertex);
    VertexData.STRIDE       = sizeof(Vertex);

    m_amount                = 1;

    if(m_editable){
        T100Dot*    dot     = T100NEW T100Dot();
        m_selectionPtr      = dot;

        dot->SetColour(1, 0, 0, 0);
    }
}

T100VOID T100Dot::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T100Dot::SetRotation(T100Vector3f& value)
{
    m_rotation  = value;
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T100Dot::ToJSON(JSON& json)
{

}

T100VOID T100Dot::FromJSON(JSON& json)
{

}
