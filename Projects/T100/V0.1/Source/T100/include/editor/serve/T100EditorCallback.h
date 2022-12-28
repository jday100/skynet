#ifndef T100EDITORCALLBACK_H
#define T100EDITORCALLBACK_H

#include "T100Common.h"

namespace T100Editor{
class T100EditorServe;
class T100EditorView;


class T100EditorCallback
{
    public:
        T100EditorCallback();
        virtual ~T100EditorCallback();

        static T100VOID                 init(T100EditorServe*, T100EditorView*);

    public:
        static T100BOOL                 frame_menu_new(void* = T100NULL);
        static T100BOOL                 frame_menu_open(void* = T100NULL);
        static T100BOOL                 frame_menu_close(void* = T100NULL);
        static T100BOOL                 frame_menu_save(void* = T100NULL);
        static T100BOOL                 frame_menu_save_as(void* = T100NULL);
        static T100BOOL                 frame_menu_quit(void* = T100NULL);

        static T100BOOL                 frame_menu_undo(void* = T100NULL);
        static T100BOOL                 frame_menu_redo(void* = T100NULL);
        static T100BOOL                 frame_menu_cut(void* = T100NULL);
        static T100BOOL                 frame_menu_copy(void* = T100NULL);
        static T100BOOL                 frame_menu_paste(void* = T100NULL);

        static T100BOOL                 frame_menu_search(void* = T100NULL);
        static T100BOOL                 frame_menu_replace(void* = T100NULL);
        static T100BOOL                 frame_menu_about(void* = T100NULL);

    protected:

    private:
        static T100EditorServe*         m_serve;
        static T100EditorView*          m_view;

};

}

#endif // T100EDITORCALLBACK_H
