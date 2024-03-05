#ifndef T100PROJECTAPP_H
#define T100PROJECTAPP_H

#include "T100WxApp.h"
class T100ThisAppManager;

namespace T100PROJECT{
class T100Project;

class T100ProjectApp : public T100WxWidgets::T100WxApp
{
    public:
        T100ProjectApp(T100ThisAppManager*, T100BOOL = T100FALSE);
        virtual ~T100ProjectApp();

        T100VOID            show();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100Project*        m_project           = T100NULL;
};

}

#endif // T100PROJECTAPP_H
