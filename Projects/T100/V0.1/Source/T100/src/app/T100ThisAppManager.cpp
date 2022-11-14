#include "T100ThisAppManager.h"

#include "T100Log.h"
#include "T100LogFile.h"
#include "T100LogConsole.h"
#include "T100AppTest.h"

#include "T100ThisAppCmdLineParser.h"

#include "T100FontApp.h"
#include "T100VPCApp.h"
#include "T100VDiskConsole.h"
#include "T100Assembly.h"


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

    if(m_info.TEST){
        T100AppTest         test(this);

        test.run();
    }

    if(m_info.FONT){
        m_font = T100NEW T100FontBuilder::T100FontApp(this);
        m_font->show();
    }

    if(m_info.VDISK){
        m_vdisk = T100NEW T100VDisk::T100VDiskConsole(this);
        m_vdisk->run();
    }

    if(m_info.ASSEMBLY){
        m_assembly  = T100NEW T100Assembly::T100Assembly(this);
        result      = m_assembly->run(m_info);
    }

    if(m_info.VPC){
        m_vpc = T100NEW T100VPC::T100VPCApp(this);
        m_vpc->show();
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
