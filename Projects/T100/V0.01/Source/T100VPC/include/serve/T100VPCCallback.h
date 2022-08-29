#ifndef T100VPCCALLBACK_H
#define T100VPCCALLBACK_H

#include "T100VPCCommon.h"
class T100VPCServe;
class T100VPCView;


class T100VPCCallback
{
    public:
        T100VPCCallback();
        virtual ~T100VPCCallback();

        static T100BOOL                 init(T100VPCServe*, T100VPCView*);

    public:
        static T100BOOL                 frame_menu_start(void* = T100NULL);
        static T100BOOL                 frame_menu_stop(void* = T100NULL);

        static T100BOOL                 frame_menu_hardware(void* = T100NULL);
        static T100BOOL                 frame_menu_hardware_select(void* = T100NULL);
        static T100BOOL                 frame_menu_setup(void* = T100NULL);

        static T100BOOL                 frame_menu_debug(void* = T100NULL);

    protected:

    private:
        static T100VPCServe*            m_serve;
        static T100VPCView*             m_view;

};

#endif // T100VPCCALLBACK_H
