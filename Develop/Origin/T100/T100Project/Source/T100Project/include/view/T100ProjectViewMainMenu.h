#ifndef T100PROJECTVIEWMAINMENU_H
#define T100PROJECTVIEWMAINMENU_H

#include "T100Common.h"

class T100ProjectFrame;

class T100ProjectViewMainMenu
{
    public:
        T100ProjectViewMainMenu();
        virtual ~T100ProjectViewMainMenu();

        virtual T100VOID            Create(T100ProjectFrame*);
        virtual T100VOID            Destroy();

    protected:
        T100ProjectFrame*           m_frame     = T100NULL;

    private:
};

#endif // T100PROJECTVIEWMAINMENU_H
