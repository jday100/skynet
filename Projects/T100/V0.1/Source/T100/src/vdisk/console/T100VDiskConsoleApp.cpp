#include "T100VDiskConsoleApp.h"

#include "T100ThisAppCommon.h"
#include "T100App.h"
#include "T100Main.h"

#include "T100VDiskConsole.h"


namespace T100VDisk{

T100VDiskConsoleApp::T100VDiskConsoleApp(T100Library::T100AppManager* obj, T100BOOL quit)
    :T100Library::T100AppBase(obj, quit)
{
    //ctor
    create();
}

T100VDiskConsoleApp::~T100VDiskConsoleApp()
{
    //dtor
    destroy();
}

T100VOID T100VDiskConsoleApp::create()
{
    m_console = T100NEW T100VDiskConsole(this);
}

T100VOID T100VDiskConsoleApp::destroy()
{
    T100SAFE_DELETE(m_console);
}

T100BOOL T100VDiskConsoleApp::run()
{
    return m_console->run();
}

T100VOID T100VDiskConsoleApp::quit()
{

    wxThreadEvent   event(wxEVT_THREAD, T100Frame::ID_THREAD_CLOSE);

    event.SetInt(T100APP_VDISK);
    wxQueueEvent(wxGetApp().getManager()->getFrame(), event.Clone());

}

}
