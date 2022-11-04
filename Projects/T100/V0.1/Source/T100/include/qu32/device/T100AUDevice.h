#ifndef T100AUDEVICE_H
#define T100AUDEVICE_H

#include "T100Device.h"

namespace T100QU32{

typedef enum{
    T100AUMODE_NONE         = T100Component::T100DEVICEMODE_MAX,
    T100AUMODE_SET,
    T100AUMODE_GET,
    T100AUMODE_MAX
}T100AU_MODE;


class T100AUDevice : public T100Device
{
    public:
        T100AUDevice(T100QU32*);
        virtual ~T100AUDevice();

        T100BOOL            load(T100Port32*);
        T100BOOL            unload();

        T100BOOL            in(T100WORD, T100WORD&);
        T100BOOL            out(T100WORD, T100WORD);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

}

#endif // T100AUDEVICE_H
