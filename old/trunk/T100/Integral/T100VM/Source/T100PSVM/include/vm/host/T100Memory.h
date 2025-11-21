#ifndef T100MEMORY_H
#define T100MEMORY_H

#include "T100Device.h"

class T100Memory : public T100Device
{
    public:
        T100Memory();
        virtual ~T100Memory();

    protected:
        T100BYTE_VECTOR         m_rom;
        T100BYTE_VECTOR         m_ram;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100MEMORY_H
