#ifndef T100CUDEVICE_H
#define T100CUDEVICE_H

#include "T100Device.h"
class IComputer;


enum T100CU_MODE{
    T100CUMODE_NONE         = T100DEVICEMODE_MAX,
    T100CUMODE_SET,
    T100CUMODE_GET,
    T100CUMODE_MAX
};


class T100CUDevice : public T100Device
{
    public:
        T100CUDevice(IComputer*);
        virtual ~T100CUDevice();

        T100WORD            in(T100WORD);
        T100VOID            out(T100WORD, T100WORD);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        IComputer*          m_host          = T100NULL;
};

#endif // T100CUDEVICE_H
