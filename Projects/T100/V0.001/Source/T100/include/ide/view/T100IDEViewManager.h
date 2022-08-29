#ifndef T100IDEVIEWMANAGER_H
#define T100IDEVIEWMANAGER_H

#include <wx/aui/aui.h>
#include <wx/docmdi.h>
#include "T100Common.h"
#include "T100EditorData.h"
#include "T100IDEFrameText.h"
class T100IDEView;


class T100IDEViewManager
{
    public:
        T100IDEViewManager(T100IDEView*);
        virtual ~T100IDEViewManager();

        wxDocManager*           getDocManager();
        wxAuiManager*           getAuiManager();

        T100BOOL                create_child(T100EditorData*);
        T100IDEFrameText*       getCurrent();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100IDEView*            m_view          = T100NULL;

        wxDocManager*           m_doc           = T100NULL;
        wxAuiManager*           m_aui           = T100NULL;

};

#endif // T100IDEVIEWMANAGER_H
