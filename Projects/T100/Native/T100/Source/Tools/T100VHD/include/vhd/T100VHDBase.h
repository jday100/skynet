#ifndef T100VHDBASE_H
#define T100VHDBASE_H

#include "T100Common.h"
#include "T100VHDCommon.h"
#include "T100WXRunThread.h"
#include "T100VDiskCallback.h"


class T100VHDBase
{
    public:
        T100VHDBase();
        virtual ~T100VHDBase();

        virtual T100BOOL            create(T100VHD_STORAGE_TYPE) = 0;
        virtual T100VOID            cancel() = 0;

        virtual T100VOID            setValue(T100VOID*) = 0;

        virtual T100VOID            setCallback(T100VDiskCallback*);

    protected:
        T100VDiskCallback*          m_callback          = T100NULL;

    private:
};

#endif // T100VHDBASE_H
