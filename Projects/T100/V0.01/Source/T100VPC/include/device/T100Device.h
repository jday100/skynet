#ifndef T100DEVICE_H
#define T100DEVICE_H

#include <atomic>
#include "T100VPCCommon.h"
#include "T100String.h"
class T100QU32;
class T100Port32;
class T100Device;


class T100Device
{
    public:
        T100Device(T100QU32*);
        virtual ~T100Device();

        T100VOID                    setName(T100String);
        T100STRING                  getName();

        T100DEVICE_TYPE             getType();

        virtual T100BOOL            load(T100Port32*) = 0;
        virtual T100BOOL            unload() = 0;
        virtual T100BOOL            isLoaded();

        virtual T100BOOL            in(T100WORD, T100WORD&) = 0;
        virtual T100BOOL            out(T100WORD, T100WORD) = 0;

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100WORD                    m_data[4];
        T100BYTE                    m_id            = 0;
        T100QU32*                   m_host          = T100NULL;
        T100Port32*                 m_port          = T100NULL;

    private:
        std::atomic_bool            m_loaded;
        T100STRING                  m_name;
        T100DEVICE_TYPE             m_type          = T100DEVICE_NONE;

};

#endif // T100DEVICE_H
