#ifndef T100IDEAPP_H
#define T100IDEAPP_H

#include "T100WxApp.h"
class T100ThisAppManager;

namespace T100IDE{
class T100IDE;


class T100IDEApp : public T100WxWidgets::T100WxApp
{
    public:
        T100IDEApp(T100ThisAppManager*, T100BOOL = T100FALSE);
        virtual ~T100IDEApp();

        T100VOID            show();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100IDE*            m_ide               = T100NULL;

};

}

#endif // T100IDEAPP_H
