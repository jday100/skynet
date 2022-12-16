#include "T100VDiskConsole.h"

#include "T100ConsoleTerminal.h"
#include "T100VDiskCmdLineParser.h"

namespace T100VDisk{

T100VDiskConsole::T100VDiskConsole(T100Library::T100AppManager* obj)
    :T100Library::T100AppBase(obj)
{
    //ctor
}

T100VDiskConsole::~T100VDiskConsole()
{
    //dtor
}

T100BOOL T100VDiskConsole::run()
{
    T100VDiskCmdLineParser*                 parser          = T100NEW T100VDiskCmdLineParser();
    T100Library::T100ConsoleTerminal*       console         = T100NEW T100Library::T100ConsoleTerminal(parser);

    return console->run();
}

}
