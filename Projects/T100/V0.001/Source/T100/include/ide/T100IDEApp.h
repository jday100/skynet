#ifndef T100IDEAPP_H
#define T100IDEAPP_H

#include "T100IDECommon.h"
#include "IApp.h"
#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"



class T100IDEApp : public IApp
{
    public:
        T100IDEApp();
        virtual ~T100IDEApp();

        T100BOOL            run(T100STDSTRING);

        T100BOOL            show();
        wxFrame*            getFrame();

        T100VOID            setStore(IStore*);
        IStore*             getStore();

        T100VOID            setServe(IServe*);
        IServe*             getServe();

        T100VOID            setView(IView*);
        IView*              getView();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100IDEAPP_H
