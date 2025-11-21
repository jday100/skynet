#include "entity/T100Line.h"

#include "link/T100Instance.h"

T100WSTRING         T100Line::Name          = L"Line";
T100UINT            T100Line::Type          = T100ENTITY_LINE;

T100Line::T100Line() :
    T100Entity()
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
    T100Entity::Name        = L"Line";
    T100Entity::Type        = T100ENTITY_LINE;

    VertexShaderFile.FILE   = L"entity/line.hlsl";
    VertexShaderFile.ENTRY  = L"VSMain";
    VertexShaderFile.TARGET = L"vs_5_0";

    PixelShaderFile.FILE    = L"entity/line.hlsl";
    PixelShaderFile.ENTRY   = L"PSMain";
    PixelShaderFile.TARGET  = L"ps_5_0";
}

T100VOID T100Line::uninit()
{

}

T100VOID T100Line::Load()
{
    VertexDescription   = T100NEW T100D3D12_INPUT_ELEMENT_DESC[2];

    VertexDescription[0]    = { "POSITION", 0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
    VertexDescription[1]    = { "COLOR",   0, T100DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };

    VertexDescriptionLength = 2;

    Vertex* vertex          = T100NEW Vertex[2];

    vertex[0]   = {{0.0f, 0.0f, 0.0f}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    if(m_length == 0){
        vertex[1]   = {{m_terminus.X, m_terminus.Y, m_terminus.Z}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    }else{
        vertex[1]   = {{m_length, 0.0f, 0.0f}, {m_colour.RED, m_colour.GREEN, m_colour.BLUE, m_colour.ALPHA}};
    }


    VertexData.DATA_PTR     = (T100BYTE*)vertex;
    VertexData.LENGTH       = sizeof(Vertex) * 2;
    VertexData.STRIDE       = sizeof(Vertex);

    m_amount                = 2;

    if(m_editable){
        T100Line*   line    = T100NEW T100Line();
        m_selectionPtr      = line;

        line->SetLength(m_length);
        line->SetColour(1, 0, 0, 0);
    }
}

T100VOID T100Line::SetLength(T100FLOAT length)
{
    m_length    = length;
    //m_terminus  = {length, 0, 0};
}

T100FLOAT T100Line::GetLength()
{
    //return m_length;
    if(m_length == 0){
        return m_terminus.Norm();
    }
    return m_length;
}

T100VOID T100Line::SetTerminus(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_terminus  = {x, y, z};
    //m_length    = m_terminus.Norm();
}

T100VOID T100Line::SetTerminus(T100Vector3f value)
{
    m_terminus  = value;
    //m_length    = m_terminus.Norm();
}

T100Vector3f T100Line::GetTerminus()
{
    return m_terminus;
}

T100VOID T100Line::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T100Line::SetRotation(T100Vector3f& value)
{
    m_rotation  = value;
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T100Line::ToJSON(JSON& json)
{

}

T100VOID T100Line::FromJSON(JSON& json)
{

}
