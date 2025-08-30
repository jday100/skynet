#ifndef T100PROJECTVIEWSETUPEDITORDIALOG_H
#define T100PROJECTVIEWSETUPEDITORDIALOG_H

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/listbox.h>
#include <wx/dialog.h>
#include "T100Common.h"

class T100ProjectViewSetupEditorDialog : public wxDialog
{
    public:
        T100ProjectViewSetupEditorDialog(wxWindow *parent, wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T100ProjectViewSetupEditorDialog();

    protected:
        static const long ID_FONT_STATIC_TEXT;
        static const long ID_FONT_LIST_BOX;

        wxStaticText*       m_fontTitle;
        wxListBox*          m_font;

        T100VOID            OnApply(wxCommandEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTVIEWSETUPEDITORDIALOG_H
