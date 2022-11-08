#ifndef T100VDISKCMDLINEPARSER_H
#define T100VDISKCMDLINEPARSER_H

#include "T100VDisk.h"
#include "T100ConsoleTerminalParser.h"

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

namespace T100VDisk{

class T100VDiskCmdLineParser : public T100Library::T100ConsoleTerminalParser
{
    public:
        T100VDiskCmdLineParser();
        virtual ~T100VDiskCmdLineParser();

    protected:
        T100BOOL            parse(T100CONSOLE_COMMAND_VECTOR&);

    protected:
        T100BOOL            help();

        T100BOOL            create(T100WSTRING, T100WSTRING);
        T100BOOL            remove(T100WSTRING);
        T100BOOL            load(T100WSTRING);
        //
        T100BOOL            part_create(T100WSTRING, T100WSTRING, T100WSTRING, T100BOOL);
        T100BOOL            part_remove(T100WSTRING);
        T100BOOL            part_list();
        T100BOOL            part_boot(T100WSTRING, T100WSTRING);
        //
        T100BOOL            fs_format(T100WSTRING);
        T100BOOL            fs_format(T100WSTRING, T100WSTRING);
        //
        T100BOOL            fs_mkdir(T100WSTRING, T100WSTRING);
        T100BOOL            fs_chdir(T100WSTRING, T100WSTRING);
        T100BOOL            fs_rmdir(T100WSTRING, T100WSTRING);
        //
        T100BOOL            fs_create(T100WSTRING, T100WSTRING);
        T100BOOL            fs_remove(T100WSTRING, T100WSTRING);
        //
        T100BOOL            fs_list(T100WSTRING, T100WSTRING);
        T100BOOL            fs_copy(T100WSTRING, T100WSTRING, T100WSTRING);

    private:
        T100Component::T100VDisk*          m_vdisk         = T100NULL;

};

}

#endif // T100VDISKCMDLINEPARSER_H
