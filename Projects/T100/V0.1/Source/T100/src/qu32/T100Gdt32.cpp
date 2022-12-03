#include "T100Gdt32.h"

#include "T100QU32.h"

namespace T100QU32{

T100Gdt32::T100Gdt32(T100QU32* host)
    :m_host(host)
{
    //ctor
}

T100Gdt32::~T100Gdt32()
{
    //dtor
}

T100QU32* T100Gdt32::getHost()
{
    return m_host;
}

T100BOOL T100Gdt32::enter(T100WORD base, T100WORD offset)
{
    T100BOOL        result          = T100FALSE;

    result = getHost()->getMemory32()->enter();

    return result;
}

T100BOOL T100Gdt32::quit(T100WORD base, T100WORD offset)
{
    T100BOOL        result          = T100FALSE;

    result = getHost()->getMemory32()->quit();

    return result;
}

T100BOOL T100Gdt32::load(T100WORD offset, T100WORD length)
{
    return T100TRUE;
}

T100BOOL T100Gdt32::getEntry(T100WORD index, T100WORD& value)
{
    T100BOOL        result          = T100TRUE;

    //test
    if(1 == index){
        value   = 1073743872;
        return T100TRUE;
    }else{
        result  = T100FALSE;
    }

    if(index >= m_gdt.size()){
        return T100FALSE;
    }

    T100GDT_ITEM*   item    = T100NULL;

    item = m_gdt.at(index);

    if(item){
        value   = item->OFFSET;
    }else{
        result  = T100FALSE;
    }

    return result;
}

}
