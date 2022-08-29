#ifndef T100VPCAPP_H
#define T100VPCAPP_H

#include "T100VPCCommon.h"
#include "IApp.h"
#include "T100VPCServe.h"
#include "T100VPCView.h"
class T100App;


class T100VPCApp : public IApp
{
    friend class T100VPCTest;
    friend class T100VPCFrame;
    public:
        T100VPCApp();
        virtual ~T100VPCApp();

        T100BOOL            run(T100App*, T100STDSTRING, T100WORD offset = 0);
        T100VOID            setQuit(T100BOOL);
        T100BOOL            quit();

        T100BOOL            show();
        wxFrame*            getFrame();

        T100VOID            setServe(IServe*);
        IServe*             getServe();

        T100VOID            setView(IView*);
        IView*              getView();

        T100WORD            getReturn();

        T100BOOL            add(T100STDSTRING, T100WORD);

        T100BOOL            run(T100App*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100BOOL            run(T100WORD_VECTOR&, T100DWORD);
};

#endif // T100VPCAPP_H
