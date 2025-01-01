#ifndef T100PROJECTGIRDER_H
#define T100PROJECTGIRDER_H

#include "T100Common.h"
#include "T100ProjectStore.h"
#include "T100ProjectServe.h"
#include "T100ProjectView.h"

class T100ProjectGirder
{
    public:
        T100ProjectGirder();
        virtual ~T100ProjectGirder();

        T100VOID                    setStore(T100ProjectStore*);
        T100ProjectStore*           getStore();

        T100VOID                    setServe(T100ProjectServe*);
        T100ProjectServe*           getServe();

        T100VOID                    setView(T100ProjectView*);
        T100ProjectView*            getView();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100ProjectStore*           m_store         = T100NULL;
        T100ProjectServe*           m_serve         = T100NULL;
        T100ProjectView*            m_view          = T100NULL;
};

#endif // T100PROJECTGIRDER_H
