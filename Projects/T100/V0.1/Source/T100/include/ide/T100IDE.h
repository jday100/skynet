#ifndef T100IDE_H
#define T100IDE_H

#include "T100Common.h"

namespace T100IDE{
class T100IDEApp;
class T100IDEServe;
class T100IDEView;


class T100IDE
{
    public:
        T100IDE(T100IDEApp* = T100NULL);
        virtual ~T100IDE();

        T100VOID            setServe(T100IDEServe*);
        T100IDEServe*       getServe();

        T100VOID            setView(T100IDEView*);
        T100IDEView*        getView();

        T100VOID            show();
        T100VOID            quit();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100IDEApp*         m_app           = T100NULL;
        T100IDEServe*       m_serve         = T100NULL;
        T100IDEView*        m_view          = T100NULL;

};

}

#endif // T100IDE_H
