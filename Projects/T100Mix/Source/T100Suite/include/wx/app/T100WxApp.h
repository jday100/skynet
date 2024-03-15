#ifndef T100WXAPP_H
#define T100WXAPP_H

#include "T100WxStore.h"
#include "T100WxServe.h"
#include "T100WxView.h"
#include "app\T100App.h"

class T100WxApp : public T100App
{
    public:
        T100WxApp();
        virtual ~T100WxApp();

        T100VOID                    setStore(T100WxStore*);
        T100WxStore*                getStore();
        T100VOID                    setServe(T100WxServe*);
        T100WxServe*                getServe();
        T100VOID                    setView(T100WxView*);
        T100WxView*                 getView();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100WxStore*                m_store         = T100NULL;
        T100WxServe*                m_serve         = T100NULL;
        T100WxView*                 m_view          = T100NULL;
};

#endif // T100WXAPP_H
