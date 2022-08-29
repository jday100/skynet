#ifndef IVIEW_H
#define IVIEW_H

#include "IServe.h"


class IView
{
    public:
        IView();
        virtual ~IView();

        virtual T100VOID        setServe(IServe*);
        virtual IServe*         getServe();

        virtual T100VOID        create()=0;

        virtual T100BOOL        show()=0;

    protected:

    private:
        IServe*                 m_serve         = T100NULL;
};

#endif // IVIEW_H
