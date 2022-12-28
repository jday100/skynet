#ifndef T100EDITORVIEW_H
#define T100EDITORVIEW_H

#include <wx/window.h>
#include "T100Common.h"
#include "T100EditCtrl.h"

namespace T100Editor{
class T100EditorFrame;


class T100EditorView
{
    public:
        T100EditorView();
        virtual ~T100EditorView();

        T100VOID                setParent(wxWindow*);

        T100BOOL                create();

        T100VOID                show();

        T100WxWidgets::T100EditCtrl*        getEditCtrl();

    protected:
        T100VOID                destroy();

    private:
        wxWindow*               m_parent            = T100NULL;
        T100EditorFrame*        m_frame             = T100NULL;
        T100WxWidgets::T100EditCtrl*        m_edit          = T100NULL;

};

}

#endif // T100EDITORVIEW_H
