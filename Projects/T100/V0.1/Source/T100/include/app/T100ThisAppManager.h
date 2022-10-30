#ifndef T100THISAPPMANAGER_H
#define T100THISAPPMANAGER_H

#include <wx/wx.h>
#include "T100WxAppManager.h"
#include "T100ThisAppCmdLineResult.h"


class T100ThisAppManager : public T100WxWidgets::T100WxAppManager
{
    public:
        T100ThisAppManager();
        virtual ~T100ThisAppManager();

        T100BOOL                start();

        T100BOOL                stop();

        T100BOOL                parse(int&, wxChar**);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100ThisAppCmdLineResult        m_info;

};

#endif // T100THISAPPMANAGER_H
