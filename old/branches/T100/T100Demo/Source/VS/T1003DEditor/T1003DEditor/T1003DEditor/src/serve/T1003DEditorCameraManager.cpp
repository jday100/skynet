#include "serve/T1003DEditorCameraManager.h"

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

T1003DCamera* T1003DEditorCameraManager::GetCamera()
{
    T1003DCamera*   camera      = T100NEW T1003DCamera();
    int     i       = ++m_cameraCount;
    camera->Name    = wxString::Format(L"Camera%u", i);
    return camera;
}
