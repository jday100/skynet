#include "T100ProjectApplication.h"

#include "T100AllExtensions.h"
#include "T100ProjectInvoking.h"

T100ProjectApplication::T100ProjectApplication() :
    T100Win32Application(),
    m_skeletal()
{
    //ctor
}

T100ProjectApplication::~T100ProjectApplication()
{
    //dtor
}

T100VOID T100ProjectApplication::init()
{
    T100ProjectApplicationExtension*        applicationExtension        = T100NEW T100ProjectApplicationExtension();

    m_skeletal.GetExtendedManager().SignIn(T100PROJECT_APPLICATION, applicationExtension);

    T100ProjectInvokingExtension*           invokingExtension           = T100NEW T100ProjectInvokingExtension();

    m_skeletal.GetExtendedManager().SignIn(T100PROJECT_INVOKING, invokingExtension);

    T100ProjectSkeletalExtension*           skeletalExtension           = T100NEW T100ProjectSkeletalExtension();

    m_skeletal.GetExtendedManager().SignIn(T100PROJECT_SKELETAL, skeletalExtension);

    T100ProjectViewExtension*               viewExtension               = T100NEW T100ProjectViewExtension();

    m_skeletal.GetExtendedManager().SignIn(T100PROJECT_VIEW, viewExtension);

    T100ProjectServeExtension*              serveExtension              = T100NEW T100ProjectServeExtension();

    m_skeletal.GetExtendedManager().SignIn(T100PROJECT_SERVE, serveExtension);

    T100ProjectStoreExtension*              storeExtension              = T100NEW T100ProjectStoreExtension();

    m_skeletal.GetExtendedManager().SignIn(T100PROJECT_STORE, storeExtension);

    T100ProjectPlatenExtension*             platenExtension             = T100NEW T100ProjectPlatenExtension();

    m_skeletal.GetExtendedManager().SignIn(T100PROJECT_VIEW_MAIN_PLATEN, platenExtension);

    T100MenuExtension*                      menuExtension               = T100NEW T100MenuExtension();

    m_skeletal.GetExtendedManager().SignIn(T100PROJECT_VIEW_MAIN_MENU, menuExtension);


    T100WindowExtension*        extension       = T100NEW T100WindowExtension();

    m_skeletal.GetExtendedManager().SignIn(T100PROJECT_VIEW_MAIN_FRAME_RESIZE, extension);
    m_skeletal.GetExtendedManager().Bind(T100PROJECT_VIEW_MAIN_FRAME_RESIZE, T100EVENT_WINDOW_SIZE, m_frame, (T100EVENT_FUNCTION)&OnResize, this);
}

T100VOID T100ProjectApplication::uninit()
{

}

T100VOID T100ProjectApplication::Create()
{
    T100Win32Application::Create();

    m_frame->Maximize();
    m_skeletal.GetView()->SetFrame(m_frame);

    T100ProjectInvoking::Create(this);

    init();

    m_skeletal.Launch();
}

T100VOID T100ProjectApplication::Destroy()
{
    T100ProjectInvoking::Destroy();
    uninit();
}

T100ProjectSkeletal& T100ProjectApplication::GetSkeletal()
{
    return m_skeletal;
}

T100VOID T100ProjectApplication::OnMenu(T100MenuEvent& event)
{
    T100ProjectInvoking::OnMainMenu(event);
}

T100VOID T100ProjectApplication::OnResize(T100WindowEvent& event)
{
    T100ProjectInvoking::OnResize(event);
}
