#ifndef T1003DEDITORVIEW_H
#define T1003DEDITORVIEW_H

#include <wx/aui/aui.h>
#include <wx/panel.h>
#include "T100Common.h"

class T1003DEditorView
{
    public:
        T1003DEditorView();
        virtual ~T1003DEditorView();

    protected:
        wxAuiManager*           m_manager           = T100NULL;
        wxPanel*                m_main              = T100NULL;

    private:
        T100VOID                create();
        T100VOID                destroy();
};

#endif // T1003DEDITORVIEW_H
