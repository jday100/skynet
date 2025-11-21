#include "T100DX12Context.h"

#include <d3dcompiler.h>
#include "T100Debug.h"
#include "T100DX12Tools.h"
#include "T100DX12Studio.h"

T100DX12Context::T100DX12Context() :
    Type(T100DX12_MODEL_NONE),
    m_frameIndex(0)
{
    //ctor
}

T100DX12Context::~T100DX12Context()
{
    //dtor
}


T100VOID T100DX12Context::SetStudioPtr(T100DX12Studio* studioPtr)
{
    m_studioPtr     = studioPtr;
}

T100DX12Studio* T100DX12Context::GetStudioPtr()
{
    return m_studioPtr;
}

T100VOID T100DX12Context::SetFramePtr(T100DX12Frame* framePtr)
{
    m_framePtr  = framePtr;
}

T100DX12Frame* T100DX12Context::GetFramePtr()
{
    return m_framePtr;
}

T100VOID T100DX12Context::SetPosition(XMFLOAT3 value)
{
    m_position  = value;
}

T100VOID T100DX12Context::SetRotation(XMFLOAT3 value)
{
    m_rotation  = value;
}

T100VOID T100DX12Context::SetScaling(XMFLOAT3 value)
{
    m_scaling   = value;
}

T100VOID T100DX12Context::Append(T100UINT type, XMFLOAT3 value)
{
    T100DX12Event       event;

    event.Type      = type;
    event.Value     = value;

    m_events.push(event);
}

T100VOID T100DX12Context::Append(T100UINT type, T100BOOL value)
{
    T100DX12Event       event;

    event.Type              = type;
    event.Item.BoolValue    = value;

    m_events.push(event);
}

T100VOID T100DX12Context::Clear()
{
    T100DX12Event       event;

    event.Type      = T100DX12_CONTEXT_EVENT_REMOVE;
    event.Data      = this;

    m_visible       = T100FALSE;

    m_events.push(event);
}

T100VOID T100DX12Context::SetBundlePositions()
{
    UINT    m = 0;
    FLOAT   x = 0;
    for(UINT i = 0; i < Bundle.AMOUNT.X; i++)
    {
        FLOAT   y = 0;
        for(UINT j = 0; j < Bundle.AMOUNT.Y; j++)
        {
            FLOAT   z = 0;
            for(UINT k = 0; k < Bundle.AMOUNT.Z; k++)
            {
                XMStoreFloat4x4(&m_modelMatrices[m++], XMMatrixTranslation(x, y, z));
                z   += Bundle.SPACING.Z;
            }
            y   += Bundle.SPACING.Y;
        }
        x   += Bundle.SPACING.X;
    }
}

T100VOID T100DX12Context::DrawBundle()
{
    switch(Type){
    case T100ENTITY_DOT:
        {
            m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_POINTLIST);
        }
        break;
    case T100ENTITY_LINE:
        {
            m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINELIST);
        }
        break;
    case T100ENTITY_TRIANGLE:
        {
            m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        }
        break;
    /*
    case T100ENTITY_PLANE:
        {
            m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
        }
        break;
    */
    case T100ENTITY_CITY:
        {
            m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        }
        break;
    }
}

T100VOID T100DX12Context::UpdateBundle(XMMATRIX& projection, XMMATRIX& view)
{
    XMMATRIX        model;
    XMFLOAT4X4      mvp;
    UINT            m   = 0;

    XMMATRIX        item;
    XMMATRIX        temp;

    item    = BuildWorld();

    for (UINT i = 0; i < Bundle.AMOUNT.X; i++)
    {
        for (UINT j = 0; j < Bundle.AMOUNT.Y; j++)
        {
            for (UINT k = 0; k < Bundle.AMOUNT.Z; k++)
            {
                XMFLOAT4X4  value;

                value = m_modelMatrices[m];

                model = XMLoadFloat4x4(&value);

                //temp    = model * item;
                //temp    = item;
                //model   = XMMatrixTranslation(m_position.x, m_position.y, m_position.z);

                temp    = item * model;

                XMStoreFloat4x4(&mvp, XMMatrixTranspose(temp * view * projection));

                memcpy(&m_constantBuffersPtr[m], &mvp, sizeof(mvp));

                m++;
            }
        }
    }
}


XMMATRIX T100DX12Context::BuildWorld()
{
    XMMATRIX    result;
    XMMATRIX    position;
    XMMATRIX    rotationX;
    XMMATRIX    rotationY;
    XMMATRIX    rotationZ;
    XMMATRIX    scaling;

    position    = XMMatrixTranslation(m_position.x, m_position.y, m_position.z);
    rotationX   = XMMatrixRotationX(m_rotation.x);
    rotationY   = XMMatrixRotationY(m_rotation.y);
    rotationZ   = XMMatrixRotationZ(m_rotation.z);
    scaling     = XMMatrixScaling(m_scaling.x, m_scaling.y, m_scaling.z);

    result      = scaling * rotationX * rotationY * rotationZ * position;

    return result;
}
