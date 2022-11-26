#ifndef T100VPCVIEW_H
#define T100VPCVIEW_H

#include "T100Common.h"
#include "T100WxApp.h"

namespace T100VPC{
class T100VPCFrame;
class T100VPCScreen;
class T100VPCConfigDialog;


class T100VPCView
{
    public:
        T100VPCView();
        virtual ~T100VPCView();

        T100VOID        setCallback(wxFrame*, T100WxWidgets::T100FRAME_CALLBACK);

        T100BOOL                    show();
        T100BOOL                    hide();

        T100BOOL                    run();
        T100BOOL                    quit();

        T100VOID                    setFrame(T100VPCFrame*);
        T100VPCFrame*               getFrame();

        T100VPCScreen*              getScreen();

        T100VPCConfigDialog*        getConfig();

    public:
        T100BOOL                    start();
        T100BOOL                    stop();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100VPCFrame*               m_frame         = T100NULL;
        T100VPCScreen*              m_screen        = T100NULL;
        T100VPCConfigDialog*        m_config        = T100NULL;

        wxFrame*                                m_parent            = T100NULL;
        T100WxWidgets::T100FRAME_CALLBACK       m_callback          = T100NULL;

};

}

#endif // T100VPCVIEW_H
