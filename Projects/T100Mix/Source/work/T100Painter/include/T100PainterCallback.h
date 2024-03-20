#ifndef T100PAINTERCALLBACK_H
#define T100PAINTERCALLBACK_H

#include "T100Common.h"
class T100Painter;
class T100PainterStore;
class T100PainterServe;
class T100PainterView;


class T100PainterCallback
{
    public:
        T100PainterCallback();
        virtual ~T100PainterCallback();

        static T100VOID                     init(T100Painter*, T100PainterStore*, T100PainterServe*, T100PainterView*);
        static T100PainterStore*            getStore();
        static T100PainterServe*            getServe();
        static T100PainterView*             getView();

    public:
        static T100BOOL                     frame_menu_new(T100VOID* = T100NULL);
        static T100BOOL                     frame_menu_open(T100VOID* = T100NULL);
        static T100BOOL                     frame_menu_close(T100VOID* = T100NULL);
        static T100BOOL                     frame_menu_save(T100VOID* = T100NULL);
        static T100BOOL                     frame_menu_save_as(T100VOID* = T100NULL);
        static T100BOOL                     frame_menu_quit(T100VOID* = T100NULL);

    protected:

    private:
        static T100Painter*                 m_painter;
        static T100PainterStore*            m_store;
        static T100PainterServe*            m_serve;
        static T100PainterView*             m_view;
};

#endif // T100PAINTERCALLBACK_H
