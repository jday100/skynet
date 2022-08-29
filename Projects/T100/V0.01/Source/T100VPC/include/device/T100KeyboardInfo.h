#ifndef T100KEYBOARDINFO_H
#define T100KEYBOARDINFO_H

#include "T100DeviceInfo.h"


class T100KeyboardInfo : public T100DeviceInfo
{
    public:
        T100KeyboardInfo();
        virtual ~T100KeyboardInfo();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100KEYBOARDINFO_H
