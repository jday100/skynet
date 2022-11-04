#ifndef T100VPCCALLBACK_H
#define T100VPCCALLBACK_H

#include "T100Common.h"

namespace T100VPC{
class T100VPCServe;
class T100VPCView;


class T100VPCCallback
{
    public:
        T100VPCCallback();
        virtual ~T100VPCCallback();

        static T100BOOL             init(T100VPCServe*, T100VPCView*);

        static T100BOOL             menu_start_click();

        static T100BOOL             menu_stop_click();

        static T100BOOL             menu_quit_click();

        static T100BOOL             menu_config_click();

    protected:
        static T100VPCServe*        m_serve;
        static T100VPCView*         m_view;

    private:
};

}

#endif // T100VPCCALLBACK_H
