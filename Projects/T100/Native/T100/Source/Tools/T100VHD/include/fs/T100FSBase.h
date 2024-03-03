#ifndef T100FSBASE_H
#define T100FSBASE_H

#include "T100Common.h"


class T100FSBase
{
    public:
        T100FSBase();
        virtual ~T100FSBase();

        virtual T100BOOL            disk_initialize() = 0;

        virtual T100BOOL            partition_create() = 0;
        virtual T100BOOL            partition_remove() = 0;
        virtual T100BOOL            partition_list() = 0;

        virtual T100BOOL            fs_format() = 0;
        virtual T100BOOL            fs_list() = 0;

        virtual T100BOOL            fs_mkdir() = 0;
        virtual T100BOOL            fs_chdir() = 0;
        virtual T100BOOL            fs_rmdir() = 0;

        virtual T100BOOL            fs_create() = 0;
        virtual T100BOOL            fs_remove() = 0;
        virtual T100BOOL            fs_open() = 0;
        virtual T100BOOL            fs_close() = 0;
        virtual T100BOOL            fs_read() = 0;
        virtual T100BOOL            fs_write() = 0;
        virtual T100BOOL            fs_seek() = 0;

    protected:

    private:
};

#endif // T100FSBASE_H
