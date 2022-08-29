#ifndef T100FONTAPP_H
#define T100FONTAPP_H

#include "T100FontCommon.h"
#include "IApp.h"
#include "T100FontServe.h"
#include "T100FontView.h"


class T100FontApp : public IApp
{
    public:
        T100FontApp();
        virtual ~T100FontApp();

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

#endif // T100FONTAPP_H
