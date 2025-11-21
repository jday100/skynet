#include "T100MemoryIntel64.h"

#include <io.h>
#include <fstream>
#include <sys/stat.h>
#include "T100PSVMConfig.h"

T100MemoryIntel64::T100MemoryIntel64() :
    T100Memory()
{
    //ctor
    init();
}

T100MemoryIntel64::~T100MemoryIntel64()
{
    //dtor
    uninit();
}

T100VOID T100MemoryIntel64::init()
{
    m_rom.resize(16 * 1024 * 1024);
    m_ram.resize(64 * 1024 * 1024);

    Load(T100PSVMConfig::m_firmware);
}

T100VOID T100MemoryIntel64::uninit()
{

}

T100BOOL T100MemoryIntel64::Read(T100UINT64 offset, T100BYTE* data)
{
    /*
    if(offset >= m_offset && offset < 0xfffff){
        *data   = m_rom.at(offset - (0xfffff - m_rom.size()));
        return T100TRUE;
    }
    if(offset <= m_ram.size()){
        *data   = m_ram.at(offset);
        return T100TRUE;
    }
    */
    if(offset < m_ram.size()){
        *data   = m_ram.at(offset);
        return T100TRUE;
    }
    if(offset >= 0xffffffff - m_rom.size()){
        *data   = m_rom.at(offset);
        return T100TRUE;
    }
    return T100TRUE;
}

T100BOOL T100MemoryIntel64::Read(T100UINT64 offset, T100UINT16* data)
{
    if(offset < m_ram.size()){
        memcpy(data, m_ram.data() + offset, 2);
        return T100TRUE;
    }
    if(offset >= 0xffffffff - m_rom.size()){
        memcpy(data, m_rom.data() + offset, 2);
        return T100TRUE;
    }
    return T100TRUE;
}

T100BOOL T100MemoryIntel64::Read(T100UINT64 offset, T100UINT32* data)
{
    if(offset < m_ram.size()){
        memcpy(data, m_ram.data() + offset, 4);
        //data   = (T100UINT32*)(m_ram.data() + offset);
        return T100TRUE;
    }
    if(offset >= 0xffffffff - m_rom.size()){
        //data   = (T100UINT32*)(m_rom.data() + offset);
        memcpy(data, m_rom.data() + offset, 4);
        return T100TRUE;
    }
    return T100TRUE;
}

T100BOOL T100MemoryIntel64::Load(T100STRING& file)
{
    T100UINT64          source;
    T100UINT64          target;
    struct _stat64      state;

    if(_stat64(file.c_str(), &state) != 0){
        return T100FALSE;
    }

    source  = state.st_size;
    target  = m_rom.size();

    if(source > target){
        return T100FALSE;
    }

    T100BYTE*       data        = T100NULL;
    T100UINT64      offset      = 0;

    offset  = target - source;

    data = m_rom.data() + offset;

    std::ifstream   ifs(file, std::ios::in | std::ios::binary);

    if(!ifs.is_open()){
        return T100FALSE;
    }

    T100BOOL    result  = ifs.read((char*)data, source).good();

    ifs.close();

    Copy();

    return result;
}

T100VOID T100MemoryIntel64::Copy()
{
    T100UINT    offset;

    offset  = m_rom.size() - m_length;

    std::copy(m_rom.begin() + offset, m_rom.end(), m_ram.begin() + m_offset + 1);
}
