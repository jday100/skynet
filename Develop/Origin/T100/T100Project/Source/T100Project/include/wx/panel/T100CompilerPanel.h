#ifndef T100COMPILERPANEL_H
#define T100COMPILERPANEL_H

#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include "T100Common.h"

class T100CompilerPanel : public wxPanel
{
    public:
        T100CompilerPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T100CompilerPanel();

        const T100WSTRING       GetPath();

    protected:
        static const long ID_COMPILER_PATH_TITLE;
        static const long ID_COMPILER_PATH_PICKER;

    protected:
        wxStaticText*           m_compilerTitle         = T100NULL;
        wxDirPickerCtrl*        m_compilerPath          = T100NULL;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100COMPILERPANEL_H
