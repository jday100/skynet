#ifndef T100EDITORSTATE_H
#define T100EDITORSTATE_H

#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/docmdi.h>
#include "T100State.h"

namespace T100Editor{

class T100EditorState : public T100Component::T100State
{
    public:
        T100EditorState();
        virtual ~T100EditorState();

        virtual T100BOOL            create(wxDocMDIParentFrame* = T100NULL, wxFrame* = T100NULL) = 0;

        virtual T100BOOL            create_menu(wxMenuBar* = T100NULL) = 0;

    protected:

    private:
};

}

#endif // T100EDITORSTATE_H
