#ifndef T100IODEVICE_H
#define T100IODEVICE_H

#include "T100Device.h"
class IComputer;


enum T100IO_MODE{
    T100IOMODE_NONE             = T100DEVICEMODE_MAX,
    T100IOMODE_SET,
    T100IOMODE_GET,
    T100IOMODE_BLOCK,
    T100IOMODE_PAGE,
    T100IOMODE_MAX
};


class T100IODevice : public T100Device
{
    public:
        T100IODevice(IComputer*);
        virtual ~T100IODevice();

        T100WORD                in(T100WORD);
        T100VOID                out(T100WORD, T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        IComputer*              m_host          = T100NULL;
};

#endif // T100IODEVICE_H
