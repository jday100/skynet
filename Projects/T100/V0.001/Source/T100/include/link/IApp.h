#ifndef IAPP_H
#define IAPP_H

#include "T100Common.h"
#include "IStore.h"
#include "IServe.h"
#include "IView.h"


class IApp
{
    public:
        IApp();
        virtual ~IApp();

        virtual T100BOOL        show()=0;

        virtual T100VOID        setServe(IServe*)=0;
        virtual IServe*         getServe()=0;

        virtual T100VOID        setView(IView*)=0;
        virtual IView*          getView()=0;

    protected:
        IStore*                 m_store         = T100NULL;
        IServe*                 m_serve         = T100NULL;
        IView*                  m_view          = T100NULL;

    private:

};

#endif // IAPP_H
