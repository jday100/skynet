#include "T100VPCSetup.h"

T100BOOL            T100VPCSetup::m_quit        =   T100FALSE;
T100WORD            T100VPCSetup::m_return      =   0;

T100STDSTRING       T100VPCSetup::rom_size      =   "1M";
T100STDSTRING       T100VPCSetup::ram_size      =   "1M";

T100STDSTRING       T100VPCSetup::vdisk_file    =   "vdisk.vdk";
T100STDSTRING       T100VPCSetup::font_file     =   "font.fnt";
T100STDSTRING       T100VPCSetup::rom_file      =   "rom.bin";


T100VPCSetup::T100VPCSetup()
{
    //ctor
}

T100VPCSetup::~T100VPCSetup()
{
    //dtor
}

T100VOID T100VPCSetup::setRamSize(T100STDSTRING str)
{
    ram_size = str;
}

T100STDSTRING T100VPCSetup::getRamSize()
{
    return ram_size;
}

T100VOID T100VPCSetup::setRomSize(T100STDSTRING str)
{
    rom_size = str;
}

T100STDSTRING T100VPCSetup::getRomSize()
{
    return rom_size;
}

T100VOID T100VPCSetup::setVDiskFile(T100STDSTRING str)
{
    vdisk_file = str;
}

T100STDSTRING T100VPCSetup::getVDiskFile()
{
    if("vdisk.vdk" == vdisk_file){
        return T100APP_STORE_PATH + "\\" + vdisk_file;
    }
    return vdisk_file;
}

T100VOID T100VPCSetup::setFontFile(T100STDSTRING str)
{
    font_file = str;
}

T100STDSTRING T100VPCSetup::getFontFile()
{
    if("font.fnt" == font_file){
        return T100APP_RESOURCE_PATH + "\\" + font_file;
    }
    return font_file;
}

T100VOID T100VPCSetup::setRomFile(T100STDSTRING str)
{
    rom_file = str;
}

T100STDSTRING T100VPCSetup::getRomFile()
{
    if("rom.bin" == rom_file){
        return T100APP_BUILD_PATH + "\\" + rom_file;
    }
    return rom_file;
}

T100DWORD T100VPCSetup::format(T100STDSTRING str)
{
    return 1024 * 1024;
}

T100STDSTRING T100VPCSetup::format(T100DWORD value)
{
    return "1M";
}

T100STDSTRING T100VPCSetup::getTestPath()
{
    return T100APP_TEST_PATH;
}

T100STDSTRING T100VPCSetup::getTestOSScript(T100STDSTRING file)
{
    T100STDSTRING   result;

    result = T100APP_TEST_PATH + "\\" + "scripts\\os";

    if(!file.empty()){
        result += "\\" + file;
    }

    return result;
}

T100STDSTRING T100VPCSetup::getTestOSBuild(T100STDSTRING file)
{
    T100STDSTRING   result;

    result = T100APP_TEST_PATH + "\\" + "build";

    if(!file.empty()){
        result += "\\" + file;
    }

    return result;
}

T100STDSTRING T100VPCSetup::getTestOSStore(T100STDSTRING file)
{
    T100STDSTRING   result;

    result = T100APP_TEST_PATH + "\\" + "scripts\\stores";

    if(!file.empty()){
        result += "\\" + file;
    }

    return result;
}
