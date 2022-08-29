#ifndef T100PORTDEVICE_H
#define T100PORTDEVICE_H

#include "T100DeviceTypes.h"
#include "T100Device.h"

typedef enum{
    T100PORTMODE_NONE           = T100DEVICEMODE_MAX,
    T100PORTMODE_SET,
    T100PORTMODE_GET,
    T100PORTMODE_BLOCK,
    T100PORTMODE_PAGE,
    T100PORTMODE_MAX
}T100PORT_MODE;


class T100PortDevice : public T100Device
{
    public:
        T100PortDevice(T100QU32*);
        virtual ~T100PortDevice();

        T100BOOL                load(T100Port32*);
        T100BOOL                unload();

        T100BOOL                in(T100WORD, T100WORD&);
        T100BOOL                out(T100WORD, T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
};

#endif // T100PORTDEVICE_H
