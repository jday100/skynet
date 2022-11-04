#ifndef T100VPCVIEW_H
#define T100VPCVIEW_H

#include "T100Common.h"

namespace T100VPC{
class T100VPCFrame;
class T100VPCScreen;
class T100VPCConfigDialog;


class T100VPCView
{
    public:
        T100VPCView();
        virtual ~T100VPCView();

        T100BOOL                    show();
        T100BOOL                    hide();

        T100BOOL                    quit();

        T100VOID                    setFrame(T100VPCFrame*);
        T100VPCFrame*               getFrame();

        T100VPCScreen*              getScreen();

        T100VPCConfigDialog*        getConfig();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100VPCFrame*               m_frame         = T100NULL;
        T100VPCScreen*              m_screen        = T100NULL;
        T100VPCConfigDialog*        m_config        = T100NULL;

};

}

#endif // T100VPCVIEW_H
