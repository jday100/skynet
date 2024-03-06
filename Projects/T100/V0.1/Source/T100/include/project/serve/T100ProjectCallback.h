#ifndef T100PROJECTCALLBACK_H
#define T100PROJECTCALLBACK_H

#include "T100Common.h"
#include "T100ProjectTransverter.h"

namespace T100PROJECT{
class T100ProjectStore;
class T100ProjectServe;
class T100ProjectView;


class T100ProjectCallback
{
    public:
        T100ProjectCallback();
        virtual ~T100ProjectCallback();

        static T100VOID                     init(T100ProjectStore*, T100ProjectServe*, T100ProjectView*);
        static T100ProjectStore*            getStore();
        static T100ProjectServe*            getServe();
        static T100ProjectView*             getView();

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

        static T100BOOL                     frame_menu_projects(void* = T100NULL);

        static T100BOOL                     frame_menu_about(void* = T100NULL);

    protected:

    private:
        static T100ProjectStore*            m_store;
        static T100ProjectServe*            m_serve;
        static T100ProjectView*             m_view;

        static T100Component::T100ProjectTransverter        m_manager;
};

}

#endif // T100PROJECTCALLBACK_H
