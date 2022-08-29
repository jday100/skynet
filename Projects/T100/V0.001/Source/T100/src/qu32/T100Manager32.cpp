#include "T100Manager32.h"

#include "T100QU32Setup.h"
#include "T100HintQU32.h"
#include "T100QU32Callback.h"
#include "T100QU32.h"


T100Manager32::T100Manager32(T100QU32* host)
    :m_host(host), IManager((IComputer*)host)
{
    //ctor
}

T100Manager32::~T100Manager32()
{
    //dtor
    destroy();
}

T100QU32* T100Manager32::getHost32()
{
    return m_host;
}

T100BOOL T100Manager32::init()
{
    create();
    return T100TRUE;
}

T100VOID T100Manager32::create()
{
    T100Log::trace(T100QU32_HINT_MANAGER_START);

    m_cu        = T100NEW T100CUDevice(m_host);
    m_au        = T100NEW T100AUDevice(m_host);
    m_memory    = T100NEW T100MemoryDevice(m_host);
    m_io        = T100NEW T100IODevice(m_host);
}

T100VOID T100Manager32::destroy()
{
    T100DELETE(m_io);
    T100DELETE(m_memory);
    T100DELETE(m_au);
    T100DELETE(m_cu);

    T100Log::trace(T100QU32_HINT_MANAGER_STOP);
}

T100BOOL T100Manager32::addDevice(T100BYTE& id, IDevice* dev)
{
    T100BOOL    result;
    int         value;

    T100Log::debug(T100QU32_HINT_MANAGER_ADD_DEVICE);

    value = m_devices.size() - m_size;

    if(1 <= value){
        return T100FALSE;
    }

    result = dev->load(this);
    if(result){
        m_devices.push_back(dev);
        id = m_devices.size() - 1;
    }

    return result;
}

T100BOOL T100Manager32::removeDevice(T100BYTE id)
{
    T100BOOL result;

    T100Log::debug(T100QU32_HINT_MANAGER_REMOVE_DEVICE);

    if(id < m_devices.size()){
        result = m_devices[id]->unload();
        if(!result){
            return T100FALSE;
        }

        T100Device* dev = (T100Device*)m_devices[id];
        //T100DELETE(dev);
        m_devices[id] = T100NULL;
        return T100TRUE;
    }

    return T100FALSE;
}

IDevice* T100Manager32::getDevice(T100BYTE id)
{
    T100Device* result = NULL;

    if(id < m_devices.size()){
        result = (T100Device*)m_devices[id];
    }

    return result;
}

T100WORD T100Manager32::in(T100WORD offset)
{
    if(offset < m_device_limit){
        T100BYTE    id;

        id = offset >> 2;

        T100Device* dev = (T100Device*)getDevice(id);

        if(dev){
            id = offset & 3;

            return dev->in(id);
        }else{

        }
    }else if(offset < m_block_limit){
        T100WORD    id;

        id = offset / m_device_limit;

        if(id > m_block.size()){
            return 0;
        }

        T100BlockDevice* dev = (T100BlockDevice*)m_block[id-1];
        if(dev){
            T100WORD            os;
            T100DEVICE_BLOCK    *block;

            os = offset % m_device_limit;
            block = m_blocks[id];

            return block->data[os];
        }else{

        }
    }else if(offset < m_page_limit){
        T100WORD    id;

        id = offset / m_block_limit;

        if(id > m_page.size()){
            return 0;
        }

        T100PageDevice* dev = (T100PageDevice*)m_page[id-1];
        if(dev){
            T100WORD            os;
            T100DEVICE_PAGE     *page;

            os = offset % m_block_limit;
            page = m_pages[id];

            return page->data[os];
        }else{

        }
    }

    return 0;
}

