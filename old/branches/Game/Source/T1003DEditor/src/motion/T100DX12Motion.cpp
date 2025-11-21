#include "T100DX12Motion.h"

T100DX12Motion::T100DX12Motion()
{
    //ctor
}

T100DX12Motion::~T100DX12Motion()
{
    //dtor
}

T100VOID T100DX12Motion::SetCameraPtr(T100DX12Camera* camera)
{
    m_cameraPtr = camera;
}

T100DX12Camera* T100DX12Motion::GetCameraPtr()
{
    return m_cameraPtr;
}

T100VOID T100DX12Motion::Forward()
{
    T100Vector3 position  = m_cameraPtr->GetPosition();

    position.Z  += m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100DX12Motion::Backward()
{
    T100Vector3 position  = m_cameraPtr->GetPosition();

    position.Z  -= m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100DX12Motion::MoveLeft()
{
    T100Vector3 position  = m_cameraPtr->GetPosition();

    position.X  -= m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100DX12Motion::MoveRight()
{
    T100Vector3 position  = m_cameraPtr->GetPosition();

    position.X  += m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100DX12Motion::MoveUp()
{
    T100Vector3 position  = m_cameraPtr->GetPosition();

    position.Y  += m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100DX12Motion::MoveDown()
{
    T100Vector3 position  = m_cameraPtr->GetPosition();

    position.Y  -= m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100DX12Motion::LookUp()
{
    T100Vector3 rotation  = m_cameraPtr->GetRotation();

    rotation.X  += m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100DX12Motion::LookDown()
{
    T100Vector3 rotation  = m_cameraPtr->GetRotation();

    rotation.X  -= m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100DX12Motion::TurnLeft()
{
    T100Vector3 rotation  = m_cameraPtr->GetRotation();

    rotation.Y  += m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100DX12Motion::TurnRight()
{
    T100Vector3 rotation  = m_cameraPtr->GetRotation();

    rotation.Y  -= m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100DX12Motion::LeftHead()
{
    T100Vector3 rotation  = m_cameraPtr->GetRotation();

    rotation.Z  += m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100DX12Motion::RightHead()
{
    T100Vector3 rotation  = m_cameraPtr->GetRotation();

    rotation.Z  -= m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100DX12Motion::Reset()
{
    m_cameraPtr->Reset();
}
