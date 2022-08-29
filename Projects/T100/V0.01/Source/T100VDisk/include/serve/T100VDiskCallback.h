#ifndef T100VDISKCALLBACK_H
#define T100VDISKCALLBACK_H

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

        static T100BOOL                 ctrl_menu_new(void* = T100NULL);


        static T100BOOL                 dialog_new_browse(void* = T100NULL);

    protected:

    private:
        static T100VDiskServe*          m_serve;
        static T100VDiskView*           m_view;

};

#endif // T100VDISKCALLBACK_H
