#ifndef T100PROJECTDEFAULTPLATEN_H
#define T100PROJECTDEFAULTPLATEN_H

#include "T100ProjectPlatenBase.h"

class T100ProjectDefaultPlaten : public T100ProjectPlatenBase
{
    public:
        T100ProjectDefaultPlaten();
        virtual ~T100ProjectDefaultPlaten();

        T100BOOL            create();
        T100BOOL            destroy();

        T100BOOL            show();
        T100BOOL            hide();

    protected:

    private:
};

#endif // T100PROJECTDEFAULTPLATEN_H
