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

    if(result){
        getHost()->getCU32()->setCBR(base);
        getHost()->getCU32()->setCOR(offset);
    }

    return result;
}

T100BOOL T100Gdt32::quit(T100WORD index, T100WORD offset)
{
    T100BOOL        result          = T100FALSE;
    T100WORD        base;

    result = getHost()->getMemory32()->quit();

    if(result){
        result = getEntry(index, base);
    }

    if(result){
        getHost()->getCU32()->setCBR(base);
        getHost()->getCU32()->setCOR(offset);
    }

    return result;
}

T100BOOL T100Gdt32::load(T100WORD offset, T100WORD length)
{
    T100BOOL        result;

    if(T100GDT_ITEM_LENGTH > length){
        return T100FALSE;
    }

    if(0 != (length % T100GDT_ITEM_LENGTH)){
        return T100FALSE;
    }

    T100WORD        index;

    index = length / T100GDT_ITEM_LENGTH;

    for(int i=0;i<index;i++){
        result = loadGdtItem(offset);
        if(!result){
            return T100FALSE;
        }
    }

    return T100TRUE;
}

T100BOOL T100Gdt32::loadGdtItem(T100WORD& offset)
{
    T100BOOL        result;
    T100WORD        value;

    T100GDT_ITEM*   item    = T100NEW T100GDT_ITEM();

    result = getHost()->getMemory32()->read(offset, value);
    if(result){
        item->OFFSET    = value;
        offset++;
    }else{
        T100SAFE_DELETE(item);
        return T100FALSE;
    }

    result = getHost()->getMemory32()->read(offset, value);
    if(result){
        item->VALUE     = value;
        offset++;
    }else{
        T100SAFE_DELETE(item);
        return T100FALSE;
    }

    m_gdt.push_back(item);

    return T100TRUE;
}

T100BOOL T100Gdt32::getEntry(T100WORD index, T100WORD& value)
{
    T100BOOL        result          = T100TRUE;

    /*
    //test
    if(0 == index){
        value   = 1073743872;
        return T100TRUE;
    }else{
        result  = T100FALSE;
    }
    */

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
