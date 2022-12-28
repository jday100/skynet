#ifndef T100IDEVIEWMANAGER_H
#define T100IDEVIEWMANAGER_H

#include <wx/docmdi.h>
#include <wx/aui/aui.h>
#include "T100Common.h"

namespace T100IDE{

class T100IDEViewManager
{
    public:
        T100IDEViewManager();
        virtual ~T100IDEViewManager();

        wxAuiManager*           getAuiManager();
        wxDocManager*           getDocManager();

    protected:
        T100VOID                create();
        T100VOID                destroy();

        T100VOID                init();

    private:
        wxAuiManager*           m_aui           = T100NULL;
        wxDocManager*           m_doc           = T100NULL;

};

}

#endif // T100IDEVIEWMANAGER_H
