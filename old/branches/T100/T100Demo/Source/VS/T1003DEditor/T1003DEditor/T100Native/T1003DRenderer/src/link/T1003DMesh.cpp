#include "link/T1003DMesh.h"

#include "link/T100MeshInstance.h"

T1003DMesh::T1003DMesh(T1003D_RENDER_TYPE render, T1003D_MOTION_TYPE motion) :
    T100Editable(),
    m_bundle({T100FALSE, {}, {}}),
    m_renderType(render),
    m_motionType(motion),
    m_scaling({1, 1, 1})
{
    //ctor
}

T1003DMesh::~T1003DMesh()
{
    //dtor
}

T100VOID T1003DMesh::SetBundle(T100BOOL flag)
{
    m_bundle.USED   = flag;
}

T100BOOL T1003DMesh::IsBundle()
{
    return m_bundle.USED;
}

T100BUNDLE* T1003DMesh::GetBundlePtr()
{
    return &m_bundle;
}

T100VOID T1003DMesh::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetPosition(m_position);
    }
    if(m_editable){
        m_selectionPtr->SetPosition(m_position);
    }
}

T100VOID T1003DMesh::SetPosition(T100Vector3f& value)
{
    m_position  = value;
    if(m_instancePtr){
        m_instancePtr->SetPosition(m_position);
    }
    if(m_editable){
        m_selectionPtr->SetPosition(m_position);
    }
}

T100VOID T1003DMesh::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T1003DMesh::SetRotation(T100Vector3f& value)
{
    m_rotation  = value;
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T1003DMesh::SetScaling(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_scaling   = {x, y, z};
    if(m_instancePtr){
        T100MeshInstance*   instance = dynamic_cast<T100MeshInstance*>(m_instancePtr);

        if(instance){
            instance->SetScaling(m_scaling);
        }
    }
}

T100VOID T1003DMesh::SetScaling(T100Vector3f& value)
{
    m_scaling   = value;
    if(m_instancePtr){
        T100MeshInstance*   instance = dynamic_cast<T100MeshInstance*>(m_instancePtr);

        if(instance){
            instance->SetScaling(m_scaling);
        }
    }
}

T100Vector3f& T1003DMesh::GetScaling()
{
    return m_scaling;
}

T100VOID T1003DMesh::SetBundleAmount(T100Vector3u& value)
{
    m_bundle.AMOUNT.X   = value.X;
    m_bundle.AMOUNT.Y   = value.Y;
    m_bundle.AMOUNT.Z   = value.Z;
}

T100Vector3u T1003DMesh::GetBundleAmount()
{
    return T100Vector3u(m_bundle.AMOUNT.X, m_bundle.AMOUNT.Y, m_bundle.AMOUNT.Z);
}

T100VOID T1003DMesh::SetBundleSpacing(T100Vector3f& value)
{
    m_bundle.SPACING.X      = value.X;
    m_bundle.SPACING.Y      = value.Y;
    m_bundle.SPACING.Z      = value.Z;
}

T100Vector3f T1003DMesh::GetBundleSpacing()
{
    return T100Vector3f(m_bundle.SPACING.X, m_bundle.SPACING.Y, m_bundle.SPACING.Z);
}

T100VOID T1003DMesh::SetRenderType(T1003D_RENDER_TYPE type)
{
    m_renderType    = type;
}

T1003D_RENDER_TYPE T1003DMesh::GetRenderType()
{
    return m_renderType;
}

T100VOID T1003DMesh::SetMotionType(T1003D_MOTION_TYPE type)
{
    m_motionType    = type;
}

T1003D_MOTION_TYPE T1003DMesh::GetMotionType()
{
    return m_motionType;
}

T100VOID T1003DMesh::SetVisible(T100BOOL flag)
{
    m_visible   = flag;
    if(m_instancePtr){
        T100MeshInstance*   instance = dynamic_cast<T100MeshInstance*>(m_instancePtr);

        if(instance){
            instance->SetVisible(m_visible);
        }
    }
}

T100BOOL T1003DMesh::IsVisible()
{
    return m_visible;
}

T1003DMesh* T1003DMesh::GetSelectionPtr()
{
    return dynamic_cast<T1003DMesh*>(m_selectionPtr);
}

T100VOID T1003DMesh::SetAmount(T100UINT value)
{
    m_amount    = value;
}

T100UINT T1003DMesh::GetAmount()
{
    return m_amount;
}
