#ifndef T100VPCVIEW_H
#define T100VPCVIEW_H

#include <wx/frame.h>
#include "T100VPCCommon.h"
class T100VPCScreen;
class T100VPCDebugFrame;
class T100VPCHostFrame;


class T100VPCView
{
    public:
        T100VPCView();
        virtual ~T100VPCView();

        T100VOID                setFrame(wxFrame*);
        wxFrame*                getFrame();

        T100BOOL                show();

        T100BOOL                hide();

        T100BOOL                ShowDebug();

        T100VPCDebugFrame*      getDebugFrame();

    protected:

    private:
        wxFrame*                m_frame             = T100NULL;
        T100VPCScreen*          m_screen            = T100NULL;
        T100VPCDebugFrame*      m_debug             = T100NULL;
        T100VPCHostFrame*       m_host              = T100NULL;

};

#endif // T100VPCVIEW_H
