#ifndef IDEVICE_H
#define IDEVICE_H

#include "T100Common.h"
class IManager;


class IDevice
{
    public:
        IDevice();
        virtual ~IDevice();

        virtual T100BOOL    load(IManager*)=0;
        virtual T100BOOL    unload()=0;
        virtual T100BOOL    isLoaded();

        virtual T100WORD    in(T100WORD)=0;
        virtual T100VOID    out(T100WORD, T100WORD)=0;

    protected:
        T100BOOL            m_loaded        = T100FALSE;
        T100BYTE            m_id            = 0;
        IManager*           m_manager       = T100NULL;

    private:

};

#endif // IDEVICE_H
