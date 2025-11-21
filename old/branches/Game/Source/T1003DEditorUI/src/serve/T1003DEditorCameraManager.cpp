#include "T1003DEditorCameraManager.h"

#include <wx/wx.h>

T1003DEditorCameraManager::T1003DEditorCameraManager()
{
    //ctor
    init();
}

T1003DEditorCameraManager::~T1003DEditorCameraManager()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorCameraManager::init()
{
    m_cameraCount   = 0;
}

T100VOID T1003DEditorCameraManager::uninit()
{

}

T100Camera* T1003DEditorCameraManager::GetCamera()
{
    T100Camera*     camera      = T100NEW T100Camera();
    int     i       = ++m_cameraCount;
    camera->Name    = wxString::Format(L"Camera%u", i);
    return camera;
}
