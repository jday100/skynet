#ifndef IMANAGER_H
#define IMANAGER_H

#include "T100DataTypes.h"
#include "T100DeviceTypes.h"
#include "IBlockDevice.h"
#include "IPageDevice.h"
class IComputer;


class IManager
{
    public:
        IManager(IComputer*);
        virtual ~IManager();

        virtual T100BOOL            addDevice(T100BYTE&, IDevice*)=0;
        virtual T100BOOL            removeDevice(T100BYTE)=0;
        virtual IDevice*            getDevice(T100BYTE)=0;

        virtual T100WORD            in(T100WORD)=0;
        virtual T100VOID            out(T100WORD, T100WORD)=0;

        virtual T100BOOL            allotBlock(IBlockDevice*, T100WORD, T100WORD_VECTOR&)=0;
        virtual T100DEVICE_BLOCK*   getBlock(T100WORD)=0;

        virtual T100BOOL            allotPage(IPageDevice*, T100WORD, T100WORD_VECTOR&)=0;
        virtual T100DEVICE_PAGE*    getPage(T100WORD)=0;

    protected:

    private:
        IComputer*                  m_host              = T100NULL;
};

#endif // IMANAGER_H
