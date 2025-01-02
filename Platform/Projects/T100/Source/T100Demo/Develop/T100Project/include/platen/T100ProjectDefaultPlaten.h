#ifndef T100PROJECTDEFAULTPLATEN_H
#define T100PROJECTDEFAULTPLATEN_H

#include "T100ProjectPlatenBase.h"

class T100ProjectDefaultPlaten : public T100ProjectPlatenBase
{
    public:
        T100ProjectDefaultPlaten(T100ProjectView*);
        virtual ~T100ProjectDefaultPlaten();

        T100BOOL            create();
        T100BOOL            destroy();

        T100BOOL            show();
        T100BOOL            hide();

    protected:
        T100BOOL            create_menu();

    private:
};

#endif // T100PROJECTDEFAULTPLATEN_H
