#ifndef T100THISAPPMANAGER_H
#define T100THISAPPMANAGER_H

#pragma comment(linker, "/STACK:10000000")
#pragma comment(linker, "/HEAP:10000000")

#include <wx/wx.h>
#include "T100WxAppManager.h"
#include "T100ThisAppCmdLineResult.h"

namespace T100FontBuilder{
    class T100FontApp;
}

namespace T100VDisk{
    class T100VDiskConsoleApp;
}

namespace T100Assembly{
    class T100AssemblyApp;
}

namespace T100VPC{
    class T100VPCApp;
}

namespace T100Editor{
    class T100EditorApp;
}

namespace T100Painter{
    class T100PainterApp;
}

namespace T100IDE{
    class T100IDEApp;
}

class T100ThisAppManager : public T100WxWidgets::T100WxAppManager
{
    public:
        T100ThisAppManager();
        virtual ~T100ThisAppManager();

        T100BOOL                start();

        T100BOOL                stop();

        T100BOOL                parse(int&, wxChar**);

        T100BOOL                close(T100WORD);

        T100IDE::T100IDEApp*    getIDE();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    protected:
        T100FontBuilder::T100FontApp*       m_font          = T100NULL;
        T100VDisk::T100VDiskConsoleApp*     m_vdisk         = T100NULL;
        T100Assembly::T100AssemblyApp*      m_assembly      = T100NULL;
        T100VPC::T100VPCApp*                m_vpc           = T100NULL;
        T100Editor::T100EditorApp*          m_editor        = T100NULL;
        T100Painter::T100PainterApp*        m_painter       = T100NULL;
        T100IDE::T100IDEApp*                m_ide           = T100NULL;

    private:
        T100ThisAppCmdLineResult            m_info;

};

#endif // T100THISAPPMANAGER_H
