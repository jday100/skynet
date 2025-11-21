#ifndef T100EXTENSIONDOCK_H
#define T100EXTENSIONDOCK_H

#include "T100Extension.h"

class wxAuiManager;

class T100ExtensionDock : public T100Extension
{
    public:
        T100ExtensionDock();
        virtual ~T100ExtensionDock();

        T100VOID            SetDockManager(wxAuiManager*);
        wxAuiManager*       GetDockManager();

    protected:
        wxAuiManager*       m_dockManager       = T100NULL;

    private:
};

#endif // T100EXTENSIONDOCK_H
