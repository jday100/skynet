#ifndef T100EXTENSIONPANEL_H
#define T100EXTENSIONPANEL_H

#include "T100Extension.h"

class wxPanel;

class T100ExtensionPanel : public T100Extension
{
    public:
        T100ExtensionPanel();
        virtual ~T100ExtensionPanel();

        T100VOID            SetPanel(wxPanel*);
        wxPanel*            GetPanel();

    protected:
        wxPanel*            m_panel         = T100NULL;

    private:
};

#endif // T100EXTENSIONPANEL_H