T100VOID T100Manager32::out(T100WORD offset, T100WORD value)
{
    if(offset < m_device_limit){
        T100BYTE    id;

        id = offset >> 2;
        T100Device* dev = (T100Device*)getDevice(id);
        if(dev){
            id = offset & 3;

            dev->out(id, value);

            if(T100QU32Setup::DEBUG){
                //wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_DEVICE_UPDATE);
                //wxQueueEvent(m_host->getExecutor32()->m_frame, event.Clone());
                T100QU32Callback::callDebugDevice();
            }
            if(m_device_window){
                if(offset >= m_device_window_begin && offset <= m_device_window_end){
                    if(T100QU32Setup::DEBUG){
                        //wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_DEVICE_UPDATE);
                        //wxQueueEvent(m_host->getExecutor32()->m_frame, event.Clone());
                        T100QU32Callback::callDebugDevice();
                    }
                }
            }
        }else{

        }
    }else if(offset < m_block_limit){
        T100WORD    id;

        id = offset / m_device_limit;
        if(id > m_block.size()){
            return;
        }
        T100BlockDevice* dev = (T100BlockDevice*)m_block[id-1];
        if(dev){
            T100WORD    os;

            os = offset % m_device_limit;

            dev->out(id, os, value);

            if(T100QU32Setup::DEBUG){
                //wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_BLOCK_BASE_UPDATE);
                //wxQueueEvent(m_host->getExecutor32()->m_frame, event.Clone());
                T100QU32Callback::callDebugBlock();
            }

            if(m_block_window){
                if(offset >= m_block_window_begin && offset <= m_block_window_end){
                    if(T100QU32Setup::DEBUG){
                        //wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_BLOCK_BASE_UPDATE);
                        //wxQueueEvent(m_host->getExecutor32()->m_frame, event.Clone());
                        T100QU32Callback::callDebugBlock();
                    }
                }
            }
        }else{

        }
    }else if(offset < m_page_limit){
        T100WORD        id;

        id = offset / m_block_limit;
        if(id > m_page.size()){
            return;
        }

        T100PageDevice* dev = (T100PageDevice*)m_page[id-1];
        if(dev){
            T100WORD            os;
            T100DEVICE_PAGE     *page;

            os = offset % m_block_limit;
            page = m_pages[id];

            page->data[os] = value;

            if(T100QU32Setup::DEBUG){
                //wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_PAGE_BASE_UPDATE);
                //wxQueueEvent(m_host->getExecutor32()->m_frame, event.Clone());
                T100QU32Callback::callDebugPage();
            }
            if(m_page_window){
                if(offset >= m_page_window_begin && offset <= m_page_window_end){
                    if(T100QU32Setup::DEBUG){
                        //wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_PAGE_BASE_UPDATE);
                        //wxQueueEvent(m_host->getExecutor32()->m_frame, event.Clone());
                        T100QU32Callback::callDebugPage();
                    }
                }
            }
        }else{

        }
    }
}

T100BOOL T100Manager32::allotBlock(IBlockDevice* dev, T100WORD length, T100WORD_VECTOR& block)
{
    T100WORD        count;

    count = (length + m_device_limit - 1) / m_device_limit;

    for(int i=0;i<count;i++){
        if(1023 <= m_block.size()){
            return T100FALSE;
        }

        T100DEVICE_BLOCK* data = T100NEW T100DEVICE_BLOCK();

        m_block.push_back(dev);
        data->id = m_block.size();
        m_blocks[data->id] = data;
        block.push_back(m_block.size());
    }

    return T100TRUE;
}

T100DEVICE_BLOCK* T100Manager32::getBlock(T100WORD id)
{
    return m_blocks[id];
}

T100BOOL T100Manager32::allotPage(IPageDevice* dev, T100WORD length, T100WORD_VECTOR& page)
{
    T100WORD        count;

    count = (length + m_block_limit - 1) / m_block_limit;

    for(int i=0;i<count;i++){
        if(1023 <= m_page.size()){
            return T100FALSE;
        }

        T100DEVICE_PAGE* data = T100NEW T100DEVICE_PAGE();

        m_page.push_back(dev);
        data->id = m_page.size();
        m_pages[data->id] = data;
        page.push_back(m_page.size());
    }

    return T100TRUE;
}

T100DEVICE_PAGE* T100Manager32::getPage(T100WORD id)
{
    return m_pages[id];
}

T100BOOL T100Manager32::openDeviceWindow(T100WORD begin, T100WORD end)
{
    T100BOOL    result      = T100FALSE;

    if(begin >= m_device_limit){
        return T100FALSE;
    }

    if(end < begin || end >= m_device_limit){
        return T100FALSE;
    }
    m_device_window_begin   = begin;
    m_device_window_end     = end;
    m_device_window         = T100TRUE;

    return T100TRUE;
}

T100BOOL T100Manager32::closeDeviceWindow()
{
    if(!m_device_window){
        return T100FALSE;
    }

    m_device_window_begin   = 0;
    m_device_window_end     = 0;

    m_device_window         = T100FALSE;

    return T100TRUE;
}

T100BOOL T100Manager32::openBlockWindow(T100WORD begin, T100WORD end)
{
    T100BOOL    result      = T100FALSE;

    if(begin < m_device_limit || begin >= m_block_limit){
        return T100FALSE;
    }

    if(end < begin || end < m_device_limit || end >= m_block_limit){
        return T100FALSE;
    }
    m_block_window_begin    = begin;
    m_block_window_end      = end;
    m_block_window          = T100TRUE;

    return T100TRUE;
}

T100BOOL T100Manager32::closeBlockWindow()
{
    if(!m_block_window){
        return T100FALSE;
    }

    m_block_window_begin    = 0;
    m_block_window_end      = 0;

    m_block_window          = T100FALSE;

    return T100TRUE;
}

T100BOOL T100Manager32::openPageWindow(T100WORD begin, T100WORD end)
{
    T100BOOL    result      = T100FALSE;

    if(begin < m_block_limit || begin >= m_page_limit){
        return T100FALSE;
    }

    if(end < begin || end < m_block_limit || end >= m_page_limit){
        return T100FALSE;
    }
    m_page_window_begin     = begin;
    m_page_window_end       = end;
    m_page_window           = T100TRUE;

    return T100TRUE;
}

T100BOOL T100Manager32::closePageWindow()
{
    if(!m_page_window){
        return T100FALSE;
    }

    m_page_window_begin     = 0;
    m_page_window_end       = 0;

    m_page_window           = T100FALSE;

    return T100TRUE;
}
