#ifndef T100WPAINTERCALLBACK_H
#define T100WPAINTERCALLBACK_H

#include "T100Common.h"
class T100WPainter;
class T100WPainterStore;
class T100WPainterServe;
class T100WPainterView;

class T100WPainterCallback
{
    public:
        T100WPainterCallback();
        virtual ~T100WPainterCallback();

        static T100VOID                 init(T100WPainter*, T100WPainterStore*, T100WPainterServe*, T100WPainterView*);

        static T100WPainter*            getPainter();
        static T100WPainterStore*       getStore();
        static T100WPainterServe*       getServe();
        static T100WPainterView*        getView();

    public:
        static T100VOID                 frame_menu_new(T100VOID* = T100NULL);
        static T100VOID                 frame_menu_open(T100VOID* = T100NULL);
        static T100VOID                 frame_menu_save(T100VOID* = T100NULL);
        static T100VOID                 frame_menu_save_as(T100VOID* = T100NULL);
        static T100VOID                 frame_menu_close(T100VOID* = T100NULL);
        static T100VOID                 frame_menu_quit(T100VOID* = T100NULL);

        static T100VOID                 elements_item_select(T100VOID* = T100NULL);

    protected:

    private:
        static T100WPainter*            m_painter;
        static T100WPainterStore*       m_store;
        static T100WPainterServe*       m_serve;
        static T100WPainterView*        m_view;
};

#endif // T100WPAINTERCALLBACK_H
