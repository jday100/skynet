#ifndef T1003DEDITORSETTINGSPARAMETERREFERENCEPANEL_H
#define T1003DEDITORSETTINGSPARAMETERREFERENCEPANEL_H

#include <atomic>
#include <vector>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include "T100Common.h"

class T1003DEditorSettingsParameterReferencePanel : public wxPanel
{
    public:
        T1003DEditorSettingsParameterReferencePanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorSettingsParameterReferencePanel();

    protected:
        wxPropertyGrid*                     m_gridPtr           = T100NULL;
        wxButton*                           m_buttonSave        = T100NULL;
        wxButton*                           m_buttonAppend      = T100NULL;
        wxButton*                           m_buttonRemove      = T100NULL;

    protected:
        static const long ID_BUTTON_SAVE;
        static const long ID_BUTTON_APPEND;
        static const long ID_BUTTON_REMOVE;

        void OnButtonAppendClick(wxCommandEvent& event);
        void OnButtonRemoveClick(wxCommandEvent& event);
        void OnButtonSaveClick(wxCommandEvent& event);

    private:
        std::atomic_int                     m_count;
        T100STRING                          m_name          = "./config/parameterreference.json";

        T100VOID                            init();
        T100VOID                            uninit();

        T100VOID                            Load();
        T100VOID                            Save();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORSETTINGSPARAMETERREFERENCEPANEL_H
