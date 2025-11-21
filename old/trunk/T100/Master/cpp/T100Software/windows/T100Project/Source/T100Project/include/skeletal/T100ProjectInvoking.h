#ifndef T100PROJECTINVOKING_H
#define T100PROJECTINVOKING_H

#include "T100ProjectSkeletal.h"

class T100ProjectApplication;

class T100ProjectInvoking
{
    public:
        T100ProjectInvoking();
        virtual ~T100ProjectInvoking();

        static T100ProjectApplication*          GetApplication();

        static T100VOID                         Create(T100ProjectApplication*);
        static T100VOID                         Destroy();

        static T100VOID                         BindMenu(const T100WSTRING&, T100UINT, T100EVENT_FUNCTION, T100EventHandler* = T100NULL);
        static T100VOID                         CallMenu(const T100WSTRING&, T100MenuEvent*);

        static T100VOID                         OnMainMenu(T100MenuEvent&);
        static T100VOID                         OnResize(T100WindowEvent&);

        static T100VOID                         New();
        static T100VOID                         Open();
        static T100VOID                         Close();
        static T100VOID                         Save();
        static T100VOID                         SaveAs();
        static T100VOID                         Quit();

        static T100VOID                         Undo();
        static T100VOID                         Redo();
        static T100VOID                         Cut();
        static T100VOID                         Copy();
        static T100VOID                         Paste();

        static T100VOID                         Find();
        static T100VOID                         Replace();

        static T100VOID                         About();

    protected:

    private:
        static T100ProjectApplication*          m_application;
};

#endif // T100PROJECTINVOKING_H
