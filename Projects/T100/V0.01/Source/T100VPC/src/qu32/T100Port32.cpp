#include "T100Port32.h"

T100Port32::T100Port32(T100QU32* host)
    :m_host(host)
{
    //ctor
    //create();
}

T100Port32::~T100Port32()
{
    //dtor
    destroy();
}

T100VOID T100Port32::create()
{
    m_cu        = T100NEW T100CUDevice(m_host);
    m_au        = T100NEW T100AUDevice(m_host);
    m_memory    = T100NEW T100MemoryDevice(m_host);
    m_port      = T100NEW T100PortDevice(m_host);
}

T100VOID T100Port32::destroy()
{

}

T100BOOL T100Port32::appendDevice(T100BYTE& id, T100Device* dev)
{
    T100BOOL            result;
    T100INT             value;

    value = m_devices.size() - m_device_limit;

    if(1 <= value){
        return T100FALSE;
    }

    result = dev->load(this);
    if(result){
        m_devices.push_back(dev);
        id = m_devices.size() - 1;
        m_device_hash[id] = dev;
    }

    return result;
}

T100BOOL T100Port32::removeDevice(T100BYTE id)
{
    T100BOOL            result;

    if(id < m_devices.size()){
        result = m_devices[id]->unload();
        if(!result){
            return T100FALSE;
        }

        T100Device* dev = (T100Device*)m_devices[id];
        m_devices[id] = T100NULL;

        T100DEVICE_HASH::iterator   it;

        it = m_device_hash.find(id);

        if(it != m_device_hash.end()){
            m_device_hash.erase(it);
        }

        return T100TRUE;
    }

    return T100FALSE;
}

T100Device* T100Port32::getDevice(T100BYTE id)
{
    T100DEVICE_HASH::iterator       it;

    it = m_device_hash.find(id);

    if(it != m_device_hash.end()){
        return (*it).second;
    }

    return T100NULL;
}

T100BOOL T100Port32::in(T100WORD offset, T100WORD& value)
{
    T100BOOL            result          = T100FALSE;

    if(offset < m_device_limit){
        T100BYTE    id;

        id = offset >> 2;

        T100Device* dev = getDevice(id);

        if(dev){
            id = offset & 3;
            return dev->in(id, value);
        }else{
            value = 0;
            return T100TRUE;
        }
    }else if(offset < m_block_limit){
        T100WORD    id;

        id = offset / m_device_limit;

        if(id > m_blocks.size()){
            return T100FALSE;
        }

        T100BlockDevice* dev = (T100BlockDevice*)m_blocks[id-1];
        if(dev){
            T100WORD            os;
            T100DEVICE_BLOCK*   block   = T100NULL;

            os      = offset % m_device_limit;
            block   = m_block_hash[id];

            value = block->data[os];
            return T100TRUE;
        }

    }else if(offset < m_page_limit){
        T100WORD        id;

        id = offset / m_block_limit;

        if(id > m_pages.size()){
            return T100FALSE;
        }

        T100PageDevice* dev = (T100PageDevice*)m_pages[id-1];
        if(dev){
            T100WORD            os;
            T100DEVICE_PAGE*    page    = T100NULL;

            os      = offset % m_block_limit;
            page    = m_page_hash[id];

            value = page->data[os];
            return T100TRUE;
        }
    }

    return result;
}

T100BOOL T100Port32::out(T100WORD offset, T100WORD value)
{
    T100BOOL            result          = T100FALSE;

    if(offset < m_device_limit){
        T100BYTE        id;

        id = offset >> 2;

        T100Device* dev = getDevice(id);
        if(dev){
            id = offset & 3;

            return dev->out(id, value);
        }else{
            //test
            return T100TRUE;
        }
    }else if(offset < m_block_limit){
        T100WORD        id;

        id = offset / m_device_limit;
        if(id > m_blocks.size()){
            return T100FALSE;
        }

        T100BlockDevice* dev = (T100BlockDevice*)m_blocks[id-1];
        if(dev){
            T100WORD                os;
            T100DEVICE_BLOCK*       block       = T100NULL;

            os      = offset % m_device_limit;
            block   = m_block_hash[id];

            block->data[os] = value;
            return T100TRUE;
        }
    }else if(offset < m_page_limit){
        T100WORD        id;

        id = offset / m_block_limit;
        if(id > m_pages.size()){
            return T100FALSE;
        }

        T100PageDevice* dev = (T100PageDevice*)m_pages[id-1];
        if(dev){
            T100WORD                os;
            T100DEVICE_PAGE*        page        = T100NULL;

            os      = offset % m_block_limit;
            page    = m_page_hash[id];

            page->data[os] = value;
            return T100TRUE;
        }
    }

    return result;
}

T100BOOL T100Port32::allotBlock(T100BlockDevice* dev, T100WORD length, T100WORD_VECTOR& blocks)
{
    T100BOOL            result          = T100TRUE;
    T100WORD            count;

    count = (length + m_device_limit - 1) / m_device_limit;

    for(int i=0;i<count;i++){
        if((m_device_limit - 1) <= m_blocks.size()){
            return T100FALSE;
        }

        T100DEVICE_BLOCK* data = T100NEW T100DEVICE_BLOCK();

        m_blocks.push_back(dev);
        data->id = m_blocks.size();
        m_block_hash[data->id] = data;
        blocks.push_back(m_blocks.size());
    }

    return result;
}

T100DEVICE_BLOCK* T100Port32::getBlock(T100WORD id)
{
    return m_block_hash[id];
}

T100BOOL T100Port32::allotPage(T100PageDevice* dev, T100WORD length, T100WORD_VECTOR& pages)
{
    T100BOOL            result          = T100TRUE;
    T100WORD            count;

    count = (length + m_block_limit - 1) / m_block_limit;

    for(int i=0;i<count;i++){
        if((m_block_limit - 1) <= m_pages.size()){
            return T100FALSE;
        }

        T100DEVICE_PAGE* data = T100NEW T100DEVICE_PAGE();

        m_pages.push_back(dev);
        data->id = m_pages.size();
        m_page_hash[data->id] = data;
        pages.push_back(m_pages.size());
    }

    return result;
}

T100DEVICE_PAGE* T100Port32::getPage(T100WORD id)
{
    return m_page_hash[id];
}


