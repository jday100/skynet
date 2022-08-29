#ifndef T100AUDEVICE_H
#define T100AUDEVICE_H

#include "T100Device.h"
class IComputer;

enum T100AU_MODE{
    T100AUMODE_NONE     = T100DEVICEMODE_MAX,
    T100AUMODE_SET,
    T100AUMODE_GET,
    T100AUMODE_MAX
};


class T100AUDevice : public T100Device
{
    public:
        T100AUDevice(IComputer*);
        virtual ~T100AUDevice();

        T100WORD            in(T100WORD);
        T100VOID            out(T100WORD, T100WORD);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        IComputer*          m_host          = T100NULL;
};

#endif // T100AUDEVICE_H
