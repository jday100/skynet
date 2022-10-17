#ifndef T100VDISKCALLBACK_H
#define T100VDISKCALLBACK_H

#include "T100DiskCommon.h"
#include "T100VDiskCommon.h"
class T100VDiskServe;
class T100VDiskView;


class T100VDiskCallback
{
    public:
        T100VDiskCallback();
        virtual ~T100VDiskCallback();

        static T100BOOL                 init(T100VDiskServe*, T100VDiskView*);

    public:
        static T100BOOL                 frame_menu_new(void* = T100NULL);
        static T100BOOL                 frame_menu_open(void* = T100NULL);
        static T100BOOL                 frame_menu_save(void* = T100NULL);
        static T100BOOL                 frame_menu_close(void* = T100NULL);

        static T100BOOL                 frame_menu_quit(void* = T100NULL);
        static T100BOOL                 frame_menu_about(void* = T100NULL);

        static T100BOOL                 ctrl_menu_new(void* = T100NULL);
        static T100BOOL                 ctrl_menu_remove(void* = T100NULL);
        static T100BOOL                 ctrl_menu_format(void* = T100NULL);

        static T100BOOL                 ctrl_get_all_parts(void* = T100NULL);
        static T100BOOL                 ctrl_get_all_items(T100String, T100String, T100DISK_ITEM_VECTOR&);

        static T100BOOL                 ctrl_create_folder(void* = T100NULL);
        static T100BOOL                 ctrl_remove_folder(void* = T100NULL);

        static T100BOOL                 ctrl_copy_file(void* = T100NULL, void* = T100NULL);
        static T100BOOL                 ctrl_remove_file(void* = T100NULL);

    protected:

    private:
        static T100VDiskServe*          m_serve;
        static T100VDiskView*           m_view;

};

#endif // T100VDISKCALLBACK_H
