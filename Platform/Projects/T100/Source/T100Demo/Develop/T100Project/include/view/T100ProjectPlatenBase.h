#ifndef T100PROJECTPLATENBASE_H
#define T100PROJECTPLATENBASE_H

#include "T100Common.h"
#include "T100ProjectView.h"

class T100ProjectPlatenBase
{
    public:
        T100ProjectPlatenBase(T100ProjectView*);
        virtual ~T100ProjectPlatenBase();

        virtual T100BOOL                    create() = 0;
        virtual T100BOOL                    destroy() = 0;

        virtual T100BOOL                    show() = 0;
        virtual T100BOOL                    hide() = 0;

    protected:
        T100ProjectView*                    m_view              = T100NULL;

    private:
};

#endif // T100PROJECTPLATENBASE_H
