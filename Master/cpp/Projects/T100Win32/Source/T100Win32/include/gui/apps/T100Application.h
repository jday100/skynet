#ifndef T100APPLICATION_H
#define T100APPLICATION_H

#include "gui/apps/T100ApplicationBase.h"

class T100Application : public T100ApplicationBase
{
    public:
        T100Application();
        virtual ~T100Application();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

    protected:

    private:
};

#endif // T100APPLICATION_H
