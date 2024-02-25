#ifndef T100VHDBASE_H
#define T100VHDBASE_H

#include "T100Common.h"
#include "T100VHDCommon.h"
#include "T100WXRunThread.h"


class T100VHDBase
{
    public:
        T100VHDBase();
        virtual ~T100VHDBase();

        virtual T100BOOL            create(T100VHD_STORAGE_TYPE) = 0;
        virtual T100VOID            cancel() = 0;

        virtual T100VOID            setValue(T100VOID*) = 0;
        virtual T100VOID            setCreateCallback(T100THREAD_CALLBACK) = 0;

    protected:

    private:
};

#endif // T100VHDBASE_H
