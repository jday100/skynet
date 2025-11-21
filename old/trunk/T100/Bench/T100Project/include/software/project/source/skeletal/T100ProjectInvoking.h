#ifndef T100PROJECTINVOKING_H
#define T100PROJECTINVOKING_H

#include <wx/event.h>
#include "T100Common.h"

class T100ProjectFrame;
class T100ProjectApplication;

class T100ProjectInvoking
{
    public:
        T100ProjectInvoking();
        virtual ~T100ProjectInvoking();

        static T100VOID             Init(T100ProjectFrame*);
        static T100VOID             Uninit();

        static T100VOID             OnMainMenu(wxCommandEvent&);

        static T100VOID             OnQuit();

    protected:

    private:
        static T100ProjectApplication*          m_application;
};

#endif // T100PROJECTINVOKING_H
