#include "T100VDiskConsole.h"

#include "T100VDiskConsoleApp.h"
#include "T100ConsoleTerminal.h"
#include "T100VDiskCmdLineParser.h"

namespace T100VDisk{

T100VDiskConsole::T100VDiskConsole(T100VDiskConsoleApp* app)
    :m_app(app)
{
    //ctor
}

T100VDiskConsole::~T100VDiskConsole()
{
    //dtor
}

T100BOOL T100VDiskConsole::run()
{
    T100BOOL        result                  = T100FALSE;

    T100VDiskCmdLineParser*                 parser          = T100NEW T100VDiskCmdLineParser();
    T100Library::T100ConsoleTerminal*       console         = T100NEW T100Library::T100ConsoleTerminal(parser);

    result = console->run();

    if(m_app){
        m_app->quit();
    }

    return result;
}

}
