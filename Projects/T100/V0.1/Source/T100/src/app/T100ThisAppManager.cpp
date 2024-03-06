#include "T100ThisAppManager.h"

#include "T100Log.h"
#include "T100LogFile.h"
#include "T100LogConsole.h"
#include "T100AppTest.h"

#include "T100ThisAppCommon.h"
#include "T100ThisAppCmdLineParser.h"
#include "T100ThisAppHelp.h"

#include "T100Main.h"
#include "T100FontApp.h"
#include "T100VPCApp.h"
#include "T100VDiskConsoleApp.h"
#include "T100AssemblyApp.h"
#include "T100ProjectApp.h"
#include "T100EditorApp.h"
#include "T100PainterApp.h"
#include "T100IDEApp.h"


T100ThisAppManager::T100ThisAppManager()
    :T100WxWidgets::T100WxAppManager(),
    m_info()
{
    //ctor
    create();
}

T100ThisAppManager::~T100ThisAppManager()
{
    //dtor
    destroy();
}

T100VOID T100ThisAppManager::create()
{

}

T100VOID T100ThisAppManager::destroy()
{

}

T100BOOL T100ThisAppManager::start()
{
    T100BOOL        result;

    T100Library::T100Log::append(T100NEW T100Library::T100LogConsole());
    T100Library::T100Log::start();

    m_frame = T100NEW T100Frame(0);

    if(m_info.HELP){
        T100ThisAppHelp     help;

        help.show();
        return quit();
    }

    if(m_info.TEST){
        m_info.RUNNING      = T100TRUE;

        T100AppTest         test(this);

        if(m_info.UNIT){
            test.unit(m_info.NAME);
        }else if(m_info.LIST){
            test.list();
        }else{
            test.run();
        }
    }

    if(m_info.EDITOR){
        m_info.RUNNING      = T100TRUE;

        m_editor    = T100NEW T100Editor::T100EditorApp(this, m_info.QUIT);
        m_editor->show();
    }

    if(m_info.PROJECT){
        m_info.RUNNING      = T100TRUE;

        m_project   = T100NEW T100PROJECT::T100ProjectApp(this, m_info.QUIT);
        m_project->show();
    }

    if(m_info.PAINTER){
        m_info.RUNNING      = T100TRUE;

        m_painter   = T100NEW T100Painter::T100PainterApp(this, m_info.QUIT);
        m_painter->show();
    }

    if(m_info.IDE){
        m_info.RUNNING      = T100TRUE;

        m_ide       = T100NEW T100IDE::T100IDEApp(this, m_info.QUIT);
        m_ide->show();
    }

    if(m_info.FONT){
        m_info.RUNNING      = T100TRUE;

        m_font = T100NEW T100FontBuilder::T100FontApp(this, m_info.QUIT);
        m_font->show();
    }

    if(m_info.VDISK){
        m_info.RUNNING      = T100TRUE;

        m_vdisk = T100NEW T100VDisk::T100VDiskConsoleApp(this, m_info.QUIT);
        m_vdisk->run();
    }

    if(m_info.ASSEMBLY){
        m_info.RUNNING      = T100TRUE;

        m_assembly  = T100NEW T100Assembly::T100AssemblyApp(this);
        result      = m_assembly->run(m_info);
    }

    if(m_info.VPC){
        m_info.RUNNING      = T100TRUE;

        m_vpc = T100NEW T100VPC::T100VPCApp(this, m_info.QUIT);
        m_vpc->show();
    }

    if(!m_info.RUNNING){
        quit();
    }

    return T100TRUE;
}

T100BOOL T100ThisAppManager::stop()
{
    T100Library::T100Log::stop();
    return T100TRUE;
}

T100BOOL T100ThisAppManager::parse(int& argc, wxChar** argv)
{
    T100ThisAppCmdLineParser    cmd;

    return cmd.parse(argc, argv, m_info);
}

T100BOOL T100ThisAppManager::close(T100WORD id)
{
    switch(id){
    case T100APP_VPC:
        {
            T100SAFE_DELETE(m_vpc);
        }
        break;
    case T100APP_FONT_BUILDER:
        {
            T100SAFE_DELETE(m_font);
        }
        break;
    case T100APP_VDISK:
        {
            T100SAFE_DELETE(m_vdisk);
        }
        break;
    }

    quit();
}


T100IDE::T100IDEApp* T100ThisAppManager::getIDE()
{
    return m_ide;
}
