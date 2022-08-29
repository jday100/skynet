#ifndef T100MEMORYDEVICE_H
#define T100MEMORYDEVICE_H

#include "T100Device.h"
class IComputer;


enum T100MEMORY_MODE{
    T100MEMORYMODE_NONE             = T100DEVICEMODE_MAX,
    T100MEMORYMODE_SET,
    T100MEMORYMODE_GET,
    T100MEMORYMODE_ROM,
    T100MEMORYMODE_RAM,
    T100MEMORYMODE_MAX
};


class T100MemoryDevice : public T100Device
{
    public:
        T100MemoryDevice(IComputer*);
        virtual ~T100MemoryDevice();

        T100WORD                in(T100WORD);
        T100VOID                out(T100WORD, T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        IComputer*              m_host          = T100NULL;
};

#endif // T100MEMORYDEVICE_H
