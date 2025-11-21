#include "link/T100CameraInstance.h"

T100CameraInstance::T100CameraInstance() :
    T100Instance()
{
    //ctor
}

T100CameraInstance::~T100CameraInstance()
{
    //dtor
}

T100VOID T100CameraInstance::SetSource(T1003DCamera* camera)
{
    m_source    = camera;
}

T1003DCamera* T100CameraInstance::GetSource()
{
    return m_source;
}

