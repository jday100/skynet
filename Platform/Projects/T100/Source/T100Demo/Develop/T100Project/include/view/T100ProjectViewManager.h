#ifndef T100PROJECTVIEWMANAGER_H
#define T100PROJECTVIEWMANAGER_H

#include <wx/docmdi.h>
#include <wx/aui/aui.h>
#include "T100Common.h"

class T100ProjectViewManager
{
    public:
        T100ProjectViewManager();
        virtual ~T100ProjectViewManager();

        wxAuiManager*               getAuiManager();
        wxDocManager*               getDocManager();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100VOID                    init();

    private:
        wxAuiManager*               m_aui           = T100NULL;
        wxDocManager*               m_doc           = T100NULL;
};

#endif // T100PROJECTVIEWMANAGER_H
