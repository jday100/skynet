#ifndef T100PROJECTPLATENBASE_H
#define T100PROJECTPLATENBASE_H

#include "T100Common.h"

class T100ProjectPlatenBase
{
    public:
        T100ProjectPlatenBase();
        virtual ~T100ProjectPlatenBase();

        virtual T100BOOL                    create() = 0;
        virtual T100BOOL                    destroy() = 0;

        virtual T100BOOL                    show() = 0;
        virtual T100BOOL                    hide() = 0;

    protected:

    private:
};

#endif // T100PROJECTPLATENBASE_H
