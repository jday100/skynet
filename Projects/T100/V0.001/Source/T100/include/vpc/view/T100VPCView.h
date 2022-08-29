#ifndef T100VPCVIEW_H
#define T100VPCVIEW_H

#include "IView.h"
#include "T100VPCCommon.h"
#include "T100VPCFrame.h"
#include "T100VPCScreen.h"
#include "T100VPCServe.h"
#include "T100VPCDebugFrame.h"
class T100VPCApp;


class T100VPCView : public IView
{
    friend class T100VPCFrame;
    public:
        T100VPCView();
        virtual ~T100VPCView();

        T100VOID            create();

        T100BOOL            run();
        T100BOOL            start();
        T100BOOL            stop();
        T100BOOL            quit();

        T100VOID            setApp(T100VPCApp*);
        T100VPCApp*         getApp();
        T100VOID            setFrame(T100VPCFrame*);
        T100VPCFrame*       getFrame();

        T100BOOL            show();

        T100VPCDebugFrame*  getDebugFrame();

    protected:
        T100VOID            destroy();

    private:
        T100VPCApp*         m_app           = T100NULL;
        T100VPCFrame*       m_frame         = T100NULL;
        T100VPCScreen*      m_screen        = T100NULL;
        T100VPCDebugFrame*  m_debug         = T100NULL;

        T100BOOL            m_quit          = T100FALSE;

};

#endif // T100VPCVIEW_H
