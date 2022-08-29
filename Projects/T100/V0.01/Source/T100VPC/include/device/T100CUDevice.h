#ifndef T100CUDEVICE_H
#define T100CUDEVICE_H

#include "T100DeviceTypes.h"
#include "T100Device.h"
class T100QU32;


typedef enum{
    T100CUMODE_NONE             = T100DEVICEMODE_MAX,
    T100CUMODE_SET,
    T100CUMODE_GET,
    T100CUMODE_MAX
}T100CU_MODE;


class T100CUDevice : public T100Device
{
    public:
        T100CUDevice(T100QU32*);
        virtual ~T100CUDevice();

        T100BOOL                load(T100Port32*);
        T100BOOL                unload();

        T100BOOL                in(T100WORD, T100WORD&);
        T100BOOL                out(T100WORD, T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
};

#endif // T100CUDEVICE_H
