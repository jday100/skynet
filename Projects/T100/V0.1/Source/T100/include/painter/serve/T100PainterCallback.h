#ifndef T100PAINTERCALLBACK_H
#define T100PAINTERCALLBACK_H

#include "T100Common.h"
#include "T100PainterTransverter.h"

namespace T100Painter{
class T100PainterStore;
class T100PainterServe;
class T100PainterView;


class T100PainterCallback
{
    public:
        T100PainterCallback();
        virtual ~T100PainterCallback();

        static T100VOID                     init(T100PainterStore*, T100PainterServe*, T100PainterView*);

    public:
        static T100BOOL                     frame_menu_new(void* = T100NULL);
        static T100BOOL                     frame_menu_open(void* = T100NULL);
        static T100BOOL                     frame_menu_close(void* = T100NULL);
        static T100BOOL                     frame_menu_save(void* = T100NULL);
        static T100BOOL                     frame_menu_save_as(void* = T100NULL);
        static T100BOOL                     frame_menu_quit(void* = T100NULL);

        static T100BOOL                     frame_menu_undo(void* = T100NULL);
        static T100BOOL                     frame_menu_redo(void* = T100NULL);
        static T100BOOL                     frame_menu_cut(void* = T100NULL);
        static T100BOOL                     frame_menu_copy(void* = T100NULL);
        static T100BOOL                     frame_menu_paste(void* = T100NULL);

        static T100BOOL                     frame_menu_elements(void* = T100NULL);

        static T100BOOL                     frame_menu_about(void* = T100NULL);

        ///
        static T100BOOL                     view_element_init(void* = T100NULL);
        static T100BOOL                     view_element_select(void* = T100NULL);

        //
        static T100BOOL                     canvas_mouse_left_down(void* = T100NULL);
        static T100BOOL                     canvas_mouse_left_up(void* = T100NULL);
        static T100BOOL                     canvas_mouse_move(void* = T100NULL);

    protected:

    private:
        static T100PainterStore*            m_store;
        static T100PainterServe*            m_serve;
        static T100PainterView*             m_view;

        static T100Component::T100PainterTransverter        m_manager;

};

}

#endif // T100PAINTERCALLBACK_H
