#ifndef IBLOCKDEVICE_H
#define IBLOCKDEVICE_H

#include "T100Device.h"


class IBlockDevice : public T100Device
{
    public:
        IBlockDevice();
        virtual ~IBlockDevice();

        virtual T100BOOL        load(IManager*);

    protected:

    private:
};

#endif // IBLOCKDEVICE_H
