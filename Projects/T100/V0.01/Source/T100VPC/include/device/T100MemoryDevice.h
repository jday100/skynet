#ifndef T100MEMORYDEVICE_H
#define T100MEMORYDEVICE_H

#include "T100DeviceTypes.h"
#include "T100Device.h"
class T100QU32;

typedef enum{
    T100MEMORYMODE_NONE             = T100DEVICEMODE_MAX,
    T100MEMORYMODE_SET,
    T100MEMORYMODE_GET,
    T100MEMORYMODE_ROM,
    T100MEMORYMODE_RAM,
    T100MEMORYMODE_MAX
}T100MEMORY_MODE;


class T100MemoryDevice : public T100Device
{
    public:
        T100MemoryDevice(T100QU32*);
        virtual ~T100MemoryDevice();

        T100BOOL                load(T100Port32*);
        T100BOOL                unload();

        T100BOOL                in(T100WORD, T100WORD&);
        T100BOOL                out(T100WORD, T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
};

#endif // T100MEMORYDEVICE_H
