#ifndef T100VDISKAPP_H
#define T100VDISKAPP_H

#include "T100VDiskCommon.h"
#include "IApp.h"
#include "T100VDiskServe.h"
#include "T100VDiskView.h"


class T100VDiskApp : public IApp
{
    public:
        T100VDiskApp();
        virtual ~T100VDiskApp();

        T100BOOL            run(T100STDSTRING);

        T100BOOL            show();
        wxFrame*            getFrame();

        T100VOID            setServe(IServe*);
        IServe*             getServe();

        T100VOID            setView(IView*);
        IView*              getView();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100VDISKAPP_H
