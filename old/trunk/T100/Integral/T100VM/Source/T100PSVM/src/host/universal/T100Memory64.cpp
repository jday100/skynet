#include "T100Memory64.h"

#include <io.h>
#include <fstream>
#include <sys/stat.h>
#include "T100Host64.h"
#include "T100PSVMConfig.h"

T100Memory64::T100Memory64(T100Host64* host) :
    T100Memory(),
    m_host(host)
{
    //ctor
    init();
}

T100Memory64::~T100Memory64()
{
    //dtor
    uninit();
}

T100VOID T100Memory64::init()
{
    m_flag      = T100FALSE;
    m_ready     = T100FALSE;
    m_count     = 0;
    m_delay     = 5;

    m_ram.resize(128 * 1024 * 1024);
    m_rom.resize(16 * 1024 * 1024);

    Load(T100PSVMConfig::m_firmware);
}

T100VOID T100Memory64::uninit()
{

}

T100VOID T100Memory64::Pulse()
{
    if(m_flag){
        if(m_ready){

        }else{
            m_count++;
            if(m_count >= m_delay){
                m_host->m_bus.Ready();
                m_ready = T100TRUE;
            }
        }
    }
}

T100VOID T100Memory64::Acquire()
{
    if(m_flag){

    }else{
        m_flag  = T100TRUE;
    }
}

T100BOOL T100Memory64::Read(T100UINT64 offset, T100BYTE* data)
{
    if(m_flag){
        if(m_count >= m_delay){
            *data   = m_ram.at(offset);
            m_flag  = T100FALSE;
            m_ready = T100FALSE;
            m_count = 0;
        }
    }
}

T100BOOL T100Memory64::Load(T100STRING& file)
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

T100VOID T100Memory64::Copy()
{
    T100UINT    offset;

    offset  = m_rom.size() - m_length;

    std::copy(m_rom.begin() + offset, m_rom.end(), m_ram.begin() + m_offset + 1);
}
