#ifndef T100VPCSETUP_H
#define T100VPCSETUP_H

#include "T100Common.h"
#include "T100Setup.h"


class T100VPCSetup : public T100Setup
{
    public:
        T100VPCSetup();
        virtual ~T100VPCSetup();

        static T100BOOL             m_quit;
        static T100WORD             m_return;

        static T100VOID             setRamSize(T100STDSTRING);
        static T100STDSTRING        getRamSize();

        static T100VOID             setRomSize(T100STDSTRING);
        static T100STDSTRING        getRomSize();

        static T100VOID             setVDiskFile(T100STDSTRING);
        static T100STDSTRING        getVDiskFile();

        static T100VOID             setFontFile(T100STDSTRING);
        static T100STDSTRING        getFontFile();

        static T100VOID             setRomFile(T100STDSTRING);
        static T100STDSTRING        getRomFile();

        static T100DWORD            format(T100STDSTRING);
        static T100STDSTRING        format(T100DWORD);


        static T100STDSTRING        getTestPath();

        static T100STDSTRING        getTestOSScript(T100STDSTRING);
        static T100STDSTRING        getTestOSBuild(T100STDSTRING);
        static T100STDSTRING        getTestOSStore(T100STDSTRING);

    protected:

    private:
        static T100STDSTRING        ram_size;
        static T100STDSTRING        rom_size;

        static T100STDSTRING        vdisk_file;
        static T100STDSTRING        font_file;

        static T100STDSTRING        rom_file;
};

#endif // T100VPCSETUP_H
