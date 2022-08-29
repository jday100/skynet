#ifndef T100VPCCALLBACKNEW_H
#define T100VPCCALLBACKNEW_H

#include "T100VPCCommon.h"
class T100VPCServe;
class T100VPCView;


class T100VPCCallback
{
    public:
        T100VPCCallback();
        virtual ~T100VPCCallback();

        static T100BOOL                 init(T100VPCServe*, T100VPCView*);

        static T100BOOL                 frame_menu_start(void* = T100NULL);
        static T100BOOL                 frame_menu_stop(void* = T100NULL);
        static T100BOOL                 frame_menu_quit(void* = T100NULL);
        static T100BOOL                 frame_menu_setup(void* = T100NULL);
        static T100BOOL                 frame_menu_debug(void* = T100NULL);

        static T100BOOL                 frame_event_close(void* = T100NULL);

        static T100BOOL                 app_quit(void* = T100NULL);

        static T100BOOL                 frame_debug_log_on(void* = T100NULL);
        static T100BOOL                 frame_debug_log_off(void* = T100NULL);

        static T100BOOL                 frame_debug_pause(void* = T100NULL);
        static T100BOOL                 frame_debug_run(void* = T100NULL);
        static T100BOOL                 frame_debug_step(void* = T100NULL);
        static T100BOOL                 frame_debug_next(void* = T100NULL);

        //
        static T100BOOL                 callback_start(void*, void*, void*, void*);
        static T100BOOL                 callback_stop(void*, void*, void*, void*);
        static T100BOOL                 callback_done(void*, void*, void*, void*);

        static T100BOOL                 callback_debug(void*, void*, void*, void*);
        static T100BOOL                 callback_debug_update(void*, void*, void*, void*);
        static T100BOOL                 callback_debug_rom_base_update(void*, void*, void*, void*);
        static T100BOOL                 callback_debug_ram_base_update(void*, void*, void*, void*);
        //
        static T100BOOL                 callback_debug_device_update(void*, void*, void*, void*);
        static T100BOOL                 callback_debug_block_update(void*, void*, void*, void*);
        static T100BOOL                 callback_debug_page_update(void*, void*, void*, void*);

    protected:

    private:
        static T100VPCServe*            m_serve;
        static T100VPCView*             m_view;

};

#endif // T100VPCCALLBACKNEW_H
