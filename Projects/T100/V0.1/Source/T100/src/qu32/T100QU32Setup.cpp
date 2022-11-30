#include "T100QU32Setup.h"

namespace T100QU32{

T100BOOL                    T100QU32Setup::DEBUG                        = T100FALSE;
T100EXECUTOR_MODE           T100QU32Setup::DEBUG_MODE                   = T100EXECUTOR_MODE_NONE;
T100EXECUTOR_STATE          T100QU32Setup::DEBUG_STATE                  = T100EXECUTOR_STATE_NONE;
T100PRELOAD_VECTOR          T100QU32Setup::m_files;

T100WORD                    T100QU32Setup::MEMORY_WINDOW_BEGIN          = 0;
T100WORD                    T100QU32Setup::MEMORY_WINDOW_END            = 0;
T100WORD                    T100QU32Setup::PORT_WINDOW_BEGIN            = 0;
T100WORD                    T100QU32Setup::PORT_WINDOW_END              = 0;

T100WORD                    T100QU32Setup::SCREEN_WIDTH                 = 800;
T100WORD                    T100QU32Setup::SCREEN_HEIGHT                = 600;

T100STRING                  T100QU32Setup::m_build_path                 = L"build";
T100STRING                  T100QU32Setup::m_stores_path                = L"stores";
T100STRING                  T100QU32Setup::m_resources_path             = L"resources";

T100BOOL                    T100QU32Setup::NEED_LOAD_ROM                = T100TRUE;
T100STRING                  T100QU32Setup::m_rom_file                   = L"rom.bin";
T100WORD                    T100QU32Setup::m_ram_base                   = 1024 * 1024 * 1024;
T100WORD                    T100QU32Setup::m_ram_size                   = 1024 * 1024;
T100WORD                    T100QU32Setup::m_rom_base                   = 0;
T100WORD                    T100QU32Setup::m_rom_size                   = 1024 * 1024;

T100QU32Setup::T100QU32Setup()
{
    //ctor
}

T100QU32Setup::~T100QU32Setup()
{
    //dtor
}

T100VOID T100QU32Setup::clear()
{
    m_files.clear();
}

T100VOID T100QU32Setup::setRomFile(T100STRING file)
{
    m_rom_file = file;
}

T100STRING T100QU32Setup::getRomFile()
{
    return m_build_path + L"\\" + m_rom_file;
}

T100STRING T100QU32Setup::getBuild()
{
    return m_build_path;
}

T100STRING T100QU32Setup::getStores()
{
    return m_stores_path;
}

T100STRING T100QU32Setup::getResources()
{
    return m_resources_path;
}

T100VOID T100QU32Setup::setRamBase(T100WORD value)
{
    //m_ram_base = value;
}

T100WORD T100QU32Setup::getRamBase()
{
    return m_ram_base;
}

T100VOID T100QU32Setup::setRamSize(T100WORD value)
{
    m_ram_size = value;
}

T100WORD T100QU32Setup::getRamSize()
{
    return m_ram_size;
}

T100VOID T100QU32Setup::setRomBase(T100WORD value)
{
    m_rom_base = value;
}

T100WORD T100QU32Setup::getRomBase()
{
    return m_rom_base;
}

T100VOID T100QU32Setup::setRomSize(T100WORD value)
{
    m_rom_size = value;
}

T100WORD T100QU32Setup::getRomSize()
{
    return m_rom_size;
}

T100PRELOAD_VECTOR& T100QU32Setup::getPreloadFiles()
{
    return m_files;
}

}
