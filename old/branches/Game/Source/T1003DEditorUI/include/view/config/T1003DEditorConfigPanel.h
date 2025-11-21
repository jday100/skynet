#ifndef T1003DEDITORCONFIGPANEL_H
#define T1003DEDITORCONFIGPANEL_H

#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/stattext.h>
#include "T100Common.h"

class T1003DEditorConfigPanel : public wxPanel
{
    public:
        T1003DEditorConfigPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorConfigPanel();

    protected:
        wxButton*           m_buttonSave                = T100NULL;
        wxChoice*           m_coordinateChoice          = T100NULL;
		wxStaticText*       m_coordinateStaticText      = T100NULL;
		wxChoice*           m_projectionChoice          = T100NULL;
		wxStaticText*       m_projectionStaticText      = T100NULL;

        static const long ID_BUTTON_SAVE;
        static const long ID_STATICTEXT_COORDINATE;
		static const long ID_CHOICE_COORDINATE;
		static const long ID_STATICTEXT_PROJECTION;
		static const long ID_CHOICE_PROJECTION;

		void OnChoiceCoordinateSelect(wxCommandEvent& event);
		void OnChoiceProjectionSelect(wxCommandEvent& event);
        void OnButtonSaveClick(wxCommandEvent& event);

    private:
        T100VOID                            init();
        T100VOID                            uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORCONFIGPANEL_H
