#ifndef T100PORT32_H
#define T100PORT32_H

#include "T100VPCCommon.h"
#include "T100CUDevice.h"
#include "T100AUDevice.h"
#include "T100MemoryDevice.h"
#include "T100PortDevice.h"
class T100QU32;
class T100BlockDevice;
class T100PageDevice;


class T100Port32
{
    public:
        T100Port32(T100QU32*);
        virtual ~T100Port32();

        T100VOID                create();

        T100BOOL                appendDevice(T100BYTE&, T100Device*);
        T100BOOL                removeDevice(T100BYTE);
        T100Device*             getDevice(T100BYTE);

        T100BOOL                in(T100WORD, T100WORD&);
        T100BOOL                out(T100WORD, T100WORD);

        T100BOOL                allotBlock(T100BlockDevice*, T100WORD, T100WORD_VECTOR&);
        T100DEVICE_BLOCK*       getBlock(T100WORD);

        T100BOOL                allotPage(T100PageDevice*, T100WORD, T100WORD_VECTOR&);
        T100DEVICE_PAGE*        getPage(T100WORD);

    protected:
        T100VOID                destroy();



    private:
        T100QU32*               m_host          = T100NULL;

        T100CUDevice*           m_cu            = T100NULL;
        T100AUDevice*           m_au            = T100NULL;
        T100MemoryDevice*       m_memory        = T100NULL;
        T100PortDevice*         m_port          = T100NULL;

        T100DEVICE_VECTOR       m_devices;
        T100DEVICE_VECTOR       m_blocks;
        T100DEVICE_VECTOR       m_pages;


        T100BYTE                m_device_limit          = 255;
        T100WORD                m_port_limit            = 1024;
        T100WORD                m_block_limit           = 1024 * 1024;
        T100WORD                m_page_limit            = 1024 * 1024 * 1024;


};

#endif // T100PORT32_H
