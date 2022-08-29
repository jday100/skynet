#ifndef T100MANAGER32_H
#define T100MANAGER32_H

#include "IManager.h"
#include "T100BlockDevice.h"
#include "T100PageDevice.h"
#include "T100CUDevice.h"
#include "T100AUDevice.h"
#include "T100MemoryDevice.h"
#include "T100IODevice.h"
class T100QU32;


class T100Manager32 : public IManager
{
    public:
        T100Manager32(T100QU32*);
        virtual ~T100Manager32();

        T100QU32*           getHost32();

        T100BOOL            init();

        T100BOOL            addDevice(T100BYTE&, IDevice*);
        T100BOOL            removeDevice(T100BYTE);
        IDevice*            getDevice(T100BYTE);

        T100WORD            in(T100WORD);
        T100VOID            out(T100WORD, T100WORD);

        T100BOOL            allotBlock(IBlockDevice*, T100WORD, T100WORD_VECTOR&);
        T100DEVICE_BLOCK*   getBlock(T100WORD);

        T100BOOL            allotPage(IPageDevice*, T100WORD, T100WORD_VECTOR&);
        T100DEVICE_PAGE*    getPage(T100WORD);

        T100BOOL            openDeviceWindow(T100WORD, T100WORD);
        T100BOOL            closeDeviceWindow();
        T100BOOL            openBlockWindow(T100WORD, T100WORD);
        T100BOOL            closeBlockWindow();
        T100BOOL            openPageWindow(T100WORD, T100WORD);
        T100BOOL            closePageWindow();

    protected:
        T100BLOCK_HASH      m_blocks;
        T100PAGE_HASH       m_pages;

        T100VOID            create();
        T100VOID            destroy();

    private:
        T100QU32*           m_host          = T100NULL;
        T100CUDevice*       m_cu            = T100NULL;
        T100AUDevice*       m_au            = T100NULL;
        T100MemoryDevice*   m_memory        = T100NULL;
        T100IODevice*       m_io            = T100NULL;

        T100DEVICE_VECTOR   m_devices;
        T100DEVICE_VECTOR   m_block;
        T100DEVICE_VECTOR   m_page;

        T100BYTE            m_size          = 255;
        T100WORD            m_device_limit  = 1024;
        T100WORD            m_block_limit   = 1024 * 1024;
        T100WORD            m_page_limit    = 1024 * 1024 * 1024;

        T100BOOL            m_device_window = T100FALSE;
        T100BOOL            m_block_window  = T100FALSE;
        T100BOOL            m_page_window   = T100FALSE;

        T100WORD            m_device_window_begin   = 0;
        T100WORD            m_device_window_end     = 0;
        T100WORD            m_block_window_begin    = 0;
        T100WORD            m_block_window_end      = 0;
        T100WORD            m_page_window_begin     = 0;
        T100WORD            m_page_window_end       = 0;
};

#endif // T100MANAGER32_H
