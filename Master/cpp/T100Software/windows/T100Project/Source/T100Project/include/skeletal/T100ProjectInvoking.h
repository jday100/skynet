#ifndef T100PROJECTINVOKING_H
#define T100PROJECTINVOKING_H

#include "T100ProjectSkeletal.h"

class T100ProjectApplication;

class T100ProjectInvoking
{
    public:
        T100ProjectInvoking();
        virtual ~T100ProjectInvoking();

        static T100VOID                         Create(T100ProjectApplication*);
        static T100VOID                         Destroy();

        static T100VOID                         BindMenu(const T100WSTRING&, T100UINT, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);
        static T100VOID                         CallMenu(const T100WSTRING&, T100MenuEvent*);

        static T100VOID                         OnMainMenu(T100MenuEvent&);
        static T100VOID                         OnResize(T100WindowEvent&);

        static T100VOID                         Quit();

    protected:

    private:
        static T100ProjectApplication*          m_application;
};

#endif // T100PROJECTINVOKING_H
