#ifndef T100VDISKCMDPARSER_H
#define T100VDISKCMDPARSER_H

#include "T100CmdParser.h"
#include "T100VDisk.h"

/*
Create:
    create vdisk name.vdk 1024
    create part name 1 1024
    create part name boot 1 1024
    create file part path
    create dir part path

Remove:
    remove vdisk name.vdk
    remove part name
    remove file part path
    remove dir part path

Set:
    set part name boot 1

Load:
    load name

List:
    list
    list part path

Format:
    format name
    format name boot.bin

Directory:
    mkdir part path
    chdir part path
    rmdir part path

Copy:
    copy source part target

*/

class T100VDiskCmdParser : public T100CmdParser
{
    public:
        T100VDiskCmdParser();
        virtual ~T100VDiskCmdParser();

        T100INTEGER         parse(T100COMMAND_VECTOR&);
        T100BOOL            quit();

    protected:
        T100BOOL            help();

        //
        T100BOOL            create(T100STDSTRING, T100STDSTRING);
        T100BOOL            remove(T100STDSTRING);
        T100BOOL            load(T100STDSTRING);
        //
        T100BOOL            part_create(T100STDSTRING, T100STDSTRING, T100STDSTRING, T100BOOL);
        T100BOOL            part_remove(T100STDSTRING);
        T100BOOL            part_list();
        T100BOOL            part_boot(T100STDSTRING, T100STDSTRING);
        //
        T100BOOL            fs_format(T100STDSTRING);
        T100BOOL            fs_format(T100STDSTRING, T100STDSTRING);
        //
        T100BOOL            fs_mkdir(T100STDSTRING, T100STDSTRING);
        T100BOOL            fs_chdir(T100STDSTRING, T100STDSTRING);
        T100BOOL            fs_rmdir(T100STDSTRING, T100STDSTRING);
        //
        T100BOOL            fs_create(T100STDSTRING, T100STDSTRING);
        T100BOOL            fs_remove(T100STDSTRING, T100STDSTRING);
        //
        T100BOOL            fs_list(T100STDSTRING, T100STDSTRING);
        T100BOOL            fs_copy(T100STDSTRING, T100STDSTRING, T100STDSTRING);


    private:
        T100VDisk*          m_vdisk         = T100NULL;

};

#endif // T100VDISKCMDPARSER_H
