#ifndef T100PROJECTVIEW_H
#define T100PROJECTVIEW_H

#include "T100Common.h"

class T100ProjectFrame;

class T100ProjectView
{
    public:
        T100ProjectView();
        virtual ~T100ProjectView();

        virtual T100VOID            Create(T100ProjectFrame*);
        virtual T100VOID            Destroy();

    protected:
        T100ProjectFrame*           m_frame     = T100NULL;

    private:
};

#endif // T100PROJECTVIEW_H
