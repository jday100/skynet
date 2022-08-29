#include "T100QU32Setup.h"


T100WORD        T100QU32Setup::m_return         = 0;

T100STDSTRING   T100QU32Setup::m_file           = "";
T100BOOL        T100QU32Setup::m_base           = T100FALSE;
T100WORD        T100QU32Setup::m_offset         = 0;

T100WORD        T100QU32Setup::m_rom_base       = 0;
T100WORD        T100QU32Setup::m_rom_size       = 16 * 1024;
T100WORD        T100QU32Setup::m_ram_base       = 1024 * 1024;
T100WORD        T100QU32Setup::m_ram_size       = 16 * 1024 * 1024;

T100BOOL        T100QU32Setup::m_debug          = T100FALSE;

T100FILE_INFO_VECTOR            T100QU32Setup::m_files;


T100QU32Setup::T100QU32Setup()
{
    //ctor
}

T100QU32Setup::~T100QU32Setup()
{
    //dtor
}
