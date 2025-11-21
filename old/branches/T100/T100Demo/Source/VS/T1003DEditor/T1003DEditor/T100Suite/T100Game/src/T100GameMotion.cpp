#include "T100GameMotion.h"

T100GameMotion::T100GameMotion()
{
    //ctor
}

T100GameMotion::~T100GameMotion()
{
    //dtor
}

T100VOID T100GameMotion::SetCameraPtr(T1003DCamera* camera)
{
    m_cameraPtr = camera;
}

T1003DCamera* T100GameMotion::GetCameraPtr()
{
    return m_cameraPtr;
}

T100VOID T100GameMotion::Forward()
{
    T100Vector3f& position  = m_cameraPtr->GetPosition();

    position.Z  += m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100GameMotion::Backward()
{
    T100Vector3f& position  = m_cameraPtr->GetPosition();

    position.Z  -= m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100GameMotion::MoveLeft()
{
    T100Vector3f& position  = m_cameraPtr->GetPosition();

    position.X  -= m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100GameMotion::MoveRight()
{
    T100Vector3f& position  = m_cameraPtr->GetPosition();

    position.X  += m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100GameMotion::MoveUp()
{
    T100Vector3f& position  = m_cameraPtr->GetPosition();

    position.Y  += m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100GameMotion::MoveDown()
{
    T100Vector3f& position  = m_cameraPtr->GetPosition();

    position.Y  -= m_step;

    m_cameraPtr->SetPosition(position);
}

T100VOID T100GameMotion::LookUp()
{
    T100Vector3f& rotation  = m_cameraPtr->GetRotation();

    rotation.X  += m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100GameMotion::LookDown()
{
    T100Vector3f& rotation  = m_cameraPtr->GetRotation();

    rotation.X  -= m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100GameMotion::TurnLeft()
{
    T100Vector3f& rotation  = m_cameraPtr->GetRotation();

    rotation.Y  += m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100GameMotion::TurnRight()
{
    T100Vector3f& rotation  = m_cameraPtr->GetRotation();

    rotation.Y  -= m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100GameMotion::LeftHead()
{
    T100Vector3f& rotation  = m_cameraPtr->GetRotation();

    rotation.Z  += m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100GameMotion::RightHead()
{
    T100Vector3f& rotation  = m_cameraPtr->GetRotation();

    rotation.Z  -= m_turn;

    m_cameraPtr->SetRotation(rotation);
}

T100VOID T100GameMotion::Reset()
{
    m_cameraPtr->Reset();
}
