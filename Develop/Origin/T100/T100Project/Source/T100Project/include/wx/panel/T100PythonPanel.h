#ifndef T100PYTHONPANEL_H
#define T100PYTHONPANEL_H

#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include "T100Common.h"

class T100PythonPanel : public wxPanel
{
    public:
        T100PythonPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T100PythonPanel();

        const T100WSTRING       GetPath();

    protected:
        static const long ID_PYTHON_FILE_TITLE;
        static const long ID_PYTHON_FILE_PICKER;

    protected:
        wxStaticText*           m_pythonTitle       = T100NULL;
        wxFilePickerCtrl*       m_pythonFile        = T100NULL;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100PYTHONPANEL_H
