#ifndef IPAGEDEVICE_H
#define IPAGEDEVICE_H

#include "T100Device.h"


class IPageDevice : public T100Device
{
    public:
        IPageDevice();
        virtual ~IPageDevice();

    protected:

    private:
};

#endif // IPAGEDEVICE_H
