#include "T1003DEditorDirection.h"

#include "T100VectorTools.h"

T1003DEditorDirection::T1003DEditorDirection()
{
    //ctor
    init();
}

T1003DEditorDirection::~T1003DEditorDirection()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorDirection::init()
{
    m_arrowX        = T100NEW T1003DEditorArrow();
    m_arrowY        = T100NEW T1003DEditorArrow();
    m_arrowZ        = T100NEW T1003DEditorArrow();

    m_arrowX->SetPosition(-0.9, -0.9, 0);
    m_arrowY->SetPosition(-0.9, -0.9, 0);
    m_arrowZ->SetPosition(-0.9, -0.9, 0);
    m_arrowY->SetRotation(0, 0, T100_PIDIV2);
    m_arrowZ->SetRotation(T100_PIDIV4, 0, T100_PIDIV4);

    m_arrows.push_back(m_arrowX);
    m_arrows.push_back(m_arrowY);
    m_arrows.push_back(m_arrowZ);
}

T100VOID T1003DEditorDirection::uninit()
{

}

T100VOID T1003DEditorDirection::Load(T100DX12Scene* scene)
{
    for(T1003DEditorArrow* arrow : m_arrows){
        arrow->Load(scene);
    }
}

T100VOID T1003DEditorDirection::SetLength(T100FLOAT length)
{
    for(T1003DEditorArrow* arrow : m_arrows){
        arrow->SetLength(length);
    }
}

T100VOID T1003DEditorDirection::SetColour(T100FLOAT r, T100FLOAT g, T100FLOAT b, T100FLOAT a)
{
    for(T1003DEditorArrow* arrow : m_arrows){
        arrow->SetColour(r, g, b, a);
    }
}

T100VOID T1003DEditorDirection::SetColour(T100Vector4u value)
{
    SetColour(value.RED, value.GREEN, value.BLUE, value.ALPHA);
}

T100VOID T1003DEditorDirection::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    T100Vector3     rotation(x, y, z);

    SetRotation(rotation);
}

T100VOID T1003DEditorDirection::SetRotation(T100Vector3 rotation)
{
    m_arrowX->SetRotation(rotation);
    m_arrowY->SetRotation(rotation);
    m_arrowZ->SetRotation(rotation);
}

T100VOID T1003DEditorDirection::SetPosition(T100UINT x, T100UINT y)
{
    m_arrowX->SetPosition(x, y, 0);
    m_arrowY->SetPosition(x, y, 0);
    m_arrowZ->SetPosition(x, y, 0);
}
