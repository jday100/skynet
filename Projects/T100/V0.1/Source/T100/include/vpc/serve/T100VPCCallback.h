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

    public:
        static T100BOOL             frame_menu_start(void* = T100NULL);
        static T100BOOL             frame_menu_stop(void* = T100NULL);
        static T100BOOL             frame_menu_quit(void* = T100NULL);

        static T100BOOL             frame_menu_hardware(void* = T100NULL);
        static T100BOOL             frame_menu_hardware_setup(void* = T100NULL);
        static T100BOOL             frame_menu_hardware_append(void* = T100NULL);
        static T100BOOL             frame_menu_hardware_remove(void* = T100NULL);
        static T100BOOL             frame_menu_hardware_finish(void* = T100NULL);

        static T100BOOL             frame_menu_setup(void* = T100NULL);

        static T100BOOL             frame_menu_debug(void* = T100NULL);

        static T100BOOL             frame_menu_about(void* = T100NULL);


        static T100BOOL             serve_create_display(void* = T100NULL);

    public:
        static T100BOOL             debug_button_run_click(void* = T100NULL);
        static T100BOOL             debug_button_pause_click(void* = T100NULL);
        static T100BOOL             debug_button_step_click(void* = T100NULL);
        static T100BOOL             debug_button_next_click(void* = T100NULL);
        static T100BOOL             debug_button_comment_click(void* = T100NULL);
        static T100BOOL             debug_button_call_click(void* = T100NULL);
        static T100BOOL             debug_button_return_click(void* = T100NULL);


        static T100BOOL             debug_cmt_update(void* = T100NULL);
        static T100BOOL             debug_register_update(void* = T100NULL);
        static T100BOOL             debug_memory_base_update(void* = T100NULL);
        static T100BOOL             debug_memory_offset_update(void* = T100NULL);
        static T100BOOL             debug_port_base_update(void* = T100NULL);
        static T100BOOL             debug_port_offset_update(void* = T100NULL);


        //
        static T100BOOL             debug_port_update(void* = T100NULL);


        static T100BOOL             debug_notify_start(void* = T100NULL);
        static T100BOOL             debug_notify_stop(void* = T100NULL);

    public:
        static T100BOOL             notify_thread_stop(void* = T100NULL);

    protected:
        static T100VPCServe*        m_serve;
        static T100VPCView*         m_view;

    private:
};

}

#endif // T100VPCCALLBACK_H
