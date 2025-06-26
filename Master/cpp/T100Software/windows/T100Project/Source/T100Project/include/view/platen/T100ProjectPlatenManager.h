#ifndef T100PROJECTPLATENMANAGER_H
#define T100PROJECTPLATENMANAGER_H

#include "T100ProjectPlatenBase.h"

class T100ProjectPlatenManager
{
    public:
        T100ProjectPlatenManager();
        virtual ~T100ProjectPlatenManager();

        virtual T100VOID            Update(T100UINT);

    protected:

    private:
};

#endif // T100PROJECTPLATENMANAGER_H
